#include "StopWatch.h"
StopWatch::StopWatch() {
};

void StopWatch::StartStopWatch() {
	//update start time with current time
	start_ = std::chrono::system_clock::now();
};
void StopWatch::StopStopWatch() {
	//update end time with current time
	end_ = std::chrono::system_clock::now();
};

void StopWatch::Reset() {
	//resetting stop watch makes start and end the current time. GetTime will therefore output zero after a stopwatch reset.
	start_ = std::chrono::system_clock::now();
	end_ = std::chrono::system_clock::now();
};

double StopWatch::GetTime() const {
	std::chrono::duration<double> elapsed_seconds = end_ - start_;
	return elapsed_seconds.count();
};

StopWatch::StopWatch(const StopWatch& sw) {
	//copy constructor
	start_ = sw.start_;
	end_ = sw.end_;
};
StopWatch& StopWatch::operator=(const StopWatch& sw) {
	//assignment constructor
	StopWatch sw_out(sw);
	return sw_out;
};