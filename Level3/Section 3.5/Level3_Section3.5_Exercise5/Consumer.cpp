#include <iostream>
#include <string>

#include "Command.h"
#include "SynchronizedQueue.h"

// Class that consumes objects from a queue 
// Taken from lecture slides but changed to std 
class Consumer {
 private:
  int m_id;                             // The id of the consumer
  SynchronizedQueue<Command>* m_queue;  // The queue to use
 public:
  // Constructor with id and the queue to use
  Consumer(int id, SynchronizedQueue<Command>* queue) {
    m_id = id;
    m_queue = queue;
  }
  // The thread function reads data from the queue
  void operator()(std::atomic<bool>& interrupt) {
    while (true) {
      if (interrupt.load()) {
        break;  // break on user input
      } else {
        // Get the data from the queue and print it
        Command cmd = m_queue->Dequeue();
        std::cout << "Consumer # " << m_id
                  << " executing cmd with priority: " << cmd.priority()
                  << " and value "
                  << std::endl;  // print consumer number and priority
        cmd.Execute(4);              // execute the command
        // Make sure we can be interrupted
        std::this_thread::yield();
      }
    }
  }
};
