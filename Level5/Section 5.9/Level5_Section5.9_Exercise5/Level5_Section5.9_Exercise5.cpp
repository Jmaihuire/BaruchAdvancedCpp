// Level5_Section5.9_Exercise5.cpp 
// Fiona Ross 
// GOF Pattern 

#include <iostream>
#include <boost/signals2/signal.hpp>
#include <boost/functional.hpp>
#include <list>


// Using boost Function library
typedef boost::function<void(double)> FunctionType;

class Subject {
  // The notifier (Observable)in Publisher-Subscriber pattern
 private:
  boost::signals2::signal<void(double)> attentionList;

 public:
  // this isn't working so made it a type 
  // Subject() { attentionList = boost::signals2::signal<void(double)>(); }
  Subject() { attentionList = boost::signals2::signal<void(double)>(); }
  void AddObserver(const FunctionType & ft) { // attentionList.push_back(ft); 
   // not using list so push_back is changed to connect 
      attentionList.connect(ft);
  }

  void ChangeEvent(double x) {
    /*for (auto it = attentionList.begin(); it != attentionList.end(); ++it) {
      (*it)(x);
    }*/
    // no longer have to loop through list but just call signal 
    attentionList(x);
  }
};

//Part B: Create Slots
void CPrint(double x) { std::cout << "C function: " << x << std::endl; }

struct Print{void operator()(double x){std::cout << "I am a printer " << x << std::endl;}};

class MathsWhiz {
 public:
  double data;
  MathsWhiz(double x) { data = x; }
  void operator()(double x) {
    std::cout << "Product = " << data * x << std::endl;
  }
};


int main()
{
  // Part C: 
  // Create the notifier
  Subject mySubject;

  // Create the attention list
  Print myPrint;
  MathsWhiz myMaths(10.0);
  // Database myDatabase; // not sure what this is referring to...had to coment out

  mySubject.AddObserver(myPrint);
  mySubject.AddObserver(myMaths);
  // mySubject.AddObserver(myDatabase); // Don't understand the database...had to comment out
  mySubject.AddObserver(&CPrint);

  // Trigger the event
  std::cout << "Give the value: ";
  double val;
  std::cin >> val;
  mySubject.ChangeEvent(val);
}
