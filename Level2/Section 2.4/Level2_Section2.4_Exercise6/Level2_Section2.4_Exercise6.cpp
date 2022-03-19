// Level2_Section2.4_Exercise6.cpp 
/*
A weak pointer is an observer of a shared pointer. 
It is useful as a way to avoid dangling pointers 
and when we wish to use shared resources without assuming ownership.
Answer the following questions:

a) Create a shared pointer, print the use count and then create a weak pointer that observes it. Print the use count again. What are the values?

b) Assign a weak pointer to a shared pointer and check that the weak pointer is not empty.

c) Assign a weak pointer to another weak pointer; assign a weak pointer to shared pointer. What is the use count in both cases?

*/
#include <iostream>
#include <memory>
#include <ios>

int main()
{	// PART A: 
	// creating weak pointer 
	std::weak_ptr<double> w;

	// creating shared pointer 
	std::shared_ptr<double> commonValue(new double(3.145));
	
	// getting count of shared pointer 
	std::cout << "Ref count:" << commonValue.use_count() << std::endl;
	
	// setting weak pointer so observes shared pointer 
	w = commonValue;

	// getting count of shared pointer after weak pointer observes it
	std::cout << "Ref count after weak pointer observes shared pointer: " << commonValue.use_count() << std::endl;
	// count does not increase even after weak pointer observes shared pointer 

	// PART B: 
	// assigning weak pointer to shared pointer
	std::weak_ptr<double> w2;
	std::shared_ptr<double>sp = w2.lock();

	// checking that weak pointer is not empty 
	std::cout << "Ref count of shared pointer: " << sp.use_count() << std::endl; // count is one 
	std::cout << "Checking if weak pointer is expired: " << std::boolalpha << w2.expired() << std::endl; // w2 is expired 


	// PART C: 
	std::weak_ptr<double> w3; 
	std::shared_ptr<double> sptr_2_wptr;
	std::weak_ptr<double> wptr_2_wptr = w3.lock();
	sptr_2_wptr = wptr_2_wptr.lock();


	std::cout << "Ref count of weak ptr 2 weak ptr " << wptr_2_wptr.use_count() << std::endl; // the weak pointer is empty 
	std::cout << "Checking if weak pointer is expired: " << std::boolalpha << wptr_2_wptr.expired() << std::endl; // wptr_2_wptr is expired 
	std::cout << "Ref count of shared ptr 2 weak ptr " << sptr_2_wptr.use_count() << std::endl; // expected to have count of zero because wptr_2_wptr is expired 
	


}

