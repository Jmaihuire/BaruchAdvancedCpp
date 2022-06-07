// Level5_Section5.2_Exercise6.cpp 
// Fiona Ross 
// ECMAS Grammer 

#include <iostream>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <sstream>


double toDouble(std::string s, std::regex ecmaReg) 
{
  double d_out = -INFINITY; 
  if (std::regex_match(s, ecmaReg)) {
    d_out = std::stod(s);
    std::cout << s << " converted to double : " << d_out << std::endl; 
  } 
  else {
    std::cout << "string input does not match regex, cannot convert to double"
              << std::endl;
  }
  return (d_out);
}



int main()
{

  // Part A: 
  // the expression takes in scientific notation 
  std::regex ecmaReg(
      "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]"
      "+)?");



  // Part B: 
  // Creating test cases 
  std::string str1 = "+3.3e-4";  // this should be true since scientific and contains all appropriate symbols
  std::string str2 = "34";  // think this will be true since still appropriate values 
  std::string str3 = "-3.4E+1";  // true 
  std::string str4 = "1.3*10^12";   // should be false even though scientific notation wrong symbols

  std::cout << str1 << ", " << std::regex_match(str1, ecmaReg) << std::endl;
  std::cout << str2 << ", " << std::regex_match(str2, ecmaReg) << std::endl;
  std::cout << str3 << ", " << std::regex_match(str3, ecmaReg) << std::endl;
  std::cout << str4 << ", " << std::fixed << std::regex_match(str4, ecmaReg)
            << std::endl;

	

  // Part C: 
  double d1 = toDouble(str1, ecmaReg);
  double d2 = toDouble(str2, ecmaReg);
  double d3 = toDouble(str3, ecmaReg);
  double d4 = toDouble(str4, ecmaReg);
 
}

