#pragma once
#include "SynchronisedQueue.h"
#include <string>
#include <queue>
#include <iostream>
class Consumer {
 private:
  int m_id;		// the id of the consumer 
  SynchronisedQueue<std::string>* m_queue; // the queue to use 

  public: 
	  // Constructor with id and the queue to use 
	  Consumer(int id, SynchronisedQueue<std::string>* queue) {

		  m_id = id;
          m_queue = queue; 
	  }

	  void operator()() { 
		  while (true) {
            // Get the data from the queue and print it 
			  std::cout << "Consumer " << std::to_string(m_id).c_str();
		  }
	  }
};