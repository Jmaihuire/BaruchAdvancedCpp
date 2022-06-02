// Fiona Ross: Exercise 3.4.6

#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>

template <typename T>
T F1(T& input) {
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;

  // generating random amount of time to replicate different function power
  // requirements
  std::default_random_engine dre(412);
  std::uniform_int_distribution<int> delay(0, 1000);
  int output = delay(dre);
  std::this_thread::sleep_for(std::chrono::milliseconds(input));

  std::cout << "Finished F1 \n";
  return output;
}

// This is a quick function, not time intensive
template <typename T>
T F2(T& input) {
  std::cout << "Thread ID: " << std::this_thread::get_id()<< std::endl;
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

int main() {
  // PART A: Create single threaded code for dependency graph
  // Start Processing time
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();

  int a = 5;
  auto b = F1(a);  // call func1
  auto c = F2(a);  // call func2
  auto d = F3(c);  // call func 3 on func 2 output

  auto f = F4(b, d);  // call func 4 on func 3 and func 1 output
  std::cout << "Part A answer: " << std::get<0>(f) << ", " << std::get<1>(f)
            << std::endl;

  // Compute processing time:
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "Finished part A computation at "
            << "elapsed time: " << elapsed_seconds.count() << "s\n";
  // Part A took 0.045 sec

  // Part B: Implement the graph using std::async and std::future.
  // Start Processing time
  std::chrono::time_point<std::chrono::system_clock> start2, end2;
  start2 = std::chrono::system_clock::now();

  // Use std::async and future
  int a2 = 5;
  std::future<int> b2(
      std::async(F1<int>, std::ref(a2)));  // This calls F1 in asynchronous mode
  auto c2 = F2(a2);                        // calls F2
  auto d2 = F3(c2);                        // using F2 output as input to F3

  auto outVal = b2.get();
  auto f2 = F4(outVal, d2);  // call func 4 on func 3 and func 1 output
  std::cout << "Part B answer: " << std::get<0>(f2) << ", " << std::get<1>(f2)
            << std::endl;

  // Compute processing time:
  end2 = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
  std::time_t end_time2 = std::chrono::system_clock::to_time_t(end2);

  std::cout << "Finished part B computation at \n"
            << "elapsed time: " << elapsed_seconds2.count() << "s\n";
  // end processing time computation
  // Part B showed improvement to about 0.026s. This improvement depends
  // on the randomly assigned runtime of F1. If F1 requires long computation
  // time then parallel tasking would definitely speed it up

  // Part C, using promises
  // Start Processing time
  std::chrono::time_point<std::chrono::system_clock> start3, end3;
  start3 = std::chrono::system_clock::now();

  // code:
  // Use std::promise and thread
  int a3 = 5;
  std::promise<int> b3;                          // create promise
  std::future<int> b3_future = b3.get_future();  // get promsie future
  std::thread f1_thread(
      [=](std::promise<int>& b_promise) { b_promise.set_value(F1(a3)); },
      std::ref(b3));  // assign value to promise with func1
  auto c3 = F2(a3);   // call func2
  auto d3 = F3(c3);   // call func 3 on func 2 output
  f1_thread.join();   // join f1 thread after it is done computing b
  auto outVal2 = b3_future.get();  // get output of f1
  auto f3 = F4(outVal2, d3);       // call func 4 on func 3 and func 1 output
  std::cout << "Part C: " << std::get<0>(f3) << ", " << std::get<1>(f3)
            << std::endl;

  // Compute processing time:
  end3 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
  std::time_t end_time3 = std::chrono::system_clock::to_time_t(end3);
  std::cout << "Finished part C computation at \n"
            << "elapsed time: " << elapsed_seconds3.count() << "s\n";
  // Processing time is about the same for promises vs async and future

  // Part D:
  // Start Processing time
  std::chrono::time_point<std::chrono::system_clock> start4, end4;
  start4 = std::chrono::system_clock::now();

  // code:
  // Use packaged tasks
  int a4 = 5;
  std::packaged_task<int(int& a_)> task1(
      F1<int>);  // create packaged task for each function
  std::packaged_task<int(int& a_)> task2(F2<int>);
  std::packaged_task<int(int& c_)> task3(F3<int>);
  std::packaged_task<std::tuple<int, int>(int& b_, int& d_)> task4(F4<int>);
  auto fut1 = task1.get_future();  // get futures for each task
  auto fut2 = task2.get_future();
  auto fut3 = task3.get_future();
  auto fut4 = task4.get_future();
  task1(a4);
  task2(a4);            // call func2
  int c4 = fut2.get();  // get c value
  task3(c4);            // call func 3 on func 2 output
  int d4 = fut3.get();  // get d value
  int b4 = fut1.get();  // get b value
  task4(b4, d4);
  auto f4 = fut4.get();  // get f value from future
  std::cout << "Answer part D: " << std::get<0>(f4) << ", " << std::get<1>(f4)
            << std::endl;

  // Compute processing time:
  end4 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds4 = end4 - start4;
  std::time_t end_time4 = std::chrono::system_clock::to_time_t(end4);
  std::cout << "Finished part D computation at "
            << "elapsed time: " << elapsed_seconds4.count() << "s\n";
  // Processing time is about the same as the other methods
}
