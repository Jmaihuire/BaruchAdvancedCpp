// Level5_Section5.2_Exercise2.cpp 
// Fiona Ross
// Seaching / Regex_search()

#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>


int main()
{
  boost::regex mySearchReg("(rain)|(Spain)"); // example substring that we are searching for 

  std::string myText(
      "The rain in Spain stays mainly on the plain");  // target string

  boost::smatch result;  
  std::cout << "matched? " << boost::regex_search(myText, result, mySearchReg)
            << std::endl;
  std::cout << "Result = " << result[0] << std::endl;

}
