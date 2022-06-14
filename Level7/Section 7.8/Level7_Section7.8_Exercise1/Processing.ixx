#include "LastExercise.h"
#include <string>
#include <memory>

// Grabbed this from lecture
// the user doesnt directly see any of this information 
// This also performs some sort of functionality (really simple for this example since I ran out of time). 

export module Processing;
struct Impl;

export
class S
{
public:
	S();
	~S();
	std::string do_stuff(double x, double y);
private:
	std::unique_ptr<Impl> impl;
};

module :private;
//Everything beyond this point is not available to importers - example of information hiding
struct Impl {
  std::string processing(double x, double y) {
		LastExercise in_ = { x,y};//fill a LastExercise struct --  just to show we can still use normal headers within modules
		return "Processing has filled the last exercise struct with the values: " + std::to_string(x) + " and " + std::to_string(y);
	}
};

S::S() : impl{ std::make_unique<Impl>() } {}
S::~S() {}
std::string S::processing(double x, double y) { return impl->do_stuff(x,y); }


