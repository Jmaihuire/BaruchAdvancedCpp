// Level3_Section3.2_Exercise4.cpp : 
// Fiona Ross - 04-16-2022

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>


// Part A: Necessary Global Data 

// Types and data needed
std::string data;  // Shared data between master and worker
std::mutex m;      // Ensures no race condition

// Synchronization between master and worker
std::condition_variable cv;

// Initial state of worker and master
//std::atomic<bool> workerReady = false;
//std::atomic<bool> masterReady = false;
// Part D: 
std::atomic_flag workerReady = ATOMIC_FLAG_INIT;
std::atomic_flag masterReady = ATOMIC_FLAG_INIT;

// Part B: Creating Worker 
void WorkerThread() { std::cout << "Worker is called ... \n";

// False state: wait until master sends data
std::unique_lock<std::mutex> myLock(m);
//cv.wait(myLock, [] { return workerReady.load(); }); //including load() for atomic boolean
cv.wait(myLock, [] { return workerReady.test_and_set(); });

// Now in True State 
std::cout << "Worker is processing data \n";
data += "addition from worker";

// Notify master 
//masterReady = true;
masterReady.test_and_set();

//Postprocess
myLock.unlock();
cv.notify_one();
std::cout << "Worker is exited...\n";

}

int main() {

	// Part C : Master Code from lecture slides 
	std::cout << "Master is called...\n";
        std::thread worker(WorkerThread);
        data = "Master Data";

		// Transition into True state 
		{ 
			std::lock_guard<std::mutex> myLock(m);
                  //workerReady = true;
                        workerReady.test_and_set();
		}

		std::cout<< "Master has notified worker, wait for response...\n";
        cv.notify_one();
                {
                  std::unique_lock<std::mutex> myLock(m);
                  cv.wait(myLock, [] { return masterReady.test_and_set(); });
                }

				std::cout << "Master back again...\n";
                worker.join();

}

