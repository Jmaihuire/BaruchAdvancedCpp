// Level3_Section3.2_Exercise5.cpp :
// Fiona Ross - 04-16-2022
#include <iostream>
#include <mutex>
#include <thread>
#include "SynchronisedQueue.h"
#include "Consumer.h"
#include "Producer.h"

std::atomic<bool> barberReady = false;
std::atomic<bool> customerReady = false;

std::mutex m;  // Ensures no race condition

// Synchronization between master and worker
std::condition_variable cv;

// Consumer code 
void Customer() {
    // wait until customer enters 
    // False state: wait until master sends data
  std::unique_lock<std::mutex> myLock(m);
  cv.wait(myLock, [] { return customerReady.load(); }); //including load() for
  // atomic boolean
  //cv.wait(myLock, [] { return customerReady.test_and_set(); });

  // Now in True State
  std::cout << "Customer is ready \n";

  // Notify master
  barberReady = true;
  //masterReady.test_and_set();

  // Postprocess
  myLock.unlock();
  cv.notify_one();
  std::cout << "Worker is exited...\n";
}

// Producer Code 
void Barber() {

    // hang around and wait for the customer to enter
   
  while (!customerReady.load()) 
      {
      std::cout.put('.').flush();

      // go back to sleep
      std::this_thread::sleep_for(std::chrono::seconds(10));

  }

  std::cout << "Barber is sleeping while waiting for next customer"
            << std::endl;
  // can output data value here 
    // std::cout << "Value of data is: " << data << std::endl; 

}

int main() {
  // The number of producers / consumers
  int nrProducers = 10;  // ten clients all coming in every 10 seconds
  int nrConsumers = 1;   // one Barber

  // The shared queue
  SynchronisedQueue<std::string> queue;

  // Create producers
  std::vector<std::thread> grp;
  for (int i = 0; i < nrProducers; i++) {
    

  }
  
  }

