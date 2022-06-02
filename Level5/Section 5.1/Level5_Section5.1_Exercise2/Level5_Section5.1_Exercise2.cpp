// Level5_Section5.1_Exercise2.cpp 
// Fiona Ross 
// Classification 

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <tuple>

// Part B: Password checking function...making it a tuple since want to return 
// boolean and the string 
std::tuple<bool, std::string> checkPassword(std::string input) {
	// no spaces allowed 
	if (boost::contains(input, " ")) {
          // cannot contain spaces
          return std::make_tuple(false, "No spaces allowed");
        }

	auto numchar =
            boost::trim_copy_if(input, !(boost::is_upper() || boost::is_lower()));
	// must contain at least 8 characters 
	if (numchar.size() < 8) {
          // check if string contains at least 8 characters
          return std::make_tuple(false,
                                 "Pwd must contain at least 8 characters");
        }

	// must contian a combination of digits and characters 
	else if (boost::all(input, !boost::is_digit())) {
          // check if string contains digits and characters (since we already
          // checked # characters we can just check if there are any digits
          return std::make_tuple(
              false, "Need both digits and characters");
        } 

	// at least one character uppercase 
    else if (boost::all(input, !boost::is_upper())) {
          // check if one character is upper case
          return std::make_tuple(false, "Need one upper case character");
        }

	// no control characters allowed 
    else if (boost::all(input, boost::is_any_of("\*"))) {
          // no control characters allowed
          return std::make_tuple(false,
                                 "No control characters allowed");
        }

    else {
          return std::make_tuple(true, "Password is good");
        }

}

int main()
{
   // Make Example Strings 
	std::string str1(" abd1 234\*");
	std::string s1 = "   into the woods   "; 
	std::string s2 = "55canada   "; 
	std::string s3 = "AAA is not ehhh   ";

	// Part A: 
	// recognize digits or letters
        std::cout << boost::all(str1, (boost::is_alnum())) << std::endl; 

	// recognize digits not letters 
	std::cout << boost::all(str1,(boost::is_digit() && !(boost::is_lower()))); 

    // Recognize charachters from the range [a z]
    std::cout<< boost::all(str1, boost::is_lower()) << std::endl; 

	// Part B: Password checker
    std::string pwd1("DanielDuffy1952");
    std::string pwd2("DanielDuffy");
    std::string pwd3("U19520829");
    std::string pwd4("19520829U");

    // check pwds
    auto check1 = checkPassword(pwd1);  // true
    auto check2 = checkPassword(pwd2);  // false because no digits
    auto check3 = checkPassword(pwd3);  // false because not enough characters
    auto check4 = checkPassword(pwd4);  // false because not enough characters
    
    // print checks:
    std::cout << std::boolalpha << std::get<0>(check1) << ": "
              << std::get<1>(check1) << std::endl;
    std::cout << std::boolalpha << std::get<0>(check2) << ": "
              << std::get<1>(check2) << std::endl;
    std::cout << std::boolalpha << std::get<0>(check3) << ": "
              << std::get<1>(check3) << std::endl;
    std::cout << std::boolalpha << std::get<0>(check4) << ": "
              << std::get<1>(check4) << std::endl;
}	



