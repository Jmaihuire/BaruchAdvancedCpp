// Level2_Section2.2_Exercise2.cpp :
/*
Fiona Ross - 02-07-2022
Array Categories 
a) Test std::is_array() on different types
b) Finding rank & extent of a multidimensional array
c) remove_extent and remove_all_extent

*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <type_traits>

class MyClass {
public:
    int myNum;  // attribute 
    std::string myString;    // attribute 
};

union S
{
    std::int32_t n; // 4 bytes 
    std::uint16_t s[2]; // 4 bytes
    std::uint8_t c; // 1 byte 
};

int main()
{
    // Part A) Test std::is_array() on a range of:
            // fundamental
            // scalar
            // object 
            // arithmetic 
            // compound types.
            
    // Fundamentals Types 
    std::cout << "\nfundamental unsigned: " << std::is_array<unsigned>::value;
    std::cout << "\nfundamental float " << std::is_array<float>::value;
    std::cout << "\nfundamental nullptr: " << std::is_array<decltype(nullptr)>::value;

    // Scalar Types 
    enum Color {red, green, blue};
 
    std::cout << "\nScalar enum: " << std::is_array<Color>::value;
    std::cout << "\nScalar double " << std::is_array<double>::value;
    std::cout << "\nScalar int: " << std::is_array<int>::value;

    // Object 
    MyClass myObj; // creating an object of MyClass
    std::cout << "\nObject class: " << std::is_array<MyClass>::value;

    // Arithmetic Types 
    std::cout << "\nArithmetic bool: " << std::is_array<bool>::value;
    std::cout << "\nArithmetic char " << std::is_array<char>::value;
    std::cout << "\nArithmetic short int " << std::is_array<short int>::value;
    std::cout << "\nArithmetic long int: " << std::is_array<bool>::value;
    std::cout << "\nArithmetic unsigned  " << std::is_array<char>::value;
    std::cout << "\nArithmetic short int " << std::is_array<short int>::value;

    // Compound Types 
    int three_d[10][20][30];
   
    std::cout << "\nCompound array: " << std::is_array<int [10][20]>::value;
    std::cout << "\nCompound object pointer " << std::is_array<MyClass*>::value;
    std::cout << "\nCompound union: " << std::is_array<S>::value;

    // Part B) Multidimensional Array
    std::cout <<"\nFinding rank of multidimensional array: " << std::rank<int[][2][3][4]>::value << std::endl;
    std::cout <<"Finding rank of multidimensional array: " << std::extent<int[][2][3][4]>::value << std::endl;
   
    // Part C) Multidimensional Array
    typedef std::remove_all_extents<int[][2][3][4]>::type A;
    typedef std::remove_extent<int[][2][3][4]>::type B;
    std::cout << "remove all extent A is same as int: " << std::is_same<int, A>::value << std::endl;
    std::cout << "remove extent B is same as int: " << std::is_same<int, B>::value << std::endl;

    return 0;
}
