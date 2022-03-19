// Level2_Section2.8_Exercise5.cpp : 
// Fiona Ross 03-19-2022

#include <iostream>
#include "BitMatrix.cpp"
#include <bitset>

 // Part A: Optimal Data Structure 
 // Reasoning: A nested array would seem optimal so you can do 
 // row by row operations and 

int main()
{
	// Part B: Testing Constructors 
	// testing default constructor 
	BitMatrix<5, 3> bitmatrix;
	std::cout << "printing constructor: ";
	bitmatrix.print(); // printing results 

	// testing constructor with value input 
	BitMatrix<5, 6> bitmatrix1(9);
	std::cout << "printing constructor with value input: ";
	bitmatrix1.print();

	// testing copy constructor 
	auto bitmatrix2(bitmatrix1);
	std::cout << "printing copy constructor: ";
	bitmatrix2.print();

	// testing move constructor 
	auto bitmatrix3(std::move(bitmatrix2)); //Move constructor
	bitmatrix3.print();


	// Part C: 
	// test if none, all or any bits are set 
	std::cout << "Checking if bits are set " << bitmatrix3.all() << std::endl;
	std::cout << "Checking if no bits are set " << bitmatrix3.none() << std::endl;
	std::cout << "Checking if any bits are set " << bitmatrix3.any() << std::endl;

	// access the elements 
	std::size_t x = 4;
	std::size_t y = 5;
	bitmatrix3.print();
	std::cout << "Checking access to (4,5) " << bitmatrix3(x, y) << std::endl;
	std::cout << "Counting number of elements in row 2 " << bitmatrix3.count(2) << std::endl;
	std::cout << "Counting total elements " << bitmatrix3.count() << std::endl;

	// Part D: 
	std::cout << "Testing bitwise operations" << std::endl;
	std::cout << "Testing bitwise operation XOR" << std::endl;
	BitMatrix<5, 6> bitmatrix4 = bitmatrix3 ^ bitmatrix2;
	bitmatrix4.print();

	// bitmatrix 4,5,6 all have to be the same size 
	std::cout << "Testing bitwise operation OR" << std::endl;
	BitMatrix<5, 6> bitmatrix5 = (bitmatrix4 | bitmatrix2);
	bitmatrix5.print();
	std::cout << "Testing bitwise operation AND" << std::endl;
	BitMatrix<5, 6> bitmatrix6 = bitmatrix4 & bitmatrix2;
	bitmatrix6.print();

}
