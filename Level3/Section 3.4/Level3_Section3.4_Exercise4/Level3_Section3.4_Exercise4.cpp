// Level3_Section3.4_Exercise4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <thread>
#include <future>
#include <queue>

// Thread function
double compute(double x, double y) {
  // Wait a while
  std::default_random_engine dre(42);
  std::uniform_int_distribution<int> delay(0, 1000);
  std::this_thread::sleep_for(std::chrono::milliseconds(delay(dre)));

  return std::cos(x) * std::exp(y);
}
int main()
{
	// Part A: Code to start a task 
	double x = 0.0;
    double y = 2.71;
    // A. 'Direct' tasks
    std::future<double> fut = std::async(compute, x, y);

    // Get the shared data
    double result = fut.get();
    std::cout << "Result: " << result << '\n';

    // Part B: Rewriting of above code to package task / delay execution 
    std::packaged_task<double(double, double)> task(compute); 
    std::future<double> resultPkg = task.get_future();

    std::thread task_td(std::move(task), 0.0, 2.71); 
    task_td.join();

    std::cout << "task_thread: \t" << resultPkg.get() << '\n'; 

    // Part C: Use a packaged tasks, dequeue each task and execute it
    std::queue<std::packaged_task<double(double x, double y)>> packaged_task_queue;
    int numTasks = 10; 
    
    // Queueing 
    for (int i = 0; i<numTasks; i++) {
      std::packaged_task<double(double x, double y)> t(compute);
      packaged_task_queue.push(std::move(t)); // this is adding the package to the queue

    }

    // Dequeuing 
    double taskTmp = 0.0; 
    for (int i = 0; i < numTasks; i++) {
        // making unique tasks 
        taskTmp = taskTmp + i; 
        auto resultQueue = packaged_task_queue.front().get_future(); // creating future for the first task on queue 
        packaged_task_queue.front()(taskTmp, y); // running task 
        
        // Outputting result
        std::cout << "resultQueue is: " << resultQueue.get() << std::endl; 
        
        packaged_task_queue.pop();  // taking task off of queue 

    }

}

