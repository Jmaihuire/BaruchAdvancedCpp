// Level5_Section5.9_Exercise1.cpp 
// Fiona Ross 
// Signals 101

#include <iostream>
#include <boost/signals2/signal.hpp>
#include <functional>

// lambda function slot
auto lambdaSlot = []() { std::cout << "Lambda function slot \n"; };

// define a normal function 
void mySlot() { std::cout << "a first slot "; }

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
  
  // connect slots
  SecondSlot slot1(1);
  signal.connect(boost::ref(lambdaSlot));
  signal.connect(boost::ref(slot1));
  signal.connect(boost::ref(mySlot));

  
  // output of signal 
  signal();
  std::cout << std::endl;

  // Part B: 
  MyStruct mySlot(2);  // create new slot 
  signal.connect(std::bind(&MyStruct::modify, &mySlot, 3)); // connecting  
  signal();    // outputting signal                                                 
  std::cout << std::endl;

  // Part C:
  signal.disconnect(boost::ref(mySlot));
  signal.disconnect(boost::ref(lambdaSlot));
  signal();
  std::cout << std::endl;

  // Part D: 
  // Define potential emitters
  boost::signals2::signal<void()> signalA;
  boost::signals2::signal<void()> signalB;
  boost::signals2::signal<void()> signalC;
  boost::signals2::signal<void()> signalD;

  // Define slots
  auto slotB = []() { std::cout << "Slot B called by B\n " << std::endl; };
  auto slotC = []() { std::cout << "Slot C called by C\n " << std::endl; };
  auto slotD1 = []() { std::cout << "Slot D1 called by D\n " << std::endl; };
  auto slotD2 = []() { std::cout << "Slot D2 called by D\n " << std::endl; };

  // Making Connections 
// Signal B connected to signal A.
  signalB.connect(boost::ref(signalA));
  // Signal C connected to signal B.
  signalC.connect(boost::ref(signalB));
  // Signal D connected to signal C.
  signalD.connect(boost::ref(signalC));
  // Slot B connected to signal B.
  signalB.connect(boost::ref(slotB));
  // Slot C connected to signal C.
  signalC.connect(boost::ref(slotC));
  // Slot D1 connected to signal D.
  signalD.connect(boost::ref(slotD1));
  // Slot D2 connected to signal D.
  signalD.connect(boost::ref(slotD2));
  // output D 
  signalD();

  // disconnecting signal C from B 
  signalC.disconnect(boost::ref(signalB));
  signalD();
  // it seems like this is okay and I don't have to disconnect the terminal signal 


}
