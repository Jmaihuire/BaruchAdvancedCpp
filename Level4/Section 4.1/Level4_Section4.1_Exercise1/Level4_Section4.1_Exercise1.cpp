// Level4_Section4.1_Exercise1.cpp 
// Fiona Ross 
// 
#include <iostream>
#include "Proposition.h"


// Conditional functions: Define as free functions
// Conditional
Proposition operator%(Proposition p1, Proposition p2) {
  return new Proposition((!p1() || p2()));  //(!A or B)
};
// Biconditional
Proposition operator%=(Proposition p1, Proposition p2) {
  // returning prepositions is better than bools 
  Proposition aImpliesb(p1 % p2);
  Proposition bImpliesa(p2 % p1);
  Proposition result(aImpliesb() & bImpliesa());
  return result;  //(A->B)&(B->A)
};

int main() {
  Proposition a1(true);
  Proposition b1(false);
  Proposition c1(false);

  // Part C: De Morgan's laws:
  std::cout << "NOT (A OR B) == NOT(A) AND NOT(B): "
            << (!(a1 | b1) == (!a1 && !b1)) << std::endl;
  std::cout << "NOT (A AND B) == NOT(A) OR NOT(B): "
            << (!(a1 & b1) == (!a1 || !b1)) << std::endl;
  // Part D: Distributive Laws:
  std::cout << "A AND(B OR C) == (A AND B) OR (A OR C): "
            << (a1() && (b1 | c1) == (a1 & b1) || (a1 | c1)) << std::endl;
  std::cout << "A OR(B AND C) == (A OR B) AND (A OR C): "
            << (a1() || (b1 & c1) == (a1 | b1) && (a1 | c1)) << std::endl;
  
  // Part E: Tautology
  // ABC = 000:
  a1 = false;
  Proposition ab(a1 & b1);
  bool out = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 000: " << out
            << std::endl;
  // ABC = 001:
  c1 = true;
  Proposition ab1(a1 & b1);
  bool out1 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 001: " << out1
            << std::endl;
  // ABC = 010:
  c1 = false;
  b1 = true;
  Proposition ab2(a1 & b1);
  bool out2 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 010: " << out2
            << std::endl;
  // ABC = 100:
  a1 = true;
  b1 = false;
  c1 = false;
  Proposition ab3(a1 & b1);
  bool out3 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 100: " << out3
            << std::endl;
  // ABC = 101:
  c1 = true;
  Proposition ab4(a1 & b1);
  bool out4 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 101: " << out4
            << std::endl;
  
  // ABC = 011:
  a1 = false;
  b1 = true;
  Proposition ab5(a1 & b1);
  bool out5 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 011: " << out5
            << std::endl;
  
  // ABC = 110:
  a1 = true;
  c1 = false;
  Proposition ab6(a1 & b1);

  bool out6 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 110: " << out6
            << std::endl;
  
  // ABC = 111:
  c1 = true;
  Proposition anb7(a1 & b1);
  bool out7 = (a1 % (b1 % c1) %= ab % c1)();
  std::cout << "[A -> (B -> C)] <-> [(A & B) -> C] - 111: " << out7
            << std::endl;
}