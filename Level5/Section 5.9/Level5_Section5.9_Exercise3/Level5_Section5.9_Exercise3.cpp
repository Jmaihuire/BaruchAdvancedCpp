// Level5_Section5.9_Exercise3.cpp 
// Fiona Ross 
// Combining Returned Values from Slots 

#include <iostream>
#include <boost/signals2/signal.hpp>

// Part A: 
struct BootstrapCheck {
  // Iterate in slots and return first 'false'
  // value; otherwise, 'true'
  typedef bool result_type;
  template <typename InputIterator>
  bool operator()(InputIterator first, InputIterator last) const {
    while (first != last) {
      if (!*first) return false;
      ++first;
    }
    return true;
  }
};

boost::signals2::signal<bool(), BootstrapCheck> sig;

// Part B: three signals but second one returns false, others return true 
bool firstSlot() {
  std::cout << "Executing first slot...\n";
  return true;
}
bool secondSlot() {
  std::cout << "Executing second slot...\n";
  return false;
}
bool thirdSlot() {
  std::cout << "Executing third slot...\n";
  return true;
}


int main()
{
  // Part A: 
  boost::signals2::signal<bool(), BootstrapCheck> signal;

  // Part C: 
  // connecting signals 
  sig.connect(&firstSlot);
  sig.connect(&secondSlot);
  sig.connect(&thirdSlot);
  // outputting signal 
  signal(); 
  // not sure what happened but nothing got outputted...expected the first signal
  // to output and then the second and third not to because second signal is false 

}

