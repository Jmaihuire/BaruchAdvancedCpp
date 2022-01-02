// Level1_Section1.4_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 2: Function Wrapper and partial Function Evaluation 101
#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>
/*
	Resources: https://home.cc.umanitoba.ca/~psgendb/doc/local/pkg/CASAVA_v1.8.2-build/opt/bootstrap/build/boost_1_44_0/libs/bind/bind.html

	Function arity means: 
	Minimum & maximum arity
	We can define the minimum arity as the smallest number of arguments function expects and the maximum arity as the largest number of arguments that function takes.
	
	Definite & Fixed arity
		Fixed arity function is the most popular kind present in almos tall programming languages.
		Fixed arity function must be called with the same number of arguments as the number of parameters specified in its declaration.
		
		Definite arity function must be called with a finite number of arguments.
*/

// Function of arity 3
double freeFunction3(double x, double y, double z)
{
	return x + y + z;
}


int main()
{
	// Part B) Test these functions by binding the appropriate 
	//		   variables and checking that the output is correct.
	
	// Defining functions of different arity using bind 
	auto arity_3 = boost::bind(&freeFunction3, _1, _2, _3);
	auto arity_2 = boost::bind(&freeFunction3, _1, _2, 0);
	auto arity_1 = boost::bind(&freeFunction3, _1, 0, 0);
	auto arity_0 = boost::bind(&freeFunction3, 0, 0, 0);

	// Part A) Define functions of arity 3, 2,1 and 0 
	//		   based on the above function.

	// Testing Arity of 3
	double d1 = 1.0; double d2 = 2.0; double d3 = 3.0;
	auto expect3 = freeFunction3(d1, d2, d3);
	auto actual3 = arity_3(d1, d2, d3); 
	if (expect3 == actual3) { std::cout << " Correct! " << std::endl; }
	else{ std::cout << "Try again for arity 3" << std::endl; }

	// Testing Arity of 2
	double e1 = 1.0; double e2 = 2.0;
	auto expect2 = freeFunction3(e1, e2, 0);
	auto actual2 = arity_2(e1, e2);
	if (expect2 == actual2) { std::cout << " Correct! " << std::endl; }
	else { std::cout << "Try again for arity 3" << std::endl; }

	// Testing Arity of 1
	double f1 = 1.0; 
	auto expect1 = freeFunction3(f1, 0, 0);
	auto actual1 = arity_1(f1);
	if (expect1 == actual1) { std::cout << " Correct! " << std::endl; }
	else { std::cout << "Try again for arity 3" << std::endl; }

	// Testing Arity of 0
	auto expect0 = freeFunction3(0, 0, 0);
	auto actual0 = arity_0();
	if (expect0 == actual0) { std::cout << " Correct! " << std::endl; }
	else { std::cout << "Try again for arity 3" << std::endl; }
}

