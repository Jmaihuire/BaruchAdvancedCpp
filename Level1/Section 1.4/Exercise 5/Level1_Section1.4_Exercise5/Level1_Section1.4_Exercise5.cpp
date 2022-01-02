// Level1_Section1.4_Exercise5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 5: Function Wrapper and Composition

#include <iostream>
#include <functional>

// Part a) The goal of the exercise is to create a single Shape 
// with an embedded command - style function wrapper(such as rotate()
// or other ones).

//Function wrapper
template <typename T>
using FunctionType = std::function<T(const T& t)>;


template <typename T>
class Shape
{
private:
    FunctionType<T> _func;
    T _fac;
public:
    Shape(const FunctionType<T>& function,
        const T& factor) : _fac(factor)
    {
        _func = function;
    }

    T rotate(double d) { return _func(d) * _fac; } //Rename execute to rotate. The functionality is very similar to prior exercise.

    void switchFunction(const FunctionType<T>& function) //Include switch function in shape class
    {
        _func = function;
    }
};

int main() {
    // Example test case
    auto square = [](double d) {return d * d; };
    auto nonsquare = [] (double d) {return std::exp(d); };
    Shape<double> test1(square, 1.0);
    std::cout << "Square: " << test1.rotate(2.0) << '\n'; // 4

    // square is not cool, switch to expo
    test1.switchFunction(nonsquare);
    std::cout << "Exponential: " << test1.rotate(5.0); // 148.413

}
