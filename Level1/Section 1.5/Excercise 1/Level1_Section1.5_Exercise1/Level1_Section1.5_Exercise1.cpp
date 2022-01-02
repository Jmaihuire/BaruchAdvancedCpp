// Level1_Section1.5_Exercise5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1: Tuple/Span 101

#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <span>
#include <iomanip>
#include <boost/date_time/gregorian/gregorian.hpp>


// Printing elements in Tuple (1B)
void print(std::tuple <std::string, std::string, boost::gregorian::date>const& inputTuple) {
    std::cout << "(" << std::get<0>(inputTuple) << ", " << std::get<1>(inputTuple)
        << ", ";
    boost::gregorian::date Date = std::get<2>(inputTuple);
    std::cout << Date << ")\n";
}

// Sorting Funciton (1D)
bool sortTuple(const std::tuple <std::string, std::string, boost::gregorian::date>& LHS, const std::tuple <std::string, std::string, boost::gregorian::date>& RHS)
{
    std::cout << "sorting tuple by birthdate \n";
    return (std::get<2>(LHS) < std::get<2>(RHS));
}

// Print using range based for loop (1E)
void printSpan(const std::span<int>& ref)
{
    for (int val : ref)
        std::cout << val << " ";

    std::cout << "\n";
}

// Print using indexing [] (1E)
void printSpan1(const std::span<int>& val)
{
    for (auto i = 0; i != val.size(); ++i)
        std::cout << val[i] << " ";

    std::cout << "\n";
}

// Print using iterators (1E)
void printSpan2(std::span<int> val2)
{
    for (auto i = std::begin(val2); i != std::end(val2); ++i)
    {
        std::cout << *i << ",";
    }
    std::cout << "\n";
}


// (1E) 
void TestSpan()
{
    // creating test data 
    const int M = 10;
    std::array<int, M> fixedArray = { 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int> variableArray1 = { 2,4,6,8,10,12,14,16,18,20 };
    int variableArray[5] = { 10,20,30,40,50 };

    // Creating spans (contigious sequence of objects) 
    auto s1 = std::span(fixedArray);
    auto s2 = std::span(variableArray1);
    auto s3 = std::span(variableArray);
    auto s4 = std::span(s3);

    printSpan(s1);
    printSpan1(s2);
    printSpan2(s3);
    printSpan2(s4);

    nFirstElem(s1, 3);
    nLastElem(s2, 3);

    testSubspan(s1, 2, 3);

}

// returning first and last N elements of span (1F)
// First and last contiguous values
void nFirstElem(std::span<int> val, int N)
{
    std::span<const int, std::dynamic_extent> span_first = val.first(N);

    for (auto const& elem : span_first)
        std::cout << elem << ",";
    std::cout << '\n';
}

void nLastElem(std::span<int> val, int N)
{
    std::span<const int, std::dynamic_extent> span_last = val.last(N);

    for (auto const& elem : span_last) // 3,4,5,6, -9
        std::cout << elem << ",";
    std::cout << '\n';
}

// testing subspan (1H)
void testSubspan(std::span<int> val, int iter1, int iter2)
{
    auto spanOut = val.subspan(iter1, iter2);

    for (auto const& elem : spanOut) // 3,4,5,6, -9
        std::cout << elem << ",";
    std::cout << '\n';

}



int main()
{
    // Declaring Tuple 
    // Person with: Name, Adress, and date of birth (1A)
    std::tuple <std::string, std::string, boost::gregorian::date> Person;

    // Declaring tupple (1A)
    Person = std::make_tuple("John Doe", "800 NiceStreet Street", boost::gregorian::date{ 1980, 1, 31 });


    // Printing Tuple (1B)
    print(Person);

    // Vector of people (1C)
    std::vector<std::tuple <std::string, std::string, boost::gregorian::date>> manyPeople;
    manyPeople.push_back(std::make_tuple("Good Guy", "800 NiceStreet Street", boost::gregorian::date{ 1980, 1, 31 }));
    manyPeople.push_back(std::make_tuple("Bad Guy", "800 BadStreet Street", boost::gregorian::date{ 1970, 1, 31 }));

    // Sorting tuples (1D) 
    sort(manyPeople.begin(), manyPeople.end(), sortTuple);

    // Byte Work 
    // ** To DO ** Maybe give brief description here 
    // Not really sure if filling the requirement: re-read (https://quantnet.com/threads/1-5-1-i-%E2%80%9Cbyte-views-of-spans.49689/)
    float data[1]{ 3.141592f };

    auto const const_bytes = std::as_bytes(std::span{ data });

    for (auto const b : const_bytes)
    {
        std::cout << std::setw(2)
            << std::hex
            << std::uppercase
            << std::setfill('0')
            << std::to_integer<int>(b) << ' ';
    }


}