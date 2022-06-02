// Level4_Section4.2_Exercise2.cpp
// Predicate for Ranges 

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int main()
{
  // Example (using is_sorted_until)
  // adding timing functionality 
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();

  std::vector<double> vec8{1.0, 2.0, 3.0, -4.0, 10.0};  // Not ordered
  auto pos = std::is_sorted_until(vec8.begin(), vec8.end());
  std::cout << "checking if bad value: " << *pos << std::endl;

  // outputting time spent doing function 
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Finished computation 1 at "
            << "elapsed time: " << elapsed_seconds.count() << "s\n";


  // Part B #2 : Using is_sorted
  std::chrono::time_point<std::chrono::system_clock> start2, end2;
  start2 = std::chrono::system_clock::now();

  std::cout << "Checking if vcetor is decreasing? " << std::boolalpha
            << std::is_sorted(vec8.begin(), vec8.end(),
                              [](double d, double d2) {
                                if (d > d2) {
                                  return true;
                                }
                                return false;
                              })
            << std::endl; 

   // outputting time spent doing function 
  end2 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
  std::cout << "Finished computation 2 at "
            << "elapsed time: " << elapsed_seconds2.count() << "s\n";
  
  // Part B  # 3 Continued... checking decreasing until 
  std::chrono::time_point<std::chrono::system_clock> start3, end3;
  start3 = std::chrono::system_clock::now();
  std::vector<double> vec9 = {3.0, 2.0, 1.0, -4.0, 10.0};  // decreasing for first three
  
  auto pos3 =
      std::is_sorted_until(vec9.begin(), vec9.end(), [](double d, double d2) {
        if (d > d2) {
          return true; //this checks if decreasing in value or not 
        }
        return false;
      });
  std::cout << "Is decreasing until " << std::distance(vec9.begin(), pos3)
            << std::endl;
  // processing time print

  end3 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
  std::cout << "Finished decreasing_until at "
            << "elapsed time: " << elapsed_seconds3.count() << "s\n";

  // Part B # 4: 
  std::chrono::time_point<std::chrono::system_clock> start4, end4;
  start4 = std::chrono::system_clock::now();
  std::vector<double> vec10 = {3.0, 2.0, 1.0, -4.0,
                              10.0};  // decreasing for first three

  auto pos4 =
      std::is_sorted_until(vec10.begin(), vec10.end(), [](double d, double d2) {
        if (d < d2) {
          return true;  // this checks if decreasing in value or not
        }
        return false;
      });
  std::cout << "Is increasing until " << std::distance(vec10.begin(), pos4)
            << std::endl;
  // processing time print

  end4 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds4 = end4 - start4;
  std::cout << "Finished increaising until at "
            << "elapsed time: " << elapsed_seconds4.count() << "s\n";


}

