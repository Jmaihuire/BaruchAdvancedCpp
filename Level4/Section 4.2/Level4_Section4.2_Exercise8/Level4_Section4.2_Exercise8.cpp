// Level4_Section4.2_Exercise8.cpp 
// Fiona Ross 
// Classifying Algorithms 


#include <iostream>

#include <iostream>
#include <vector>
#include <stack>

// min max, drop, and over are all modifying algorithms
// rot and swap are mutating algorithms

// modifying algorithms 
void max(std::stack<int>& stk) { //iterating through stack checking to see if val is higher than max val 
  int maxVal = stk.top();  
  stk.pop();
  while (!stk.empty()) {
    if (maxVal > stk.top()) {
      stk.pop();
    } else {
      maxVal = stk.top();
      stk.pop();
    }
  }
  stk.push(maxVal);  // this puts the max val back onto stack 
}

// modifying algorithm 
// iterating through stack checking to see if val is lower than min val
void min(std::stack<int>& stk) {
  int maxVal = stk.top();  // 
  stk.pop();
  while (!stk.empty()) {
    if (maxVal < stk.top()) {
      stk.pop();
    } else {
      maxVal = stk.top();
      stk.pop();
    }
  }
  stk.push(maxVal);  // this puts the max val back onto stack 
}

// modifying algorithm 
// duplicate seconds stack value on top of stack
void over(std::stack<int>& stk) {
    int topVal = stk.top();
    stk.pop();
    int secondVal = stk.top();
    stk.push(topVal);
    stk.push(secondVal);
}

// this is a helper function so we can properly do the rot() function 
void elem_to_bottom(std::stack<int>& stk, int val2) {
  if (stk.empty()) {
    stk.push(val2);
  } else {
    int val = stk.top();
    stk.pop();
    elem_to_bottom(stk, val2);
    stk.push(val);
  }
}

// mutating algoirhtm 
// rotate third data value to top of stack 
void rot(std::stack<int>& stk) {
  int numRotations = 2;  // 2 rotations will give us the third data value 
  for (int i = 0; i < numRotations; i++) {
    int val = stk.top();
    stk.pop();
    elem_to_bottom(stk, val);
  }
}

// mutating algorithm
// swap top two values
void swap(std::stack<int>& stk) {
  int val = stk.top();
  stk.pop();
  int val2 = stk.top();
  stk.pop();
  stk.push(val);
  stk.push(val2);
}

// mutating algorithm 
// Drop()
void drop(std::stack<int>& stk) {
  stk.pop();  // discard top element
}

// print
void print(std::stack<int> stk) {
  while (!stk.empty()) {
    std::cout << stk.top() << " ";
    stk.pop();
  }
  std::cout << std::endl;
}


int main()
{
   // creating a stack for testing 
	std::stack<int> stack_test;
   for (int i = 0; i < 10; i++) {
     stack_test.push(i);
   }

   // making copy of original stack for each test 
   std::stack<int> stack_test1(stack_test);
   std::stack<int> stack_test2(stack_test);
   std::stack<int> stack_test3(stack_test);
   std::stack<int> stack_test4(stack_test);
   std::stack<int> stack_test5(stack_test);
   std::stack<int> stack_test6(stack_test);

    // Testing functions 
    std::cout << "max" << std::endl; 
    max(stack_test1); 
    print(stack_test1);

    std::cout << "min" << std::endl;
    min(stack_test2);
    print(stack_test2);

    std::cout << "over" << std::endl;
    over(stack_test3);
    print(stack_test3);

    std::cout << "rot" << std::endl;
    rot(stack_test4);
    print(stack_test4);

    std::cout << "swap" << std::endl;
    swap(stack_test5);
    print(stack_test5);

    std::cout << "drop" << std::endl;
    drop(stack_test6);
    print(stack_test6);
}
