#pragma once
#include "SynchronisedQueue.h"
#include <iostream>
#include <string>
#include <ctime>
// Class that produces and puts objets in a queue 
class Producer {
 private: 
	 int m_id; // the ID of the producer 
	 SynchronisedQueue<std::string>* m_queue; // the queue to use 

	 public:
		 //Constructor with ID and the queue to use
          Producer(int id, SynchronisedQueue<std::string>* queue) {
            m_id = id;
            m_queue = queue;
          }

		  // The thread function fills the queue with data 
		  void operator()() { int data = 0; 
		  while (true) {
             // Produce a string and store in the queue 
			  std::string str = "Producer: " + std::to_string(m_id) +
                               "data: " + std::to_string(data++);
             m_queue->Enqueue(str);
             std::cout << str << std::endl; 

			 // Sleep one second 
			 std::this_thread::sleep_for(std::chrono::seconds(1));
		  }
		  }
};
