// ----------------------------------
// These are pulled from 3.4.6
//-----------------------------------

#pragma once
#include <iostream>
#include <thread>
#include <future>
#include <random>


template <typename T>
T F1(T& input) {
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;

  // generating random amount of time to replicate different function power
  // requirements
  std::default_random_engine dre(412);
  std::uniform_int_distribution<int> delay(0, 1000);
  int output = delay(dre);
 // std::this_thread::sleep_for(std::chrono::milliseconds(input));
  // had to comment out line since wasn't running 

  std::cout << "Finished F1 \n";
  return output;
}

// This is a quick function, not time intensive
template <typename T>
T F2(T& input) {
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
  std::cout << "Finished F2 \n";
  input += input;
  return input;
}

// this is a time intensive function
template <typename T>
T F3(T& input) {
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
  int hugeNumber = 1000000;
  int dummyVal = 3;
  for (int i = 0; i < hugeNumber; ++i) {
    dummyVal *= i;
  };
  std::cout << "Finished F3 \n";
  return input;
}
template <typename T>
std::tuple<T, T> F4(T& input1, T& input2) {
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
  std::cout << "Finished F4 \n";
  // Just return the two input values as tuple
  auto output = std::make_tuple<T&, T&>(input1, input2);
  return output;
}