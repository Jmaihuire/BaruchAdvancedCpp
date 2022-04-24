// Alex Moody: Exercise 3.1.3
// Objective: Understanding Safe Lock

#include <iostream>
#include <mutex>
#include <thread>

// Part A:
int counter = 0;
std::mutex mtx;  // include mutex object here so we can lock the print function
std::timed_mutex mtx2;
//
// Iprint interface for all callable object to call
void Iprint(const std::string& s, int count) {
  for (int i = 0; i < count; ++i)
    std::cout << s << std::this_thread::get_id() << std::endl;
};

// free function for part A
void freeFunction() {
  const std::lock_guard<std::mutex> lock(
      mtx);  // Part A: use lock guard to protect counter as thread increments
             // it.
  counter++;
  Iprint("Free function thread: ", 10);
  std::cout << "Counter Value: " << counter << std::endl;
  // Lock guard automatically unlocks mtx when it goes out of scope
};

// free function for parts B thru G
void freeFunction1() {
  std::unique_lock<std::mutex> lock1(
      mtx);  // Part C: use unique lock without try_lock
  try {
    std::unique_lock<std::mutex> lock2;
    lock2.lock();  // no associated mutex - this is what currently throws
    lock1.lock();  // this throws the "Mutex already locked" exception if you
                   // comment out the above two lines.

  } catch (const std::system_error& ec) {  // catch system errors
    if (ec.code() ==
        std::errc::operation_not_permitted) {  // check if associated mutex
      std::cout << "No associated mutex!!!!!!!" << std::endl;
    };
    if (ec.code() ==
        std::errc::resource_deadlock_would_occur) {  // check if mutex already
                                                     // locked
      std::cout << "Mutex is already locked!!!!!!!!" << std::endl;
    };
  }
  // Part D:
  try {
    mtx2.try_lock_for(
        std::chrono::seconds(5));  // tries to lock mutex and blocks until it
                                   // locks mtx2 or the duration has elapsed
  } catch (const std::system_error& ec) {
    if (ec.code() == std::errc::operation_not_permitted) {
      std::cout << "No associated mutex!!!!!" << std::endl;
    };
    if (ec.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "Mutex is already locked!!!!!" << std::endl;
    };
  }
  // Part E:
  try {
    lock1.unlock();  // unlock mutex and release ownership
  } catch (const std::system_error& ec) {
    if (ec.code() == std::errc::operation_not_permitted) {
      std::cout << "No associated mutex!!!!!" << std::endl;
    };
    if (ec.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "Mutex is already locked!!!!!" << std::endl;
    };
  }
  // Part F:
  try {
    auto now = std::chrono::steady_clock::now();  //
    mtx2.try_lock_until(now + std::chrono::seconds(
                                  10));  // try to unlock mutex until 10 seconds
                                         // have elapsed or lock is acquired.
  } catch (const std::system_error& ec) {
    if (ec.code() == std::errc::operation_not_permitted) {
      std::cout << "No associated mutex!!!!!" << std::endl;
    };
    if (ec.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "Mutex is already locked!!!!!" << std::endl;
    };
  }
  counter++;
  Iprint("Free function 1 thread: ", 10);
  std::cout << "Counter Value: " << counter << std::endl;

  // Part G:
  lock1.release();  // release associated mutex without unlocking it

  // Lock guard automatically unlocks mtx when it goes out of scope
};

int main() {
  // Measure processing time:
  // // Exemplar code for system performance
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();

  // Initialize a set of threads using callable objects from prior exercise
  std::thread t1(freeFunction);   // Part A
  std::thread t2(freeFunction);   // Part A
  std::thread t3(freeFunction1);  // Part C

  // Wait for t1 and t2 to finish
  if (t1.joinable()) {
    try {
      t1.join();
    } catch (...) {
    };
  };
  if (t2.joinable()) {
    try {
      t2.join();
    } catch (...) {
    };
  };
  if (t3.joinable()) {
    try {
      t3.join();
    } catch (...) {
    };
  };

  // Compute processing time:
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "Finished computation at "
            << "elapsed time: " << elapsed_seconds.count() << "s\n";

  // Part A processing time: 0.0031 - we see that the global counter is
  // incremented by both threads safely
}
