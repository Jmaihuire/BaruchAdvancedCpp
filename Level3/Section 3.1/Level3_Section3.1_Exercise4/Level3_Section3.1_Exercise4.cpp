// Level3_Section3.1_Exercise4.cpp : 

// Synchronizing Queues 
// Implimenting synchronizing (thread-safe) FIFO queue in C++11. 

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include <thread>
#include <chrono>
#include <boost/thread.hpp>

template <typename T>
class QueueClass
{
	private:
        std::queue<T> m_queue;       // stl queue to store data 
        std::mutex m_mutex;            // The mutex to synchronise on
        std::condition_variable m_cond;  // The condition to wait for  
	public: 
        // Adding elements to the queue 
        void add_queue(const T data) {
          // lock queue
          // Part B: including locking mechanism for functions 
          std::unique_lock<std::mutex> lock1(m_mutex);

          // add data to queue
          m_queue.push(data);
              // notify consumer data is ready

          // Part C: Add notification mechanisms to allow thread notification (use condition variables for notification).
          m_cond.notify_one();
        }

        // this allows the user to get data from the queue. 
        // this function will wait for data if not available
        T get_queue() {
          // acquire lock on the queue
          // Part B: including locking mechanism for functions 
          std::unique_lock<std::mutex> lock1(m_mutex);

          // when there is no data, wait until someone fills it
          // lock is automatically realease in the wait and active
          // again after the wait
          while (m_queue.size() == 0) m_cond.wait(lock1);

          // Retrieve data from the queue
          T result = m_queue.front();
          m_queue.pop();
          return result;
        }  // Lock will be released here 
		
           // print the elements of queue
         void print_queue(std::queue<T> m_queue) {
          while (!m_queue.empty()) {
             std::cout << m_queue.front() << " ";
            m_queue.pop();
           }
           std::cout << std::endl;
         }

};

// Class that produces objects and puts them in queue 
class Producer {
 private:
     int m_id;      // the id of the producer 
     QueueClass<std::string>* m_queue; // the queue to use 

public:

    // Constructur with id and the queue to use 
    Producer (int id, QueueClass<std::string>* queue) {
        m_id = id; 
        m_queue = queue;
     }

    void operator()() 
    { 
    int data = 0; 
    while (true) {
      // produce a string and store in the queue 
        std::string str = "Producer: " + std::to_string(m_id) +
                        "data: " + std::to_string(data++);
      m_queue->add_queue(str);
        std::cout << str << std::endl;

        // Sleep one second 
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    }

};

class Consumer {
    private:
  int m_id;         // the id of the consumer 
  QueueClass<std::string>* m_queue; // the queue to use 

        public: 
           // Constructor with id and the queue to use 
            Consumer(int id, QueueClass<std::string>* queue) {
                m_id = id; 
                m_queue = queue; 
            }
            void operator()()
            {
                while (true)
                {
                    // get the data from the queue and print it
                  std::cout << "Consumer " << std::to_string(m_id).c_str();
                    std::cout << "consumed: (" << m_queue->get_queue().c_str()
                              << ")" << std::endl;

                    // make sure we can be interupted 
                    boost::this_thread::interruption_point();
            }
            }
 
};
int main() {
  // Part A: Implementing template class (template parameters) for queuing and
  // dequeing The number of producers / consumers
  int numPrdcr = 3;
  int numConsr = 3;

  // the shared queue
  QueueClass<std::string> queue;
  // Part D: Testing by reating multiple producers & consumers 
  
  // Create producers
  boost::thread_group producers;
  for (int i = 0; i < numPrdcr; i++) {
    Producer p(i, &queue);
    producers.create_thread(p);
  }

  // Create consumers
  boost::thread_group consumers;
  for (int i = 0; i < numConsr; i++) {
    Consumer c(i, &queue);
    consumers.create_thread(c);
  }

  // Wait for enter
  getchar();

  // interupt the threads and stop them
  producers.interrupt_all();
  producers.join_all();

  consumers.interrupt_all(); 
  consumers.join_all();

}
