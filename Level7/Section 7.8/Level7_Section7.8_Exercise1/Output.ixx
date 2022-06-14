#include <string>
#include <iostream>

export module Output;

// The output module takes what the user inputed. 
// the input goes through the processing module 
// Then it gets outputted to the user

export void out(const std::string& s) {
	std::cout << "Printing output: " << s << std::endl;
};