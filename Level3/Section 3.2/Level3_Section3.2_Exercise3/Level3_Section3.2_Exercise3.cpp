// Level3_Section3.2_Exercise3.cpp 
// Fiona Ross 04-15-2022
// Did not put ActiveObject into own header file since such a small class 

#include <iostream>
#include <thread>

// Part A: thread & simple print function 
// function 1 definition 
void h_wld() { std::cout << "hello world! \n"; }
std::thread t_string(&h_wld);

// Part B: Active object based on thread with no 
// associated function 
class ActiveObject {
 private:
  std::thread& activeThread = t_string;

 public:
  // constructor
  explicit ActiveObject(std::thread src) {
    src.join();
    std::cout << "Active Object constructed\n";
  }

  // destructor
  ~ActiveObject() {
    if (activeThread.joinable()) activeThread.join();
    std::cout << "destructed\n";
  }
};

// function 2 definition 
void b_wld() {

std::cout << "bye world! \n";
}

// Part C: impliment thread function using function objects & lambda 


int main() { 

  auto wld = []() { std::cout << "still in world!" << std::endl; }; //lambda 
  std::thread t(wld); // making lambda thread 
  std::thread t1(&b_wld); // making function thread 
  ActiveObject obj(std::move(t)); //function object 
  ActiveObject obj1(std::move(t1)); //function object 

  // Output is: 
  /*
  
  hello world !
  bye world !
  still in world !
  Active Object constructed 
  Active Object constructed 
  destructed 
  destructed
  
  */ 
}

