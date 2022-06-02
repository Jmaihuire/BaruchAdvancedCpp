#ifndef __PROP_

#include <bitset>
#include <iostream>
class Proposition {
 private:
  std::bitset<1> data;

 public:
  // Part A: Constructors
  Proposition();                    // default constructor
  Proposition(bool arg);            // bool as argument
  Proposition(std::bitset<1> arg);  // bitset as arg

  // Part B:
  // Note- I realize it would probably make more sense for these operators to
  // return propositions, but this still serves as an adapter class to
  // std::bitset<1>
  // Equality/inequality
  bool operator==(const Proposition& p);
  bool operator!=(const Proposition& p);
  // And
  Proposition operator&(const Proposition& p);
  // OR
  Proposition operator|(const Proposition& p);
  // XOR
  Proposition operator^(const Proposition& p);
  // Negation
  Proposition operator!();
  // Assign proposition to a bool
  void operator=(bool b);

  // Get data
  bool operator()();

  // Print data
  friend std::ostream& operator<<(std::ostream& os, const Proposition& p);
};

#endif