// Level2_Section2.3_Exercise4.cpp : 
/* 
Fiona Ross - 2-19-2022
Emulating depreciated C++98 STL Bind code 

*/ 

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

// Bind to the first param x of f(x,y)
template <typename T>
std::function<T(const T&)> bind1st
(const std::function<T(const T& x, const T& y)>& f, const T& x_)
{
    return [=](const T& y)
    {
        return f(x_, y);
    };
}

// Bind to the second param y of f(x,y)
template <typename T>
std::function<T(const T&)> bind2nd
(const std::function<T(const T& x, const T& y)>& f, const T& y_)
{
    return [=](const T& x)
    {
        return f(x, y_);
    };
}

auto fxy = [](const double& x, const double& y) -> double { return x + y; };

int main()
{
    ScalarFunction f = [](double x) {return x * x; };
    ScalarFunction g = [=](double x) { return x; };

    double yval = 10.0;
    ScalarFunction fx = bind2nd<double>(fxy, yval);
    std::cout << fx(3.0) << std::endl;

    // Test new bind code on STL algorithms
    std::vector<double> vec(10, 2.0);
    std::transform(vec.begin(), vec.end(), vec.begin(), fx);
    for (auto i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ",";
    }
}

