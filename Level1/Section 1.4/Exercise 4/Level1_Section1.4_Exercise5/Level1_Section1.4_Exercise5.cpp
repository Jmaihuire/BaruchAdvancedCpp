// Level1_Section1.4_Exercise5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

template <typename T>
class NextGenPolymorphism
{
private:
    FunctionType<T> _func;
    T _fac;
public:
    NextGenPolymorphism(constFunctionType<T>& function,
        constT& factor) : _fac(factor)
    {
        _func = function;
    }

    T execute(doubled) { return _func(d) * _fac; }
    void switchFunction(constFunctionType<T>& function)
    {
        _func = function;
    }
};

template <typename T>
class Shape
{
private:
    using VoidFunctionType = std::function<void(T)>;
    VoidFunctionType<T> _func;
    T _fac;
public:
    Shape(VoidFunctionType<T>& function, const T& factor) : _fac(factor)
    {
        _func = function;
    }

    T rotate(doubled) { return _func(d) * _fac; }
    void switchFunction(VoidFunctionType<T>& function)
    {
        _func = function;
    }
};

int main()
{
    // Next gen stuff
    auto square = [](double d) {return d * d; };
    auto expo = [](double d) {return std::exp(d); };
    Shape<double> ng(square, 1.0);
    std::cout << "Square: " << ng.rotate(2.0) << '\n'; // 4
    // square is not cool, switch to expo
    ng.switchFunction(expo);
    std::cout << "Exponential: " << ng.rotate(5.0); // 148.413
  
}
