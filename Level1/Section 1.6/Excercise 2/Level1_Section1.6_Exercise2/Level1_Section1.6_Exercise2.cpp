// Level1_Section1.6_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include "TMPClass.h"


using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

double InputFunction1()
{
    return 15;
}

void OutputFunction1(std::vector<double> vec)
{
    for (auto& i : vec)
    {
        std::cout << i <<std::endl;
    }
}

int main()
{
    std::vector<double> vec(10);
    double startValue = 15;

    // functions to initialize oF / iF ... otherwise they would be empty
    OutputFunction oF = OutputFunction1;
    InputFunction iF = InputFunction1;

    TMPClass T1(10, startValue, iF, oF);
     T1.Print();
     T1.compute();
     T1.Print();
}
