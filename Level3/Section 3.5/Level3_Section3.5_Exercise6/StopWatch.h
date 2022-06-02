#pragma once
#include <chrono>
class StopWatch {
 public:
  StopWatch(){};  // default 

  void StartStopWatch(){
    // update start time with current time
    start = std::chrono::system_clock::now();
  };
  void StopStopWatch(){ stop = std::chrono::system_clock::now(); };
  void Reset() {  
    // resetting just means taking new start and stop at the current time.
    start= std::chrono::system_clock::now();
    stop = std::chrono::system_clock::now();
  };

 double GetTime() const {
     // this will just take stop - start 
     std::chrono::duration<double> elapsed_time = stop - start;
     return elapsed_time.count();

  };

 private:
  StopWatch(const StopWatch &);
  StopWatch &operator=(const StopWatch &);
  std::chrono::time_point<std::chrono::system_clock> start;
  std::chrono::time_point<std::chrono::system_clock> stop;
};