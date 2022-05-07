// Level3_Section3.2_Exercise5.cpp :
// Fiona Ross - 04-16-2022
#include <iostream>
#include <thread>
#include <atomic>
#include "SynchronisedQueue.h"
#include "Producers.h"
#include "Consumers.h"

std::atomic<bool> barberReady = false;

int main() {
  // The number of producers / consumers
  const int nrProducers = 1;  // the producer is producing clients every 10 seconds. Its not the total number of clients. 
  const int nrConsumers = 1;   // one Barber
  const int nrChairs = 4;      // number of chairs available

  // The shared queue
  SynchronisedQueue<std::string> queue;
  std::mutex* consoleMutex(new std::mutex);

  // Create producers
  std::thread grpP[nrProducers];  // array of producers

  for (int i = 0; i < nrProducers; i++) {
    // create instance of Producer
    Producer p(i, &queue, nrChairs);

    // reference wrapper (same as interupt)
    auto p_thread = std::thread(p, std::ref(barberReady));

    // input into vector
    grpP[i] = std::move(p_thread);
  }

  // Create Consumers
  std::thread grpC[nrConsumers];  // array of consumers
  for (int i = 0; i < nrConsumers; i++) {
    // create instance of Consumers
    Consumer c(i, &queue);

    // reference wrapper (same as interupt)
    auto c_thread = std::thread(c, std::ref(barberReady));

    // input into vector
    grpC[i] = std::move(c_thread);
  }

  getchar();           // wait for enter
  barberReady = true;  // Turn atomic bool to true

  // Joining & interupt
  for (auto& p : grpP) {
    p.join();  // joining the threads
  }

  for (auto& c : grpC) {
    c.join();  // joining the threads
  }
}
