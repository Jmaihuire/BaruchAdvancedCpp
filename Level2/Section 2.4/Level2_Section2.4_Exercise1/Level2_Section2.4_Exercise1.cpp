// Level2_Section2.4_Exercise1.cpp : 
/* 
Fiona Ross - 02-19-2022

*/

#include <iostream>
#include "Point.cpp"

// Part D: alias template definition 
using uniq_pt = std::unique_ptr<Point>;

int main()
{
	// Block with raw pointer lifecycle
	std::unique_ptr<double> d(new double(1.0));
	std::unique_ptr<Point> pt(new Point(1.0, 2.0)); // Two-d Point class

	// Dereference and call member functions
	*d = 2.0;
	(*pt).X(3.0);// Modify x coordinate
	(*pt).Y(3.0);// Modify y coordinate

	// Can use operators for pointer operations
	pt->X(3.0);// Modify x coordinate
	pt->Y(3.0);// Modify y coordinate

	// Try-Catch block allocating memory and then throwing an exception
	try {
		std::unique_ptr<Point> pt1 (new Point(1.0, 2.0)); // 2D Point class constructed 
		throw - 1; // throwing an exception 
		
		// Part B: 
		// with std::unique_ptr this throws error: 
		// E0852 - that expression must be a pointer to a compete object type
		// C2440 - 'delete': cannot convert from std::unique_ptr<Point, std::default_delete<Point>> to void
		// Without the following lines we get confirmation that the destructor has run, deleting the Point object 
		// delete pt1; // calling delete  
	}
	catch (int i) {
		std::cout << "An exception is thown after memory is allocated." << std::endl; 
	}
	
	// Explicitly clean up memory (if you have not forgotten)

	// Part B: 
		// with std::unique_ptr this throws error: 
		// E0852 - that expression must be a pointer to a compete object type
		// C2440 - 'delete': cannot convert from std::unique_ptr<Point, std::default_delete<Point>> to void
		// Without the following lines we get confirmation that the destructor has run, deleting the Point object 
	// delete d;
	// delete pt;
	
	// Part A: 
	// delete pt1; 
	// This caused error C2065 --> undeclared identifier 
	//			   error C2541 --> 'delete cannaot delete objects that are not pointers' 
	// but the destructor message was never called 

	// Part C: 
	// initializing two unique pointers to the same pointer 
	// this likely will cause undefined behaviours since both uniq1_to_raw & uniq2_to_raw will delete raw_orig_pt
	// this ran and then triggered a non voluntary break point because invalid address specified to the heap
	// Point* raw_orig_pt = new Point; // raw pointer 
	// std::unique_ptr<Point> uniq1_to_raw(raw_orig_pt); // first unique pointer to raw
	// std::unique_ptr<Point> uniq2_to_raw(raw_orig_pt); // second unique pointer to raw
	
	// assigning a raw pointer to a different unique pointer 
	// std::unique_ptr<Point> uniq_orig_pt(new Point(45.0, 34.0));
	// assigning a raw pointer to a unique pointer causes errors 
	//		E1776 - cannot reference a deleted function 
	//		C2280 - attempting to reference a deleted function 
	// auto raw_to_uniq = uniq_orig_pt;

	// copy construct/ move construct one unique_ptr from another unique_ptr
	// this ran okay and destructor was called 
	// std::unique_ptr<Point> uniq1_test_move(new Point(33.0, 23.0));
	// std::unique_ptr<Point> uniq2_test_move;
	// std::move(uniq1_test_move) > (uniq2_test_move);

	// copy assign / move assign from one unique_ptr to another.
	// This caused errors:
	// E1776 - cannot reference unique_ptr -- it is deleted 
	// C2280 - attempting to reference a deleted function 
	// std::unique_ptr<Point> uniq1_test_assgn(new Point(24.0, 29.0));
	// std::unique_ptr<Point> uniq2_test_assgn;
	// uniq2_test_assgn = uniq1_test_assgn;

	// Part D: Alias template use 
	uniq_pt aliasPt(new Point(30.0, 23.0));



}
