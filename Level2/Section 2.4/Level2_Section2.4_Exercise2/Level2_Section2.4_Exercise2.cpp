// Level2_Section2.4_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/shared_ptr.hpp>
#include "CClasses.cpp"
#include "Point.cpp"

int main()
{
 // // Part A & B: 
	//std::cout << "Built in Types \n"; 
	//std::shared_ptr<double> commonValue(new double(3.1415));
	//
	//std::cout << "\nUse count number is: ";
	//std::cout << commonValue.use_count();
	//
	//{
	//	C1 object1(commonValue);
	//	object1.print(); 
	//}

	//C2 object2(commonValue);
	//object2.print();

	//std::cout << "\nUse count number is: ";
	//std::cout << commonValue.use_count();
	//// C1 & C2 destructor is called  

	// Part C: 
	std::cout << "\nPart C: " << std::endl;
	std::shared_ptr<Point> p(new Point(1.0,30.0)); //initialize shared pointer
	std::cout << " Confirm 1 owner : "; 
	std::cout << p.use_count() << std::endl; //1 owner

	std::shared_ptr<Point> p1 = p;
	std::cout << " Confirm 2 owners : "; 
	std::cout << p.use_count() << std::endl; //2 owners

	{
		// initialize p2 in an additional scope so destructor is called. We can see the shared pointer owner increase by one and then decrease by one after destructor call.
		std::shared_ptr<Point> p2 = p; 
		std::cout << " Confirm 3 owners : ";
		std::cout << p.use_count() << std::endl; //3 owners
	}

	std::cout << " Confirm back to 2 owners : ";
	std::cout << p.use_count() << std::endl; //Back to only 2 owners

	// Part D: 	
	// assigning, copy and compare two shared pointers sp1 and sp2. 
	std::shared_ptr<Point> initial(new Point(30.0, 34.0));
	std::shared_ptr<Point> sp1 = initial; // assigning 
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(*sp1); // copying 

	std::cout << "Confirm initial has 2 owners : " << std::endl;
	std::cout << initial.use_count() << std::endl;
	// Comparing ownership 
	if (sp1 == sp2)
	{
		std::cout << "sp1 == sp2\n";
	}
	else
	{
		std::cout << "sp1 != sp2\n";
	};

	// Transfering ownership 
	sp2 = std::move(initial);
	
	std::cout << "Initial count after transfer of ownership : ";
	std::cout << initial.use_count() << std::endl;

	// Determine if a shared pointer is the only owner of a resource 
	std::shared_ptr<Point> sp3(new Point(38.0, 28.0));
	
	std::cout << "Is p shared pointer unique: " << p.unique() << std::endl;
	std::cout << "Is sp1 shared pointer unique: " << sp1.unique() << std::endl;
	std::cout << "Is sp2 shared pointer unique: " << sp2.unique() << std::endl;
	std::cout << "Is sp3 shared pointer unique: " << sp3.unique() << std::endl;

	// Swap sp1 and sp2 
	sp2.swap(sp3);
	sp1.swap(sp2);
	////std::cout << "sp3 was 38.0 , 28.0 and is now: " << sp3 << std::endl;
	////std::cout << "sp2 was 30.0, 34.0 and is now: " << sp2 << std::endl;
	////std::cout << "sp1 was 30.0, 34.0 and is now: " << sp2 << std::endl;

	// Give up ownership and re-initialize the shared pointer as being empty 
	sp1.reset(); // release ownership from sp1
	std::cout << "\n";
	std::cout << "After reset sp1 has count of: " << sp1.use_count() << std::endl;
	std::cout << "\n";
	sp1 = nullptr; // re-initialize the pointer as empty 

}


