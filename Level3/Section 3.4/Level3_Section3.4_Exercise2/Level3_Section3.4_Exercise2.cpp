// Level3_Section3.4_Exercise2.cpp 
// Fiona Ross - 04-25-2022

#include <iostream>
#include <future>
#include <utility>
#include <thread>
#include <ctime>
#include <chrono>

// Trivial Function to show future capabilities
int GetNumber() { return 100; }

// a slow way for checking for prime numbers:
bool is_prime(int x) {
  for (int i = 2; i < x; ++i)
    if (x % i == 0) return false;
  return true;
}

int main()
{
    //Part A: Constructors 
    std::future<int> fut = std::async(GetNumber); // default future 
    std::shared_future<int> sfut0; // default 
    std::shared_future<int> sfut1 = fut.share(); // move normal future to shared future 
    std::shared_future<int> sfut2 = fut.share(); // transfer shared future from shared future...shared future is empty

    // Part B: Checking member functions 
    std::cout << "sfut get test: " << sfut1.get() << std::endl; //.get() member 
    std::cout << "sfut valid test: " << sfut1.valid() << std::endl; //.valid() member
    

    std::cout << "sfut1 wait test, please wait";
    auto start = std::chrono::system_clock::now();
    sfut1.wait(); // .wait member
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "completed in " << elapsed_seconds.count() << "milliseconds";

    std::chrono::steady_clock::duration dur = std::chrono::seconds(4);
    sfut1.wait_until(std::chrono::steady_clock::now() + dur); // .wait_until test

    // Part C: Testing when call get() twice 
    std::cout << "sfut" << sfut1.get() << std::endl;
    std::cout << "sfut * 2" << sfut1.get() * 2 << std::endl;

    // Part D: Infinite Loop 
    
    std::future<bool> pfut = std::async(is_prime, 700020007);
    std::future<bool> pfut1 = std::async(is_prime, 700020007); 

    // do something while waiting for function to set future:
    std::cout << "checking, please wait";
    std::chrono::milliseconds span(100);

    // Using .wait_for 
    while (sfut1.wait_for(span) == std::future_status::timeout) std::cout << '.';

    bool x = pfut.get();

    std::cout << "\n700020007 " << (x ? "is" : "is not") << " prime.\n";

    // using .wait_until 
    auto now = std::chrono::system_clock::now();
    while (sfut1.wait_until(now + dur) == std::future_status::timeout)
      std::cout << '.';

    bool x2 = pfut1.get();

    std::cout << "\n700020007 " << (x ? "is" : "is not") << " prime.\n";

    return 0;
}

