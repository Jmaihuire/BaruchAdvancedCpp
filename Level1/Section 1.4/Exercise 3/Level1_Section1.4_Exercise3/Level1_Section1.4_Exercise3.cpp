// Level1_Section1.4_Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 3: Function Wrapper and Bind

#include <iostream>
#include <functional>


//In this exercise we modify function arguments so that function signature
// conforms to FunctionType.In this way we resolve the mismatches between 
// functions that we have createdand that have the wrong signature for the 
// current problem.To this end, consider the class :


class C
{
    // Function object with extra member functions
private:
    double _data;
public:
    C(double data) : _data(data) {}
    double operator () (double factor) {
        return _data + factor;
    }

    double translate(double factor) {
        return _data + factor;
    }

    double translate2(double factor1, double factor2) {
        return _data + factor1 + factor2;
    }

    static double Square(double x) {
        return x * x;
    }
};


// Useful synonym to promote readability
template <typename T>
using FunctionType = std::function<T(T t)>;

template <typename T>
void print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';

}


int main()
{
    using namespace std::placeholders;

    // 3 A)  Bind the function wrapper to C’s static member function.
    FunctionType<double> f = std::bind(C::Square, _1);
    print(f, 4.0);

    // 3 B) Binding the function wrapper to C's member functions using 
    //      std::bind and placeholders 
    C c2(3.0);
    f = std::bind(&C::translate, c2, _1);
    print(f, -4.0);

    f = std::bind(&C::translate2, c2, _1, 3.0);
    print(f, -4.0);

}
