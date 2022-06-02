#include "Proposition.h"

// Default
Proposition::Proposition() { data.reset(); }

// bool as argument
Proposition::Proposition(bool arg) { data.set(0, arg); };

// bitset as arg
Proposition::Proposition(std::bitset<1> arg) { data = arg; };

bool Proposition::operator()() { return (data[0] == 1); };

// Part B:
// Equality/inequality
bool Proposition::operator==(const Proposition& p) {
  return p.data[0] == this->data[0];
};
bool Proposition::operator!=(const Proposition& p) {
  return p.data[0] != this->data[0];
};
// And
Proposition Proposition::operator&(const Proposition& p) {
  return new Proposition(p.data[0] && this->data[0]);
};
// OR
Proposition Proposition::operator|(const Proposition& p) {
  return p.data[0] || this->data[0];
};
// XOR
Proposition Proposition::operator^(const Proposition& p) {
  return p.data[0] ^ this->data[0];
};
// Negation
Proposition Proposition::operator!() { return !this->data[0]; };
// Assign proposition to a bool
void Proposition::operator=(bool b) { this->data[0] = b; };
