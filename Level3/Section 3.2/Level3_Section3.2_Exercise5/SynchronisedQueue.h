#pragma once
#include <mutex>
#include <queue>
#include <condition_variable>

// Synchronized Queue class taken from lecture slides 
template <typename T>
class SynchronisedQueue {

	private: 
		std::queue<T> m_queue;  // the stl queue to store data 
		std::mutex m_mutex;		// the mutex to synchronise on 
        std::condition_variable m_cond; // the condition to wait for 

	public: 
		// add data to the queue and notify others 
	void Enqueue(const T& data) {
	
		// Aquire lock on the queue 
		std::unique_lock<std::mutex> lock(m_mutex);

		// Add the data to the queue 
		m_queue.push(data);

		// Notify others that the data is ready
        m_cond.notify_one();

	} // lock released 

	// Get the data from the queue and wait for data if not available 
	T Dequeue() {
          // Acquire lock on the queue
          std::unique_lock<std::mutex> lock(m_mutex);

          // When there is no data, wait until someone fills it
          // lock is automatically released in the wait and active
          // again after the wait
          while (m_queue.size() == 0) m_cond.wait(lock);

          // Retrieve the data from the queue
          T result = m_queue.front();
          m_queue.pop();
          return result;
        
	} // lock is released 

};
