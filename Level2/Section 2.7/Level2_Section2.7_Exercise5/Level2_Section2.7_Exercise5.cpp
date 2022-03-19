// Level2_Section2.7_Exercise5.cpp 
/*
Fiona Ross - 03-12-2022
Catching Exceptions 
Need to catch a simulated exception thrown when setting the exception mask
of an input file stream 
*/
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <boost/system/error_code.hpp>
#include <boost/system/windows_error.hpp>
#include <tuple>

void printTuple(std::tuple<std::string, int, std::string> input)
{
    std::cout << "\nError Message is: " << std::get<0>(input) << std::endl;
    std::cout << "Error Code is: " << std::get<1>(input) << std::endl;
    std::cout << "Error Category Name is: " << std::get<2>(input) << std::endl;
    return;
}

std::tuple<std::string, int, std::string> error_condition_info(std::error_code ec)
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
    std::ifstream file(std::string("DOESNOTEXIST.txt"));
    try
    {
        // Set the exception mask of the file stream
        // In this case 1) logical error on I/O operation or
        // 2) read/write error on I/O operation
        file.exceptions(file.failbit | file.badbit);
    }
    catch (const std::ios_base::failure& e)
    {
        // catch an error code instance ec1 with e.code()
        if (e.code() == std::io_errc::stream) 
        {
            std::error_code ec1 = std::error_code(e.code()); //error code with e.code as argument
            std::error_code ec2(ec1); // create an error condition ec2 instance with ec1 as argument 
            std::tuple<std::string, int, std::string> output = error_condition_info(ec2); // print the properties value, messsage and error category of ec2
        }

    }
    catch (...)
    {
        std::cout << "catch all\n";
    }
}
