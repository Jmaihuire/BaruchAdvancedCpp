#include <iostream>
#include <string>
#include <thread>

#include "Command.h"
#include "SynchronizedQueue.h"

// Class that produces objects and puts them in a queue -
// pulled from lecture slide material & changed to stl 

class Producer {
 private:
  int m_id;                             // The id of the producer
  SynchronizedQueue<Command>* m_queue;  // The queue to use
  int numChairs_;                       // chairs in barber shop
 public:
  // Constructor with id and the queue to use
  Producer(int id, SynchronizedQueue<Command>* queue) {
    m_id = id;
    m_queue = queue;
  }
  // The thread function fills the queue with data
  void operator()(
      std::atomic<bool>& interrupt)  // include interrupt as input so we can
                                     // break function on user command
  {
    double data = 0;
    while (true) {
      if (interrupt.load()) {
        break;  // break on user input
      }
      // Produce a Command and store in the queue
      data++;  // increase the priority every new command that is pushed
      Command cmd(Command::alg1, data);  // make command
      m_queue->Enqueue(cmd);             // add command to queue if open chairs

      // Sleep one second
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
};
