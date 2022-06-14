#pragma once
#include <functional>
class Point; 

// functionality is the same as point class but now using function wrapper (previously 
// used derived class)

class DistanceStrategy
{
private:
	std::function<double(const Point& p1, const Point& p2)> strat_; //Part A: This is the interface that all distance strategies need to follow
	//Part C:
	// the counter makes us able to store data between calls even though now function wrapper 
		int counter;
public:
	DistanceStrategy(std::function<double(const Point& p1, const Point& p2)> strat){
		counter = 0;
		strat_ = strat;
	}
	
	virtual double Distance(const Point& p1, const Point& p2) {
		counter++;
		return strat_(p1, p2);
	};
	int getCounter() {
		return counter;
	};
};

