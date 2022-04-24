#pragma once
#pragma once
#include <functional>
#include <iostream>
#include <mutex>

// global variables to keep track of mutex try_lock results:
std::mutex m_mutex; // Part A & B
std::timed_mutex n_mutex; //Part C -> G
std::timed_mutex t_mutex;
int count = 0; 
int count1 = 0;

// PART A
// Found that putting lock_guard in a seperate function caused erorrs in the program as 
// code for Part B-G would continue running. therefore, put lock_guard right into freeFuncA
void increment_countA() {
  // use lock_guard within the for loop so that other thread would not have the
  // access to shared resource until the mutex is unlocked
  for (int i = 0; i < 1000; i++) {
     std::lock_guard<std::mutex> lock(m_mutex); // Part A
  } // lock_guard will release after goes out of scope 
  count1++;
}

// Function Pointer
void Iprint(const std::string& s, int count) {
  // print the string
  for (int i = 0; i < count; ++i) {
    std::thread::id curr_thread_id =
        std::this_thread::get_id();  // thread ID is PART E
    std::cout << "Thread: " << s << "\t ID of: " << curr_thread_id << std::endl;
  };
}


// Part A Free Function Declaration using lock_guard  
void freeFuncA() {
  Iprint("Free function Part A", 3);
  increment_countA();
  std::cout << "\nCounter Value for Part A: " << count1 << std::endl;
  // Lock guard will unlock m_mutex when it goes out of scope
};

// PART B -> G 
//
//void increment_countB() {
//    // Part B: 
//    std::unique_lock<std::timed_mutex> lock1(n_mutex, std::defer_lock);
//    if (lock1.try_lock_for(std::chrono::milliseconds(500))) {
//        count += 1;  // shared resource
//        std::cout << "Count is: " << count << "\n";
//        };
//
//}

// free function declaration
void freeFuncB() {
  // Part B: use unique lock without try_lock
  std::unique_lock<std::mutex> lock1(m_mutex, std::defer_lock);

  try {
    std::unique_lock<std::timed_mutex> lock2;
    lock2.lock();  // no associated mutex - this is what currently throws
    lock1.lock();  // this throws the "Mutex already locked" exception if
                   // you comment out the above two lines.
  } catch (const std::system_error& ec) {  // catch system errors
    if (ec.code() ==
        std::errc::operation_not_permitted) {  // check if associated mutex
      std::cout << "\n No associated mutex Part B" << std::endl;
    };
    if (ec.code() ==
        std::errc::resource_deadlock_would_occur) {  // check if mutex
                                                     // already locked
      std::cout << "\n Mutex is already locked Part B" << std::endl;
    };
  }

  std::cout << "Part C: timed mutex \n" << std::endl; 
  std::unique_lock<std::timed_mutex> lock3(n_mutex);
  try {
    std::unique_lock<std::timed_mutex> lock4;
    lock3.lock();  // no associated mutex - this is what currently throws
    lock4.lock();  // this throws the "Mutex already locked" exception if you
  }

  catch (const std::system_error& e) {
    // error if there is no associated mutex
    if (e.code() == std::errc::operation_not_permitted) {
      std::cout << "no associated mutex Part C\n";
    }

    // error if the mutex is already locked by this unique_lock
    if (e.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "mutex is already locked Part C\n";
    }
  }

  // Part D : tries to lock a mutex using timeout duration
  std::cout << "Part D: timed mutex using try_lock_for\n" << std::endl; 
  try { n_mutex.try_lock_for(std::chrono::milliseconds(500));  // tries to lock mutex and blocks until it
                // locks m_mutex or the duration has elapsed
  }
  catch (const std::system_error& e) {
    // error if there is no associated mutex OR mutex is not locked
    // error if there is no associated mutex
    if (e.code() == std::errc::operation_not_permitted) {
      std::cout << "no associated mutex Part D\n";
    }
    // error if the mutex is already locked by this unique_lock
    if (e.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "mutex is already locked Part D\n";
    }
  }

  // Part E: Apply std::unique_lock::unlock that releases ownership
  std::cout << "Part E: Apply std::unique_lock::unlock that releases ownership\n" << std::endl; 
  try {
    lock3.release();
  }  // lock is released
  catch (const std::system_error& e) {
    // error if there is no associated mutex
    if (e.code() == std::errc::operation_not_permitted) {
      std::cout << "no associated mutex Part E\n";
    }
    // error if the mutex is already locked by this unique_lock
    if (e.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "mutex is already locked Part E\n";
    }

  }

  // Part F: blocks until a specific time
  std::cout
      << "Part F: Blocking Mutext for set amount of time \n"
      << std::endl; 
  try 
  {
    auto current_time = std::chrono::steady_clock::now();
    t_mutex.try_lock_until(current_time + std::chrono::seconds(10));
  } 
  catch (const std::system_error& e) 
  {
    // error if there is no associated mutex
    if (e.code() == std::errc::operation_not_permitted) {
      std::cout << "no associated mutex Part F\n";
    }
    // error if the mutex is already locked by this unique_lock
    if (e.code() == std::errc::resource_deadlock_would_occur) {
      std::cout << "mutex is already locked Part F\n";
    }
  }
  // increment_countB();
  count++;
  std::cout << "Counter for B->G is:" << count << std::endl; 
  Iprint("Free Function Part B->G", 3);

  //Part G: release mutex
  lock3.release();  // this will release associated mutex (m_mutex) without
                    // unlocking it 
   

} 
 

