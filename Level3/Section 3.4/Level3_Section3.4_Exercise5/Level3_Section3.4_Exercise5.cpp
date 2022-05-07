// Level3_Section3.4_Exercise5.cpp :

#include <iostream>
#include <array>
#include <numeric>
#include <chrono>
#include <ctime>
#include <vector>

// Part A: Using Accumulate 
void callAccumulate(std::vector<int> inputArray) {
  // using accumulate to get sum
  const auto start_time =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

  std::accumulate(std::begin(inputArray), std::end(inputArray), 0);

  // Computing program duration in milliseconds
  const auto end_time = std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();

  std::cout << "Elapsed time in milliseconds is: "
            << std::chrono::microseconds(end_time - start_time).count()
            << " ms";
}

int main()
{ 
	const int N = 100; // size of array	
	int bigArray[N] = {};  // initializing array 

	for (int i = 0; i < N; i++) {
          bigArray[i] = {i + 10};

	}

	

    // Part B: Parallize code 
        // split index space into two halves 
        // Right half = asynchronous task 
        // Left half = recursive call to the algorithm for appropriate index range 


}

