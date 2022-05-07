// Level3_Section3.4_Exercise2.cpp :
// Fiona Ross - 04-24-2022

#include <future>
#include <iostream>
#include <random>
#include <thread>

// Code from Lesson Video Tasking in C++
template <typename T>
void GetFutureState(std::future<T>& fut) {
  // Thread function
  T t = fut.get();  // get the result of the future

  // Wait a while
  std::default_random_engine dre(42);  // engine with value 42
  std::uniform_int_distribution<int> delay(
      0, 1000);  // getting random delay btwn 0 - 1000
  std::this_thread::sleep_for(std::chrono::microseconds(delay(dre)));

  std::cout << "Value: " << t << std::endl;
}

int main() {
  std::promise<int> sharedData;  // default promise
  std::promise<int> sharedData2 = std::promise<int>(
      std::allocator_arg,
      std::allocator<int>());  // promise with empty shared state
  std::promise<int> sharedData3 = std::move(sharedData);  // move constructor

  // Part B: Aquire value by future object
  std::promise<double> sharedData4;
  std::future<double> fut = sharedData4.get_future();

  // Part C: Start the thread with a new future
  std::thread myThread(GetFutureState<double>, std::ref(fut));

  // Part D: Fulfill promise; synch by setting the value in shared state
  sharedData4.set_value(3.14);

  myThread.join();
}
