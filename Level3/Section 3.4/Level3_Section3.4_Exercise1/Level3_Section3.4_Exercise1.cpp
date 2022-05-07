// Level3_Section3.4_Exercise1.cpp : 
// Fiona Ross 04-24-2022
#include <iostream>
#include <future>
#include <chrono>
// Part A: function 1 & 2 with following signatures 
void func1() {
  // Simple string output 
	std::cout << "Function 1 has completed\n";
}

double func2(double a, double b) {
  // simple math equation 
	double sum = a + b; 
	std::cout << "a is: " << a << "\nb is: " << b << "\nsum is: " << sum
                  << std::endl;
   return sum;
}

int main() {
  // Part B: Use std::async (default settings) to launch func1 and func2.
  // Get the results of the computations and print them when applicable.
  // Check the validity of the associated future before and after getting the
  // result.

  // Default - garuntees asynch behaviour ... passed function executed in
  // seperate thread
  std::future<void> resultFunc1(std::async(func1));
  double a = 1.0, b = 4.0;
  std::future<double> resultFunc2 = std::async(func2,a,b);

  // checking validity function 1 before 
  std::cout << "(Before)f1 valid? " << std::boolalpha << resultFunc1.valid()<< std::endl;
  std::cout << "(Before)f2 valid? " << std::boolalpha << resultFunc2.valid()<< std::endl;
  
  // not using resutlFunc1.get() because void signature 
  resultFunc2.wait();
  resultFunc2.get();

  // checking validity function 2 after
  std::cout << "\n(After)f1 valid? " << std::boolalpha << resultFunc1.valid() << std::endl;
  std::cout << "\n(After)f2 valid? " << std::boolalpha << resultFunc2.valid()
            << std::endl;

  // Part C: Trying to get result of std::future more than once:
  // std::cout << "Getting Func2 future result for a second time: ";
  // resultFunc2.get();  // throws an error 

  // by not using std::launch the behaviour will be similar to synchronous behaviour 
  
  // Part D: Launch 
  std::cout << "--------PART D----------\n";
  std::future<void> resultFunc1d = std::async(std::launch::async, func1);
  std::future<double> resultFunc2d = std::async(std::launch::async,func2, a, b);

  // checking validity function 1 before
  std::cout << "(Before)f1 valid? " << std::boolalpha << resultFunc1d.valid()
            << std::endl;
  std::cout << "(Before)f2 valid? " << std::boolalpha << resultFunc2d.valid()
            << std::endl;

  // not using resutlFunc1.get() because void signature
  resultFunc2d.wait();
  resultFunc2d.get();

  // checking validity function 2 after
  std::cout << "\n(After)f1 valid? " << std::boolalpha << resultFunc1d.valid()
            << std::endl;
  std::cout << "\n(After)f2 valid? " << std::boolalpha << resultFunc2d.valid()
            << std::endl;

  // by using launch, the behaviour is asynchronous, having the output of func1 prior to the vailidity call 
  // and output of func2 after the .wait() / .get() but before the final validity check
  

  // Part E: Defer 
  std::cout << "--------PART E----------\n";
  std::future<double> resultFunc2e =
      std::async(std::launch::deferred, func2, a, b);

  // checking validity function 1 before
  std::cout << "(Before)f1 valid? " << std::boolalpha << resultFunc2e.valid()
            << std::endl; // func 2 will always print after this output showing how resultFunc2e future defers call of func2 

  // not using resutlFunc1.get() because void signature
  resultFunc2e.wait();
  resultFunc2e.get();

  // checking validity function 2 after
  std::cout << "\n(After)f2 valid? " << std::boolalpha << resultFunc2e.valid()
            << std::endl;

}
