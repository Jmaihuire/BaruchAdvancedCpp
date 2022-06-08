// Level5_Section5.9_Exercise6.cpp
// Fiona Ross 
// Layered Communication with Signals 
#include <iostream>
#include <boost/signals2/signal.hpp>
#include <boost/functional.hpp>

using signal = boost::signals2::signal<void(double& d)> ;

// Part A -Slots:
// exterior slot:
// requirement was to just initialize data 
void inputData(double& d) { std::cout << "Input data: " << d << std::endl; }

// hardware slot
// requirement was:  data is checked to be in the range [2,4]; if not in the range it is set to the value 3.
void checkData(double& d) {
  if (d < 2 || d > 4) {
    d = 3;
  };
}

// data slot
// requirement was : the data is modified by an algorithm
void modify(double& d) { d += 2; }

// communication layer
// requirement was: data is formatted and printed 
void print(double& d) { std::cout << "Comm layer output: " << d << std::endl; }



int main()
{ 
  // Part A: Creating layers 
  // Exterior layer
  signal signalExterior;
  // Hardware Layer
  signal signalHardware;
  // Data Layer
  signal signalData;
  // Communication Layer
  signal signalComm;

  // connect slots & layers 
  signalExterior.connect(&inputData);
  signalHardware.connect(&checkData);
  signalData.connect(&modify);
  signalComm.connect(&print);

  // connect slots to eachother .. used 1D for help 
  signalExterior.connect(signalHardware);
  signalHardware.connect(signalData);
  signalHardware.connect(signalComm);

  // Part C: 
  // Test Code with range that works 
  double t1 = 3;  // in range
  signalExterior(t1); // exterior is connected to all other layers

  // Test code with range that doesnt work 
  double t2 = 6;       // in range
  signalExterior(t2);  // exterior is connected to all other layers

  // Seems to return the same output even when out of range....was not expected 

}

