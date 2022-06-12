// Level6_Section6.9_Exercise1.cpp 
// Fiona Ross 
// State Pattern: Stack implementation using State Pattern

#include <iostream>
#include "Stack.h"

int main() {
  // creating a stack
  int n = 11;
  Stack stk(n);

  for (int i = 0; i < n - 1; i++) {
    stk.Push(i);  // switch to not full not empty
  }

  // want to try catching error if the stack is full
  try {
    stk.Push(5);
  } catch (std::runtime_error e1) {
    std::cout << e1.what();
  }

  // What about an empty stack??
  Stack stk2(0);

  // trying out push error
  try {
    stk2.Push(1);  // throw error because cant push to full stack
  } catch (std::runtime_error e2) {
    std::cout << e2.what();
  }

  // trying out pop error
  try {
    stk2.Pop();  // throw error because cant pop from empty stack
  } catch (std::runtime_error e4) {
    std::cout << e4.what();
  }
}

