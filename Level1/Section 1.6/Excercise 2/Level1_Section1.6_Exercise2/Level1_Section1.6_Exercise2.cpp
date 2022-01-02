// Level1_Section1.6_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include "TMPClass.h"

// Part A) Create a single class TMPClass consisting of a vector,
//         input deviceand output device.Build the code for the algorithm.

using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

class TmpClass final {
private: 
    std::vector<double> inVec;
    InputFunction inFunction;
    OutputFunction outFunction;

public:
    TmpClass(std::size_t n, double firstVal, InputFunction inFunc, OutputFunction outFunc) :
        inFunction(inFunc), outFunction(outFunc) {
        inVec.assign(n, firstVal);
    }

    void multiplier() {
        double mult = inFunction();
        std::transform(inVec.begin(), inVec.end(), inVec.begin(), [&mult](double& d) { return d * mult; });
        outFunction(inVec);
    };
};

int main()
{
    std::vector<double> vec(10);
    double startValue = 15;
    double factor = 10;

    // functions to initialize oF / iF ... otherwise they would be empty
    InputFunction iF = [factor]() {return factor; };
    OutputFunction oF = [](const std::vector<double>& vec) {
        for (int i = 0; i < vec.size(); i++) { std::cout << vec[i]; }
        std::cout << "" << std::endl;
    };

    std::size_t size = 4;
    double startVal = 34;

    // Part B) Instantiate TMPClass by the constructor :

TMPClass tmp1(size, startVal, iF, oF);
std::cout << "startValue = " << startVal << "\n";
std::cout << "factor = " << factor << "\n";
tmp1.compute(); 
}

