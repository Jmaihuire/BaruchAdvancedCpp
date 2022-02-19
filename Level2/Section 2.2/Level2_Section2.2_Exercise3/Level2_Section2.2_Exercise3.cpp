// Level2_Section2.2_Exercise3.cpp :
/*
Fiona Ross - 02-07-2022
Conversions - structurally changing fundamental properties of types 

*/

#include <iostream>
#include <tuple>
#include <string>

// Part A:
using UnsignedIntType = std::make_unsigned<int>::type;
template<typename T>
UnsignedIntType UnsignIntConversion(T& t1)
{
	std::make_unsigned<int>::type;
}

void SignedUnsigned()
{
	//Mapping integers to unsigned integersand vice versa.
	using UnsignedIntType = std::make_unsigned<int>::type;
	std::cout << "Limits of int: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "Limits of UnsignedIntType: " << std::numeric_limits<UnsignedIntType>::max() << std::endl;
	std::cout << "Limits of unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;

	UnsignedIntType var = std::numeric_limits <unsigned int>::max();
	std::cout << "UnsignedIntType and unsigned int the same: ?" << std::is_same<unsigned int, UnsignedIntType >::value << std::endl;

	using SignedIntType = std::make_signed<UnsignedIntType>::type;
	std::cout << "Limits of int: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "Limits of SignedIntType: " << std::numeric_limits<SignedIntType>::max() << std::endl;

	SignedIntType var2 = std::numeric_limits<int>::max();
	std::cout << "SignedIntType and int the same? " << std::boolalpha << std::is_same<int, SignedIntType>::value << std::endl;

}

void ConstNonConst()
{
	//Mapping integers to unsigned integersand vice versa.
	using ConstType = std::add_const<int>::type;
	std::cout << "Is type const " << std::boolalpha << std::is_const<ConstType>::value << std::endl;
	std::cout << "Limits of ConstType" << std::numeric_limits<ConstType>::max() << std::endl;

	ConstType var = std::numeric_limits <const int>::max();
	std::cout << "ConstType int and const int same ?" << std::is_same<const int, ConstType >::value << std::endl;

	using NonConstType = std::remove_const<ConstType>::type;
	std::cout << "Limits of Non Const type" << std::numeric_limits<NonConstType>::max() << std::endl;

	NonConstType var2 = std::numeric_limits<int>::max();
	std::cout << "SignedIntType and int the same?" << std::boolalpha << std::is_same<int, NonConstType>::value << std::endl;

}

void Pointers()
{
	// Adding and Removing Pointers 
	double d = 3.1415;
	double& rd = d;
	std::cout << "Values d, rd: " << d << ", " << rd << std::endl; 
	std::cout << "Is a double a pointer? " << std::boolalpha << std::is_pointer<double>::value << std::endl; //false 
	std::cout << "Is a double& a pointer? " << std::boolalpha << std::is_pointer<double&>::value << std::endl; //false 
	std::cout << "Is a double* a pointer? " << std::boolalpha << std::is_pointer<double*>::value << std::endl; //true 

	using DoublePointer = std::add_pointer<decltype(d)>::type;
	std::cout << "Is DoublePointer a pointer: " << std::boolalpha << std::is_pointer<DoublePointer>::value << std::endl;

	using BackToDouble = std::remove_pointer<DoublePointer>::type;
	std::cout << "Is BackToDouble a pointer: " << std::boolalpha << std::is_pointer<BackToDouble>::value << std::endl;

}
    
void AddRemoveVolatile()
{
	//Mapping integers to unsigned integersand vice versa.
	using AddVolatile = std::add_volatile<int>::type;
	std::cout << "Is type volatile " << std::boolalpha << std::is_volatile<AddVolatile>::value << std::endl;
	std::cout << "Limits of AddVolatile " << std::numeric_limits<AddVolatile>::max() << std::endl;

	AddVolatile var = std::numeric_limits <volatile int>::max();
	std::cout << "AddVolatile int and const int same? " << std::is_same<volatile int, AddVolatile >::value << std::endl;

	using RemoveVolatile = std::remove_volatile<AddVolatile>::type;
	std::cout << "Limits of removed volatile type " << std::numeric_limits<RemoveVolatile>::max() << std::endl;

	RemoveVolatile var2 = std::numeric_limits<int>::max();
	std::cout << "RemoveVolatile and int the same? " << std::boolalpha << std::is_same<int, RemoveVolatile>::value << std::endl;

}

// Structure to show direct list initialisation vs. copy list initialisation 
struct obj
{
	explicit obj(const char*) {}
}; //copy list initialization not convertible from const char* with copy list initialization 

struct obj1
{
	obj1(const char*) {}
}; // convertible from const char* with copy list initialization 

// give a non trivial example of std::tuple with user-defined class 
class TupleExample
{
public:
	std::string name;
	int age;
	std::string profession;
	std::tuple<std::string, int, std::string> Person;

	void makePerson();
	void printPerson();
};
void TupleExample::makePerson()
{
	Person = std::make_tuple(name, age, profession);
};
void TupleExample::printPerson()
{
	std::cout << "My name is: " << std::get<0>(Person) << std::endl;
	std::cout << " I am " << std::get<1>(Person) << " years old" << std::endl;
	std::cout << " I work as a " << std::get<2>(Person) << std::endl;
};

int main()
{
	//Mapping integers to unsigned integersand vice versa.
	std::cout << "\nSigned / Unsigned ints" << std::endl;
	SignedUnsigned();

	// Add / remove the const specifier to or from a type.
	std::cout << "\nConst / Non Const ints" << std::endl;
	ConstNonConst();

	// Add / remove a pointer to or from a type.
	std::cout << "\nPointer / Non Pointer ints" << std::endl;
	Pointers();

	// Add / remove the volatile specifier to or from a type.
	std::cout << "\nVolatile / Non Volatile ints" << std::endl;
	AddRemoveVolatile();

	// Discuss the difference between direct list initialisation and copy list initialisation in C++17 / 20 compared to C++11. 
	// In which case does auto deduction reduce to std::initializer_list ? Give a code example.
	
	// Direct List Initialization in C++ 11 does not include an equal sign 
	int myInt{ 43 };
	// for C++17 can use auto and a value is deduced 
	auto initList4{ 34 }; // this compiles 
	// auto initList5{39,30}; // this does not compile because more than 1 initialization value given 

	// Copy List Initialization requires an equal sign 
	int myInt1 = { 43 }; 
	// for C++ 17 can use auto type and the initalizer_list<> is deduced but all values must be of the same type 
	auto initList1 = { 54 }; //compiles 
	auto initList2 = { 30,30,32 }; //compiles 
	// auto initList3 = { 23, 31, 30.32 }; //does not compile 

	// Under which circumstances can we get ill - formed expressions ? 
	// Copy list initialization auto deduction will deduce a std::initializer_list if all elements in the list have the same type, or be ill-formed.
	// Direct list initialization auto deduction will deduce a T if the list has a single element, or be ill - formed if there is more than one element.

	// Discuss how Class Template Argument Deduction(CTAD)) reduces code verbosity.
		// Prior to CTAD's whenever you used a class template you either had to 
		// 1) explicitly specify the template parameters 
		// 2) write a helper function that does the deduction for you 
		// With CTAD, the class template arguments can be deduced by construction of the primary
		// class template or dedution guides. 

	// Give a non - trivial example using std::tuple and a user - defined class.
	TupleExample TupEx;
	TupEx.age = 15;
	TupEx.name = "Fiona";
	TupEx.profession = "Engineer";
	TupEx.makePerson();
	TupEx.printPerson();

	// Investigate the applicability of decltype and std::is_same when comparing the type of a result with a “target” type.
}

