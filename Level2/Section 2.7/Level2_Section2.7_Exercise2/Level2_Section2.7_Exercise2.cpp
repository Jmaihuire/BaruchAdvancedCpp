// Level2_Section2.7_Exercise2.cpp : 
/*
Fiona Ross - 03-07-2022
Looking into std::error_condition fundamentals 
*/

#include <iostream>
#include <string>
#include <tuple>

void printTuple(std::tuple<std::string, int, std::string> input)
{
    std::cout << "\nError Message is: " << std::get<0>(input) << std::endl;
    std::cout << "Error Code is: " << std::get<1>(input) << std::endl;
    std::cout << "Error Category Name is: " << std::get<2>(input) << std::endl;
    return;
}

std::tuple<std::string, int, std::string> error_condition_info(std::error_condition ec)
{
    std::tuple<std::string, int, std::string> tup;

    // Assign message and value
    std::get<0>(tup) = ec.message();

    // Assign Error value / code 
    std::get<1>(tup) = ec.value();

    // Assign name of the category
    std::get<2>(tup) = static_cast<std::string>(ec.category().name());
    
    // Priting tuple contents
    printTuple(tup);

    // returning tuple
    return tup;
}


int main()
{
    // Part A: Taken from lecture example 
    // Default Constructor 
    std::cout << "The default error condition: " << std::endl;
    std::cout << std::error_condition().message() << '\n \n';
    
    // Value & Error Category 
    std::cout << "Some generic error conditions by value: \n";
    for (int i = 0; i < 10; ++i)
    {
        std::error_condition c(i, std::generic_category());
        std::cout << "\t#" << i << " : " << c.message() << '\n';
    }

    // std::errc code 
    std::cout << "A condition constructed from errc: " << std::endl;
    std::cout << std::error_condition(std::errc::permission_denied).message();

    // Part B: 
    // Creating Tuple for error 
    std::error_condition ec;
    std::tuple<std::string, int, std::string> output = error_condition_info(ec);
    // prints a tuple that has 
    // Error Code: 0
    // Error Message: unknown error 
    // Error Name: generic 
}

