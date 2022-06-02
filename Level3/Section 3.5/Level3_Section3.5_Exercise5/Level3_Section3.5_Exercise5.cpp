// Level3_Section3.5_Exercise5.cpp 
// Fiona Ross 
// Producer- Consumer Pattern 

#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include "SynchronizedQueue.h"
#include "Producer.cpp"
#include "Consumer.cpp"
#include <atomic>
#include "Command.h"

std::atomic<bool> interrupt = false;

int main() {
  // The number of producers/consumers
  const int nrProducers = 1,
            nrConsumers = 3;  // when only one consumer is used, the consumer
                              // cannot keep up with the producer and therefore
                              // skips over lower priority commands
  // The shared queue
  SynchronizedQueue<Command> queue;
  
  // PART A: Create thread group of producers
  std::thread producers[nrProducers];  // array of producers/ "customers"
  for (int i = 0; i < nrProducers; i++) {
    Producer p(i, &queue);
    auto ptemp = std::thread(p, std::ref(interrupt));
    producers[i] = std::move(ptemp);
  }
  // PART B: Create thread group of consumers
  std::thread consumers[nrConsumers];  // array of consumers/ "barber"
  for (int i = 0; i < nrConsumers; i++) {
    Consumer c(i, &queue);
    auto ctemp = std::thread(c, std::ref(interrupt));
    consumers[i] = std::move(ctemp);
  }
  // PART C: Start of application 
  getchar();
  interrupt = true;
  // Interrupt the threads and stop them...basically telling the consumers 
  // there is no more customers 
  for (auto& p : producers) {
    p.join();
  }
  for (auto& c : consumers) {
    c.join();
  }
}
