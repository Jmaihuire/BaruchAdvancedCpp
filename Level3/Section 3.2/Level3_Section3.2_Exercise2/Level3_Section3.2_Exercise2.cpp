// Level3_Section3.2_Exercise2.cpp
// Fiona Ross - 04-10-2022

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>  // std::this_thread::sleep_for
#include <vector>

std::mutex m_mutex;

struct X {
  double val;

  X() : val(0.0) {}
  void operator()() { std::cout << "An X " << val << std::endl; }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

void Modify(PointerType& p, double newVal) {
  // Wait a while, long enough to trigger the race
  // Part A:

  // get random number:
  std::random_device rd;
  std::uniform_int_distribution<int> d(0, 1000);
  int random_time = d(rd);  // random time between 0 and 1000 milliseconds

  // make this thread sleep for the random time:
  std::this_thread::sleep_for(std::chrono::milliseconds(random_time));

  p->val = newVal;
  // use print mutex to ensure print message is fully printed:
  m_mutex.lock();
  std::cout << "value is: " << p->val << std::endl;
  m_mutex.unlock();
}

int main() {
  const unsigned int numThreads = 100;
  std::vector<std::thread> v{numThreads};
  int input_val = 0;
  for (auto& t : v) {
    // create instance of pointer type
    PointerType pTemp(new X);
    // assign pointer type to thread & run modify
    std::thread t_thread(Modify, std::ref(pTemp), input_val);

    // move thread to array
    t = std::move(t_thread);
    input_val++;
  }

  for (auto& t : v) {
    t.join();  // joining the threads
  }

  // Part C:
  // From the output from the consel it was clear that the modify() does not get
  // assigned to the p value. This is the race condition. It creates this
  // inconsistency when multiple threads try to access the shared memory.
  // It creates bad results.
}
