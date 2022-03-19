// Level2_Section2.7_Exercise4.cpp 
// Error Code Fundamentals for platform dependent code 

#include <iostream>
#include <tuple>
#include <cmath>

void printTuple(std::tuple<std::string, int, std::string> input)
{
    std::cout << "\nError Message is: " << std::get<0>(input) << std::endl;
    std::cout << "Error Code is: " << std::get<1>(input) << std::endl;
    std::cout << "Error Category Name is: " << std::get<2>(input) << std::endl;
    return;
}

std::tuple<std::string, int, std::string> errCode(std::error_condition ec)
{
    std::tuple<std::string, int, std::string> tup;

    //Assign message and value
    std::get<0>(tup) = ec.message();

    // Assign Error value / code 
    std::get<1>(tup) = ec.value();

    // Assign name of the category
    std::get<2>(tup) = static_cast<std::string>(ec.category().name());
    
    // Priting tuple contents
    printTuple(tup);

    // returning tuple
    return tup;
    //return std::make_tuple(ec.message(), ec.value(), ec.category().name());
}

int main()
{
    // Part A: 
    auto err_code1 = std::error_code(0, std::system_category()); //Default error code 
    std::error_condition err_code_in = std::system_category().default_error_condition(EDOM);
    auto err_code2 = std::error_code(EDOM, err_code_in.category()); //Error code with platform-dependent code value and an error cateogry



	// Part B: 

	errno = 0; 
	std::sqrt(-1);  //errno set to EDOM
	std::error_condition ec(errno, std::generic_category()); //returns error category
    auto error_output = errCode(ec);

    // Part C: 
    std::cout << "Default error code is equal platform-dependent code: " << (err_code1 == err_code2) << std::endl;
    std::cout << "Default error code is not equal platform-dependent error condition: " << (err_code1 != err_code2) << std::endl;
    std::cout << "Platform dependent condition is equal to platform dependent error code: " << (err_code_in == err_code2);

}


