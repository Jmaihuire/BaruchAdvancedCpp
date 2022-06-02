// Level3_Section3.4_Exercise5.cpp :

#include <iostream>
#include <array>
#include <numeric>
#include <chrono>
#include <ctime>
#include <vector>
#include <future>
#include <omp.h>
#include <iterator>
#include <functional>
#include <execution>


// Part A: Using Accumulate with Time 
int callAccumulateT(std::vector<int> inputArray) {
  // using accumulate to get sum
  const auto start_time =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

  int sumOut = std::accumulate(std::begin(inputArray), std::end(inputArray), 0);
  std::cout << "Call Accumulate Sum Out is: " << sumOut << std::endl; 
  // Computing program duration in milliseconds
  const auto end_time = std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();

  std::cout << "Elapsed time in milliseconds is: "
            << std::chrono::microseconds(end_time - start_time).count()
            << " ms\n";

  return sumOut;
}

// Accumulate without Time 
int callAccumulate(std::vector<int> inputArray) {
  // using accumulate to get sum

  int sumOut = std::accumulate(std::begin(inputArray), std::end(inputArray), 0);
  std::cout << "Call Accumulate Sum Out is: " << sumOut << std::endl;
 
  return sumOut;
}

// Part B: Asynch 
int rightAsync(std::vector<int> inputArray, int halfArr ) {
  const auto start_time =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

    // creating a packaged task for the right hand of the array 
    std::packaged_task<int(std::vector<int>)> task(callAccumulate);  // input function here
  
    std::future<int> futAsync = task.get_future(); // getting future of task 
    task(inputArray); // running task 

    int halfSum_tmp = std::accumulate(inputArray.begin() + halfArr, inputArray.end(), 0);
  
    int halfSum_out = futAsync.get() + halfSum_tmp; 
    
    // Output the sum 
    std::cout << "Output of Asynch is: " << halfSum_out << std::endl;
    
    // calculate runtime 
     const auto end_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count();

    std::cout << "Elapsed time in milliseconds is: "
              << std::chrono::microseconds(end_time - start_time).count()
              << " ms\n";

    return halfSum_out; 
}

// Part B: Recursive 
int leftRecursive(std::vector<int> inputArray) {
  // check if array has more than 1 integer 
  if (inputArray.size() <= 1000) {
    return std::accumulate(inputArray.begin(), inputArray.end(), 0);
  }
  else {
    const auto start_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count();

    int halfArr = inputArray.size() / 2;
    std::vector<int> halfArr_a(inputArray.begin(), inputArray.begin()+halfArr); 
    std::vector<int> halfArr_b(inputArray.begin() + halfArr, inputArray.end());
   
    // calculate runtime 
         const auto end_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count();

    std::cout << "Elapsed time in milliseconds is: "
              << std::chrono::microseconds(end_time - start_time).count()
              << " ms\n";

    return callAccumulate(halfArr_a) + callAccumulate(halfArr_b);
  }

}

 // Part D: OpenMP
int MPSum(std::vector<int> inputArray) {

    const auto start_time =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

    int sumParallel = 0; //initializing to zero 
    #pragma omp parallel for reduction(+ : sumParallel)

    omp_set_num_threads(2);

  for (int i = 0; i < inputArray.size(); ++i) {
    sumParallel += inputArray[i];
  }

  // calculate runtime
  const auto end_time = std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();

  std::cout << "Elapsed time in milliseconds is: "
            << std::chrono::microseconds(end_time - start_time).count()
            << " ms\n";
  return sumParallel; 
}

 
std::vector<int> createArray(const int sizeVec) {
  std::vector<int> bigArray(sizeVec,1);

  for (int i = 0; i < sizeVec; i++) {
    bigArray[i] = bigArray[i] + i;
  }
  return bigArray;
}

// Part E: Threads instead of Tasks 
void sumThreads(std::vector<int> inputArray, int& sum) {
  // making thread 
  sum = std::accumulate(inputArray.begin(), inputArray.end(), 0);
}

// Part F: Binary Parallel

int parallelSum(std::vector<int> bigArray) {
  int N = bigArray.end() - bigArray.begin();
  if (N > 1000) {
    std::future<int> fut = std::async(
        std::launch::async,
        [&](std::vector<int> vec) {
          return std::accumulate(vec.begin(), vec.end(), 1,
                                 std::multiplies<int>());
        },
        bigArray);
    int res2 = fut.get();
    return res2;
  }

  else 
      {
    std::cout << "Vector is not big enough to go through binary multiplies" <<std::endl; 
    return std::accumulate(std::begin(bigArray), std::end(bigArray), 0);
  }
}

int main()
{ 
    // create big array 
    const int sizeVec = 100000; 
    std::vector<int> bigArray = createArray(sizeVec);

	// int Sum_Accum = callAccumulateT(bigArray);

    // Part B: Parallize code 
        // split index space into two halves 
        // Right half = asynchronous task 
        // Left half = recursive call to the algorithm for appropriate index range 
    
    // getting 1/2 way point 
      int halfWayPt = bigArray.size() / 2; 

      int sumAsynch = rightAsync(bigArray, halfWayPt);
      int sumRecurs = leftRecursive(bigArray);
      int totSumPartB = sumAsynch + sumRecurs; 
      std::cout << "Total Sum Part B: " << totSumPartB
                << std::endl; 


     // Part C: 
     // By just running accumulate on the entire vector you get a time of : 12883 ms
     // By calling recursive on 1/2 vector you get a time of : 9422 ms 
     // By calling asynch on 1/2 vector you get a time of : 1046 ms
     // Processing time improved by 1.5 seconds (this seems like a too large an improvement) 

     // Part D: Comparing using openMP 
     int MPOut = MPSum(bigArray); // runtime of 23904 ms  

     // Part E: Using threads instead of tasks 
     int outT1; 
     std::vector<int> halfBigArray = createArray(halfWayPt);
     std::thread t1(sumThreads, halfBigArray, std::ref(outT1));
     int threadSum = std::accumulate(bigArray.begin() + sizeVec / 2, bigArray.end(),
                         0);  // accumulate the other half of the vector
     t1.join();
     threadSum += threadSum;
     std::cout << "Part E: " << threadSum
               << std::endl;  // test speed of ompSum with openmp

     // Part F: Accumulate with Binary Function 
     int pSum = parallelSum(bigArray);
     std::cout << "pSum is: " << pSum << std::endl; 

     // Part G : Comparing parallel features 
     // ----------SEQUENTIAL ----------------
     std::cout << "start of Part G Sequential:"
               << std::endl; 
     // Start time 
         const auto start_time =
         std::chrono::duration_cast<std::chrono::microseconds>(
             std::chrono::system_clock::now().time_since_epoch())
             .count();
     int sizeVec_ptG = 10000000; 
     // making vector
     std::vector<int> pBigArray(sizeVec_ptG, 1); // initialization
     
     // increasing size of vector 
     for ( int elem : pBigArray) {
       ++elem;
     }
     
     // putting random number to make vector more interesting 
     pBigArray[11] = 350; 
     
     // Note: in C++20 could use std::execution::seq 
     // std::transform 
     std::transform(pBigArray.begin(), pBigArray.end(), pBigArray.begin(),
                    [](int out) -> int { return std::toupper(out); });

     // std::sort 
     std::sort(pBigArray.begin(), pBigArray.end());

     // std::find 
     int valFind = 350; 
     auto resultFind = std::find(pBigArray.begin(), pBigArray.end(),valFind);

     std::cout << "Result of find is: " << valFind << std::endl;

     // calculate runtime
     const auto end_time =
         std::chrono::duration_cast<std::chrono::microseconds>(
             std::chrono::system_clock::now().time_since_epoch())
             .count();

     std::cout << "Elapsed time in milliseconds is: "
               << std::chrono::microseconds(end_time - start_time).count()
               << " ms\n";
     // -------------- PARALLEL --------------
     // start time parallel 
     std::cout << "start of part G Parallel: " << std::endl; 
     const auto start_time_par =
         std::chrono::duration_cast<std::chrono::microseconds>(
             std::chrono::system_clock::now().time_since_epoch())
             .count();
     // std::transform
     std::packaged_task<void(std::vector<int> & v)> ttransf(
         [=](std::vector<int>& v) {
           std::transform(v.begin(), v.end(), v.begin(),
                          [](int val) { return val + 12; });
         });
     auto outParTransf = ttransf.get_future();

     // std::sort 
     std::packaged_task<void(std::vector<int> & v)> tSort(
         [=](std::vector<int>& v) { std::sort(v.begin(), v.end()); });
     auto outParSort = tSort.get_future(); 

     // std::find
     std::packaged_task<std::vector<int>::iterator(std::vector<int> & v)> tFind(
         [=](std::vector<int>& v) {
           return std::find(v.begin(), v.end(), 12);
         });
     auto outParFind = tFind.get_future(); 

     // calculate runtime
     const auto end_time_par =
         std::chrono::duration_cast<std::chrono::microseconds>(
             std::chrono::system_clock::now().time_since_epoch())
             .count();

     std::cout << "Elapsed time in milliseconds is: "
               << std::chrono::microseconds(end_time_par - start_time_par).count()
               << " ms\n";
     // Running parallel dramatically increased speed for vector size 10000 from 37221 ms to 28 ms. Confused why for longer vector parallel processing sped up
     // Running parallel dramatically increased speed for vector size 1000000 from 2569880 ms to 16 ms.
}

