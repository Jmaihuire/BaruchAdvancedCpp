#include "Subject.h"
#include <memory>

// changed for 7.6 so that takes function wrappers 
// uses pointers here 
void Subject::Attach(Observer observer) {
	observers.push_back(observer);
};
void Subject::Detach(Observer observer) {
	observers.remove(observer);
};

//Notify observers
void Subject::Notify() {	
	for (auto elem:observers) {
		(*elem)(this); 
	}
};