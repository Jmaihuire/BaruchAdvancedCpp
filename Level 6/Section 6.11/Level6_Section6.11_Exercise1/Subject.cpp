#include "Subject.h"
#include "Observer.h"
#include <memory>


void Subject::Attach(Observer* observer) {
	observers.push_back(observer);
};
void Subject::Detach(Observer* observer) {
	observers.remove(observer);
};

//Notifying the observers
void Subject::Notify() {
	std::list<Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++) {
		(*it)->Update(this);
	}
};