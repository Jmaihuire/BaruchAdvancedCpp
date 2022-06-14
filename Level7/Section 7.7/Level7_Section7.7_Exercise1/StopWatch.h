#pragma once
#include <chrono>

class StopWatch
{
public:
    StopWatch();

    void StartStopWatch();
    void StopStopWatch();
    void Reset();

    double GetTime() const;
private:
    std::chrono::time_point<std::chrono::system_clock> start_; 
    std::chrono::time_point<std::chrono::system_clock> end_;

    StopWatch(const StopWatch& sw);
    StopWatch& operator=(const StopWatch& sw);
};

