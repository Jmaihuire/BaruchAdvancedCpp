// Level3_Section3.5_Exercise6.cpp 
#include <iostream>
#include "StopWatch.h"
#include <thread>

int main()
{
    // create stop watch instance 
    StopWatch SW;

    // Start the watch
    SW.StartStopWatch();

    // Sleep for period of time 
    std::this_thread::sleep_for(
        std::chrono::seconds(13)); 

    // Stop the watch and return time
    SW.StopStopWatch();

    // time should be close to period of time slept for 
    std::cout << "Time is: " << SW.GetTime() << "\n";
    
    // reset and output reset (should be 0)
    SW.Reset(); 
    std::cout << "Time is: " << SW.GetTime() << "\n";   

    //checked output and results were close to 13 seconds and 0 seconds which checks out
}

