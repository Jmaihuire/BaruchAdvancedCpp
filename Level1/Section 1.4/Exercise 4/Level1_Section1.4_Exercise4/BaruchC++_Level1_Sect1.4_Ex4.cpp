// BaruchC++_Level1_Ex1.4.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
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
    VoidFunctionType ex1 = [](const double& d) {std::cout << "example1 \n"; };
    double r1 = 4;
    Shape s1(ex1);
    s1.rotate(ex1, r1);
     
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
