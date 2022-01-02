// Level1_Section1.4_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

// Part A) 
// Create an instance of a function wrapper :
// and a function to print the value of f (after it has been assigned 
// to a target method) for a given input argument:
    template<typename T>
    using FunctionType = std::function<T(const T& t)>;

    template <typename T>
    void print(const FunctionType<T>&f, T t)
    {
        std::cout << f(t) << '\n';
    }

    // Part B) 
    // Function Object (** TO DO ** )
    class AddFuncObj
    {

    public:
        //AddFuncObj(double x) { };
        double operator()(double x)
        {
            return 2 * x;
        }
    };

    // Part B) 
    // Free Function 
    double add_freeFunc(const double& x) {
        return 2 * x;
    }

    // Part B) 
    // Stored lambda 
    FunctionType<double> add_lambda = [&](double a) {return 2 * a; };

    int main()
    {
        AddFuncObj addfuncobj;

        // define them here
        const double x = 3.0;
        FunctionType<double> f1 = add_lambda;
        FunctionType<double> f2 = add_freeFunc;
        FunctionType<double> f4 = addfuncobj;

        // 3 different signature heres 
        std::cout << '\n' << f4(3.0) << '\n';
        print(f1, x);
        print(f2, x);
        print(f4, x);
    }
    

