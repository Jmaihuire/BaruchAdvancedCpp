// Level2_Section2.7_Exercise1.cpp 
/*
Fiona Ross - 03-06-2022
defining (platform-independent) error conditions 
and (platform-dependent) error codes
*/

#include <iostream>
#include <system_error>
#include <string>
#include <fstream>
#include <boost/system/error_code.hpp>

// Part A: 
// Write the code and test it using an existing file as input. 
// The return type is boost::system::error condition.


boost::system::error_condition ReadFile(std::string file)
{
	// Open File
	std::ifstream in(file.c_str());

	// Return error condition if opening failed 
	if (!in.is_open()) return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);

	// if (!in.is_open())
	// { return error_condition(errc::no_such_file_or_directory, generic_category()) }

	// Print File 
	std::cout << in.rdbuf() << std::endl;

	// Close File
	in.close();

	// Return "No Error"
	return boost::system::error_condition();
}

std::error_condition ReadFile_c11(std::string file)
{
	// Open File
	std::ifstream in(file.c_str());

	// Return error condition if opening failed 
	if (!in.is_open()) return std::make_error_condition(std::errc::no_such_file_or_directory);

	// Print File 
	std::cout << in.rdbuf() << std::endl;

	// Close File
	in.close();

	// Return "No Error"
	return std::error_condition();
}


int main()
{ 
	// Part A: 
	std::string file1("C:\\Users\\DualInc\\Desktop\\textFile.txt");
	std::string file2("No File");

	std::cout << std::endl << "Opening: " << file1 << std::endl;
	std::cout << "Error condition 1: " << ReadFile(file1).message() << std::endl;

	// Part B: 
	std::cout << std::endl << "Opening: " << file2 << std::endl;
	std::cout << "Error condition 2: " << ReadFile(file2).message() << std::endl;


	// Part D: 

	std::string file3("C:\\Users\\DualInc\\Desktop\\textFile.txt");
	std::string file4("No File");

	std::cout << std::endl << "Opening: " << file3 << std::endl;
	std::cout << "Error condition 1: " << ReadFile_c11(file3).message() << std::endl;
 
	std::cout << std::endl << "Opening: " << file4 << std::endl;
	std::cout << "Error condition 2: " << ReadFile_c11(file4).message() << std::endl;

	return 0; 
}

