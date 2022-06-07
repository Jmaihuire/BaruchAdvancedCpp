// Level5_Section5.2_Exercise1.cpp 
// Fiona Ross 
// Regex 101

#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>


int main() {
  // Part A
  // Setting up Examples
  boost::regex myReg("[a-z]*");  //
  boost::regex myReg2("[a-z]+");

  std::string s1("aza");
  std::string s2("1");
  std::string s3("b");
  std::string s4("ZZ TOP");

  std::cout << s1 << ", " << boost::regex_match(s1, myReg)
            << std::endl;  // true because in range
  std::cout << s2 << ", " << boost::regex_match(s2, myReg)
            << std::endl;  // false because 1 out of range
  std::cout << s3 << ", " << boost::regex_match(s3, myReg)
            << std::endl;  // true
  std::cout << s4 << ", " << boost::regex_match(s4, myReg2)
            << std::endl;  // false...most likely spaces

  // Part B:
  boost::regex myNumericReg("\\d{2}");
  std::string f("34");
  std::string s("345");

  std::cout << f << ", " << boost::regex_match(f, myNumericReg)
            << std::endl;  // true since digits in the overall string
  std::cout << s << ", " << boost::regex_match(s, myNumericReg)
            << std::endl;  // false since more than 2 digits in string

  // Part C:
  boost::regex myAltReg("(new)|(delete)");
  std::string s4A("new");
  std::string s5("delete");
  std::string s6("malloc");

  std::cout << s4A << ", " << boost::regex_match(s4A, myAltReg)
            << std::endl;  // true because string is "new"
  std::cout << s5 << ", " << boost::regex_match(s5, myAltReg)
            << std::endl;  // true because string is "delete"
  std::cout << s6 << ", " << boost::regex_match(s6, myAltReg)
            << std::endl;  // false no new or delete

  // Part D:
  boost::regex myReg3("A*");
  boost::regex myReg4("A+");
  boost::regex myReg5("(\\d{2})");
  boost::regex myReg6("\\d{2, 4}");  // not sure why this was commented out
  boost::regex myReg7("\\d{1,}");

  std::string testA("1");

  std::cout << testA << ", " << boost::regex_match(testA, myReg3)
            << std::endl;  // false bc 1 not A
  std::cout << testA << ", " << boost::regex_match(testA, myReg4)
            << std::endl;  // false bc 1 not A
  std::cout << testA << ", " << boost::regex_match(testA, myReg5)
            << std::endl;  // false because only one digit
  std::cout << testA << ", " << boost::regex_match(testA, myReg6)
            << std::endl;  // false bc only one digit
  std::cout << testA << ", " << boost::regex_match(testA, myReg7)
            << std::endl;  // true bc one digit

  // Part E:
  std::cout << std::endl;
  boost::regex rC("(\\w)*");          // Alphanumeric (word) A-Za-z0-9
  boost::regex rC1("(\\W)*");         // Not a word
  boost::regex rC2("[A-Za-z0-9_]*");  // Alphanumeric (word) A-Za-z0-9

  std::string sC1("abc");
  std::string sC2("A12678Z909za");
  std::string sC2("A12678Z909za");
  std::string sC3("A12678  Z909za");  // added a space
  std::string sC4("abc !!!>?? ");     // added symbols

  std::cout << sC1 << ", " << boost::regex_match(sC1, rC)
            << std::endl;  // check if string is word
  std::cout
      << sC1 << ", " << boost::regex_match(sC1, rC2)
      << std::endl;  // check if string is word with different regex expression
  std::cout << sC2 << ", " << boost::regex_match(sC2, rC2)
            << std::endl;  // check if string is word
  std::cout << sC3 << ", " << boost::regex_match(sC3, rC)
            << std::endl;  // not a word bc of space
  std::cout << sC4 << ", " << boost::regex_match(sC4, rC1)
            << std::endl;  // true because not alnum

  // A few ECMA examples
  boost::regex rE("DEF.!");  // letters and a symbol
  std::string sE("ABC12");   // this should match
  std::cout << sE << ", " << boost::regex_match(sE, rE) << std::endl;


}

