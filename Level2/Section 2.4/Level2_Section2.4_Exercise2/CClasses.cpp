#include <iostream>
#include <boost/shared_ptr.hpp>
#include "Point.cpp"

// Part A: 
//			creating code for C1 & C2 
//			contains shared objects from value d above 
		

class C1 {
	private:
		//double* d; OLD WAY
		// Part A & B
		// boost::shared_ptr<double> d;
		std::shared_ptr<double> d;
	public:
		C1() {};
		C1(std::shared_ptr<double> value) : d(value) {}
		virtual ~C1() { std::cout << "\nC1 destructor\n"; }
		void print() const { std::cout << "Value " << *d; }
};


class C2 {
	private:
		// Part A & B
		// boost::shared_ptr<double> d;
		//double* d; OLD WAY
		std::shared_ptr<double> d;
	public:
		C2() {};
		C2(std::shared_ptr<double> value) : d(value) {}
		virtual ~C2() { std::cout << "\nC2 destructor\n"; }
		void print() const { std::cout << "Value " << *d; }
};



