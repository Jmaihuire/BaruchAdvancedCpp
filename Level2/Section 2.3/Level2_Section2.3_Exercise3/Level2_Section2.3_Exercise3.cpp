// Level2_Section2.3_Exercise3.cpp :
/*
Fiona Ross - 02-14-2022
Mathematics in C++ 
In this exercise you build a simple vector space of functions.
The basic objective is to show how to create higher-order functions in C++. 
It shows what is possible with lambda functions and the possible applications 
to mathematics, engineering and numeric computation in general.

To scope the problem: 
1. consider only functions of a single variable returning a scalar value
2. All underlying types are double.
*/

#include <iostream>
#include <functional>
#include "VectorMath.cpp"


int main()
{
	// -------------Part A ---------------------
		// Create a function to: 
		// add
		// multiply
		// subtract 
	// -----------------------------------------

	// Scalar functions : double to double
	ScalarFunction f = [](double x) {return x*x; };
	ScalarFunction g = [=](double x) { return x; };

	std::cout << g(2) << ", " << g(8) << "*";
	// Set I: Arithmetic functions

	double scale = 2.0;
	auto fA = 2.0 * (f + g); // multiply scalar & function
	auto fM = f - g; // subtract 2 functions 
	auto fD = f / g; // divide 2 functions 
	auto fMul = f * g; // multiply 2 fuctions 
	auto fC = g << g << 4.0 * g;// Compose
	auto fMinus = -(f + g); //additive inverse 

	double x = 5.0;

	std::cout << fA(x) << ", " << fM(x) << ", " << fD(x) << ", "
		<< fMul(x) << ", compose: " << fC(x) << ", " << fMinus(x);

	//------------------ Part B --------------------
		// Create a function to: 
		// logarithmic of a function
		// cosine of a function
		// absolute value of a function
		// exponential of a function
		// square root of a function
	//-----------------------------------------------
	
	auto ftmp = log(g);
	auto ftmp2 = cos(f);
	auto f2 = (abs(exp(g)) * log(g) + sqrt(ftmp)) / ftmp2;
	std::cout << f2(x) << std::endl;

	//------------------ Part C --------------------
	// Create a function to: 
	// min of 2 functions
	// max of 2 functions 
	//-----------------------------------------------
	auto h1 = min(f, g);
	auto h2 = max(f, g);
	std::cout << "min(f,g): " << h1(2.0) << '\n';
	std::cout << "max(f,g): " << h2(2.0) << '\n';
	auto h3 = min(h1, max(2 * f, 3 * g));
	auto h4 = max(h2, max(-2 * f, 3 * g));
}

