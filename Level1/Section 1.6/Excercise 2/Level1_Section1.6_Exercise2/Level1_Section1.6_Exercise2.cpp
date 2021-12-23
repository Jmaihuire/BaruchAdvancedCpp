// Level1_Section1.6_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* 
Exercise 2: Implementing the GOF Template Method Pattern(TMP)
            Objective is to use sealed/final member functions and universal function wrappers.
            
            Design an algorithm to multiply each of the elements of a vector by a given value
            (from an abstract input source) and then send the modified vector to some abstract output device

            1. Preprocessor: get the value that multiplies the elements of the vector.
            2. Computation: use std::transform and a lambda function to perform the steps in the algorithm.
            3. Postprocessor: send the data to the output device.
 */

#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>

using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

// Part A:
//          Create a single class TMPClass consisting of a vector, 
//          input deviceand output device.Build the code for the algorithm.

struct TMPClass
{
private:
    std::vector<double>m_vec;
    InputFunction m_iFunction;
    OutputFunction m_oFunction;

public:
    TMPClass(std::size_t n, std::vector<double>&vec, double startValue, InputFunction iFunction, OutputFunction oFunction)
    {
        m_iFunction = iFunction;
        m_oFunction = oFunction;
        for (auto i : vec)
        {
            vec[i] = startValue;
        }
        m_vec = vec; 
    }

    void compute()
    {
        std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [this](double& elem) {
            return elem * m_iFunction();
            });
    }

    void Print()
    {
        for (auto i : m_vec)
        {
            std::cout << m_vec[i];
        }
    }

    ~TMPClass() { std::cout << "Bye TMPClass"; }
};

class Preprocessor : public TMPClass
{


};


int main()
{
    std::cout << "Hello World!\n";
}
