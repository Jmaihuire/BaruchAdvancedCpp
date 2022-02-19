// Level2_Section2.3_Exercise2.cpp :
/* 
Using init Captures to move Objects into Closures
 copying objects into the closure can lead to performance hits 
 capture-by-reference can lead to dangling pointers F
 These two capture modes do not work with move-only objects 
 (for example, std::unique_ptr or std::future). 

*/

#include <iostream>
#include <vector>
#include <functional>
#include <array>

int main()
{
    int size = 4; double val = 2.71;
    std::vector<double> data(size, val);

    // Default capture mode (not preferred)
    auto fun = [&data]() mutable
    {
        for (std::size_t i = 0; i < data.size(); ++i)
        {
            data[i] = 3.14; std::cout << data[i] << ",";
        }
        std::cout << '\n';
    };

    fun();

    // Part A: Using move semantics so vector data is moved into lambda function  
    auto fun2 = [data = std::move(data)]() mutable
    {
        for (std::size_t i = 0; i < data.size(); i++)
        {
            data[i] = 5.2 ; std::wcout << data[i] << ": ";
        }
        std::wcout << "\n";
    };

    fun2();
    std::cout << "data size is now: " << data.size() << std::endl; 

    // 'data' still exists and has been modified
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        data[i] = 3.14; std::cout << data[i] << ":";
    }

    // Part B: 
    // C++14 init capture with local variables
    int x = 1'000'000; // This is a digit separator
    auto fun4 = [&r = x]()
    {
        r *= 2;
        std::cout << "\nr: " << r;
    };
    fun4(); // output is r: 2000000 

    // Part C: Migrate the following C++11 code that uses std::bind
    // to emulate C++14 code that uses init capture:

    // Emulating generalized lambda capture with C++11
    int size2 = 3; double val2 = 1.41;
    std::vector<double> data2(size2, val2);
    std::array<double, 3> data3 = { 1.2, 2.4, 4.7 };
    auto fun3 = std::bind([](std::vector<double>& array,
        std::array<double, 3> array2)
        {
            for (std::size_t i = 0; i < array.size(); ++i)
            {
                array[i] = 3.14; std::cout << array[i] << "/";
            }
            std::cout << '\n';
            for (std::size_t i = 0; i < array2.size(); ++i)
            {
                array2[i] = 2.71; std::cout << array2[i] << "/";
            }

        }, std::move(data2), std::move(data3));

    fun3();

    auto fun5 = [array = std::move(data2), array2 = std::move(data3)] () mutable
    {
        for (std::size_t i = 0; i < array.size(); ++i)
        {
            array[i] = 3.14; std::cout << array[i] << "/";
        }
        std::cout << '\n';
        for (std::size_t i = 0; i < array2.size(); ++i)
        {
            array2[i] = 2.71; std::cout << array2[i] << "/";
        }

    };

    fun5();

    if (0 == data2.size() || 0 == data3.size())
    {
        std::cout << "\nDouble arrays have no elements, OK\n";
    }
    else
    {
        std::cout << "\n Ouch!\n";
        for (std::size_t i = 0; i < data2.size(); ++i)
        {
            std::cout << "Vectors with doubles: " << std::endl; 
            std::cout << data2[i] << "^";
        }
        for (std::size_t i = 0; i < data3.size(); ++i)
        {
            std::cout << " Array with doubles: " << std::endl; 
            std::cout << data3[i] << "^";
        }
    }
}


