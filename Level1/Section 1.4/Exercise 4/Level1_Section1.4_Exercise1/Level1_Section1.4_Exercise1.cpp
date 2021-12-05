// BaruchAdvanacedCpp_Level1.4_Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <functional>

template<typename T>
using FunctionType = std::function<T(const T& t)>;

template <typename T>
void print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';
}

// Function Object (** TO DO ** )
class AddFuncObj
{

public:
    AddFuncObj(double x) { };
    auto operator()(double& x)
    {
        return 2 * x;
    }
};


// Free Function 
double add_freeFunc(const double& x) {
    return 2 * x;
}

// Stored lambda 
FunctionType<double> add_lambda = [&](double a) {return 2 * a; };

int main()
{
    // define them here
    const double x = 3.0;
    AddFuncObj f3(x);

    FunctionType<double> f1 = add_lambda;
    FunctionType<double> f2 = add_freeFunc;
    FunctionType<double> f4 = ;



    //f1(x); // 3 different signature heres 
    //f2 = C();

    print(f1, x);
    print(f2, x);
    print(f3, x);


}


