// Level1_Section1.1_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1: First Encounters with Lambda Functions

#include <iostream>
#include <array>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <complex>

struct multiply
{
    template <typename T>
    T operator() (const T& lhs, const T& rhs)
    {
        return lhs * rhs;
    };
};

int main()
{

    // Part A) Create a lambda function that multiplies each element of an array by a number. 
    //    This number is a captured variable; test the function for the cases when it is 
    //    copy-by-value and a reference. The original array is modified after having called the function.

    std::array<int, 5> testInputArray = { 1, 2, 3, 4, 5 }; //input array 
    int testMultiplier = 10; // number to be multiplied 

    // by reference 
    std::for_each(testInputArray.begin(), testInputArray.end(), [&testMultiplier](int i) {i = i * testMultiplier; });

    // copy-by-value 
    std::for_each(testInputArray.begin(), testInputArray.end(), [testMultiplier](int& i) {i = i * testMultiplier; });


    // Part B) Print the values of the modified array using auto 
    //         to initialize the iterator variable instead of
    //         declaring it explicitly.

    for (auto i = 0; i < testInputArray.size(); i++)
    {
        std::cout << testInputArray[i] << " \n";
    }

    // Part C) Write a lambda function to compute both the minimum and
    //         maximum of the elements in an array. The return type is 
    //         an std::pair (or if you prefer, std::tuple with two elements)
    //         containing the computed minimum and maximum values in the array.

    std::array<int, 5> a1 = { 1, 2, 3, 4, 5 };
    auto findminmax = [](std::array<int, 5> arr) {
        int min = *arr.begin();
        int max = *arr.begin();
        std::for_each(arr.begin(), arr.end(), [&min](int i) mutable {if (i < min) { min = i; }; });
        std::for_each(arr.begin(), arr.end(), [&max](int i) mutable {if (i > max) { max = i; }; });
        std::pair<int, int> out{ min,max };
        return out;
    };

    std::pair<int, int> minMaxOut = findminmax(a1);
    // printing min / max 
    std::cout << "min is: " << std::get<0>(minMaxOut) << std::endl;
    std::cout << "max is " << std::get<1>(minMaxOut) << std::endl; 


   // Part D) Compare the approach taken in part c) 
   // by calling std::minmax_element.For example, 
   // do you get the same output ? How easy is to understand 
   // and reuse the code ?
   auto result = std::minmax_element(begin(a1), end(a1));
   std::cout << *std::get<0>(result) << std::endl;
   std::cout << *std::get<1>(result) << std::endl;
   // same result, easy to understand and reuse code 
}


