// Level2_Section2.4_Exercise3.cpp 
// Fiona Ross - 02 -25 -2022 

#include <iostream>
#include <memory>

int main()
{
	// --------------------------
	//			Part A
	// --------------------------
	//using std::auto_ptr;
	//// Define auto_ptr pointers instead of raw pointers
	//std::auto_ptr <double> d(new double(1.0));
	//std::cout << "Before derefence d is now : " << *d.get() << std::endl;
	//
	//// Dereference
	//*d = 2.0;
	//std::cout << "After derefence d is now : " << *d.get() << std::endl;
	//
	//// Change ownership of auto_ptr
	//// (after assignment, d is undefined and an exception is thrown)
	//auto_ptr <double> d2 = d;
	//	
	//// d.get() is a pointer with zero value, but the type is not nullptr_t. When compared with nullptr they are cast to the same type (?)
	//std::cout << std::boolalpha << "Checking if d is a pointer: " << std::is_pointer<decltype(d.get())>::value << std::endl;        //true
	//std::cout << std::boolalpha << "Checking if d is a null-pointer: " << std::is_null_pointer<decltype(d.get())>::value << std::endl;        //false
	//std::cout << std::boolalpha << "Checking if d.get() is null-pointer: " << (d.get() == nullptr) << std::endl;        //true
	//
	//*d2 = 3.0;

	//std::cout << "Auto values: " << *d.get() << ", " << *d2.get();
	
	// Overview: 
	// --------------
	// we are invoking auto_ptr's copy constructor, but it would be counter-intuitive to have the original becomes empty after copying. 
	// This can lead to a lot of unwanted behaviors if we aren't careful.
	// auto_ptr was created before C++11 and is deprecated now. 
	// You should use unique_ptr in the future for exclusive ownership.


	// -----------------------------------
	// Part B:  
	// changing code to std::unique_ptr
	// -----------------------------------
	using std::unique_ptr;
	// Define auto_ptr pointers instead of raw pointers
	std::unique_ptr <double> d_unq(new double(1.0));

	// Dereference
	*d_unq = 2.0;

	// Change ownership of unique_ptr
	// (after assignment, d is undefined)
	// When changed to unique pointer, this now becomes error C2280 attempting to reference a deleted function

	// unique_ptr <double> d2_unq = d_unq; // initializing it as empty bc previous line did not work since d_unq is deleted
	unique_ptr <double> d2_unq(new double(102));
	unique_ptr <double> d3_unq(new double(103));
	d2_unq.reset();
	d2_unq = std::move(d3_unq);

	std::cout << "Auto d_unq value: " << *d_unq.get() << std::endl;
	std::cout << "Auto d2_unq value: " << *d2_unq.get() << std::endl;
	// std::cout << "Auto d3_unq value: " << *d3_unq.get() << std::endl; // this creates an error since d3_unq is now empty
	
	// Overview 
	// -------------------
	// The unique_ptr steals the resources / transfers ownership using move constructor, and disables the copy constructor 
	// 

}

