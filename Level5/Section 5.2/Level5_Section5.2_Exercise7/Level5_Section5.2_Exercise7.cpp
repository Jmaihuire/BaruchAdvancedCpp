// Level5_Section5.2_Exercise7.cpp 
// Fiona Ross 
// Replacing Regular Expressions 

#include <iostream>
#include <regex>
#include <boost/algorithm/string.hpp>

int main() {
  // example data
  std::string text("Quick brown fox");
  std::regex vowels("a|e|i|o|u");

  // use std::regex_replace to make Q**ck br*wn f*x :
  // ie we are esentially taking out vowels and replacing them with * 
  auto textOut = std::regex_replace(text, vowels, "*");

  // result
  std::cout << textOut;
}


