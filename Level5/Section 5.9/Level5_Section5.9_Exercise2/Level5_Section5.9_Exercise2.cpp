// Level5_Section5.9_Exercise2.cpp
// Fiona Ross 
// Slot Groups 

#include <iostream>
#include <boost/signals2/signal.hpp>
#include <functional>
// lambda function slot
auto lambdaSlot = []() { std::cout << "Lambda function slot \n"; };

// define a normal function
void mySlot() { std::cout << "a first slot " << std::endl; }

// define a function object
struct SecondSlot {
  int data;

  SecondSlot() { data = 0; }
  SecondSlot(int val) { data = val; }

  void operator()() { std::cout << " a second slot " << data << std::endl; }
};

struct MyStruct {
  double val;
  MyStruct(double v) { val = v; }
  void modify(double newValue) {
    val = newValue;
    std::cout << "A third slot " << val << std::endl;
  }
};

int main()
{
  // Part A: 
  boost::signals2::signal<void()> signal;
  // connect slots with individual groups
  signal.connect(1, boost::ref(lambdaSlot));
  SecondSlot slot1(12);
  signal.connect(2, boost::ref(slot1));
  signal.connect(3, boost::ref(mySlot));

  MyStruct mySlot(4);  // create new slot
  signal.connect(5,std::bind(&MyStruct::modify, &mySlot, 2.0));  // add this slot
  
  // Part B:                                                            
  signal();  //looking at results 
}

