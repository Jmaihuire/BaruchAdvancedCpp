// Level2_Section2.7_Exercise3.cpp : 
/*
Fiona Ross - 03-07-2022
Portable Error Conditions corresponding to POSIX Error Codes 
*/
#include <iostream>

int main()
{
	//Part A:
	//Create error condition instances based on POSIX error codes, using scoped enumerator
	auto condition1 = std::error_condition(std::errc::io_error).message(); //io_error
	auto condition2 = std::error_condition(std::errc::network_unreachable).message(); //network_unreachable
	auto condition3 = std::error_condition(std::errc::no_such_file_or_directory).message(); //no_such_file_or_directory
	auto condition4 = std::error_condition(std::errc::not_a_socket).message(); //not_a_socket
	auto condition5 = std::error_condition(std::errc::permission_denied).message(); //permission_denied

	// Part B: 
	// Error condition based on value 128 and generic error category 
	std::error_condition condition6(128, std::generic_category()); //created an error for value 128 based on generic error category
	
	// Part C:
	// Error condition with std::io_ercc and std::_error_condition
	auto condition7 = std::make_error_condition(std::io_errc::stream);

	// Printing All 
	std::cout << " Io Error: " << condition1 << std::endl;
	std::cout << " Network Unreachable Error: " << condition2 << std::endl;
	std::cout << " No File / Directory Error: " << condition3 << std::endl;
	std::cout << " Not a Socket: " << condition4 << std::endl;
	std::cout << " Permission Denied: " << condition5 << std::endl;
	std::cout << " Value 128 Generic Error: " << condition6.message() << std::endl;
	std::cout << " IO ERRC: " << condition7.message() << std::endl;

}

