// Level1_Section1.3_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 2: Variadics and Polymorphic Behaviour

// In this exercise we apply variadic functions to allow us to call polymorphic and non-polymorphic functions on a 
// fixed set of objects. This avoids us having to create a composite or aggregate object and then call one of its 
// polymorphic functions. To this end, consider the class hierarchy:
#include <iostream>
#include <array>

// Part A) Based on the result in part a) 
// create a rotation function that works with any 
// object whose class implements the member function rotate().
// Test your code.

//Variadic rotate:
template <typename T>
void rotate(T factor)
{
    std::cout << "end of rotations\n";
}

template <typename T1, typename T2, typename... Types>
void rotate(const T1& factor, T2 arg, Types... args) {
    arg.rotate(factor);
    rotate(factor, args...);
}

class Shape
{
public:
    virtual void rotate(double d) = 0;
};

class Circle : public Shape
{
public:
    void rotate(double d) override { std::cout << "c\n"; }
};

class Line : public Shape
{
public:
    void rotate(double d) override { std::cout << "l\n"; }
};

class Valve
{
public:
    void rotate(double d) { std::cout << "v\n"; }
};

int main() {

    Circle circle;
    Line line;
    Valve valve;

    double factor = 2.0;

    // We can in essence create compile-time aggregates/whole
    // part objects on the fly. We only need to write one function.

    rotate(factor, circle);
    rotate(factor, circle, line);
    rotate(factor, circle, valve);
    rotate(factor * 2, circle, valve, line);


    // Part B) Alternative solution 
    std::array<Shape*, 5> shapeList{ &circle, &line, &circle, &circle, &line };
    double factor2 = 20.0;
    for (auto& elem : shapeList)
    {
        elem->rotate(factor2);
    }
    
// Why can we not include valves in this array ?
//      The array approach initializes the array so that all members 
//      must be a member or derived from Shape class. The valve class is 
//      not derived from Shape. 

// And why can we include valves in the variadic approach ?
//      In the variadic approach the only requirement is that the class 
//      implements the member function rotate(), which valve does, and does not 
//      require the class to be derived from Shape. 
}



