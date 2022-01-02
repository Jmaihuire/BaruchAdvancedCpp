// Level1_Section1.3_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1: Fundamentals of Variadics

// The objective of this exercise is to create a variadic print function 
// for objects that support overloading of the standard ouput stream operator <<.


// Part A) Create the template variadic function with its parameter pack.

using namespace std;
#include <iostream>
#include <string>
#include <bitset>

template <typename T, typename...ARGS>
void Ignore(T, ARGS...) {}; //the ignore function takes in template pack but does nothing

template <typename T>
void print(T inputVar)
{
    cout << inputVar << endl;
}

void print()
{
    cout << "I am an empty function and called last" << endl;
}
template <typename T, typename... ARGS>

// Part B) Create the termination/tail function, 
//         that is the print function accepting a single input argument.
void print(T var1, ARGS... var2) {
    cout << var1 << endl;
    print(var2...);
}

int main()
{
    // Part C) Test the function
    // Variadic function templates
    int j = 1; double d = 2.0;
    print(j); print(d); print(j, d); print(d, j);
    std::cout << "\n3 params \n";
    print(d, j, std::bitset<8>(233));

    print(1, 2, 3.14, "Pass me any ",
        "number of arguments",
        "I will print\n");

    return 0;
}