// Level1_Section1.4_Exercise4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 4: Function Wrapper and Inheritance
#include<iostream>
#include<functional>
using namespace std;

using VoidFunctionType = std::function<void(double)>;

class Shape
{
protected:
    VoidFunctionType f;

public:
    Shape() {};
    Shape(const VoidFunctionType& fn) { f = fn; };
    virtual void rotate(VoidFunctionType, double d) { f(d); };
};
class Circle : public Shape
{
public:
    Circle(const VoidFunctionType& fn) { f = fn; };
    // void rotate(double d) override{ std::cout << "c\n"; }
};




int main()
{
    // Example 1 
    VoidFunctionType ex1 = [](const double& d) {std::cout << "example1 \n"; };
    double r1 = 4;
    Shape s1(ex1);
    s1.rotate(ex1, r1);

    // Example 2 
    VoidFunctionType ex2 = [](const double& d) {std::cout << "example1 \n"; };
    int r2 = 6;
    int rotation = 3;
    Shape s2(ex2);
    s2.rotate(ex2, rotation);

    // Example 3
    Circle c1(ex2);
    c1.rotate(ex2, rotation);

}