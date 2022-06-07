// Level5_Section5.2_Exercise4.cpp 
// Fiona Ross 
// Token Iterator 

#include <iostream>
#include <regex>
#include <boost/algorithm/string.hpp>


int main()
{
  // construct provided examples 
  std::regex myReg10("/");
  std::string S3 = "2016/3/15";

  // Extract data 
  std::vector<std::string> date;  // container to hold the date values
  std::copy(std::sregex_token_iterator(S3.begin(), S3.end(), myReg10, -1),
            std::sregex_token_iterator(), std::back_inserter(date));

  // printing results to check 
  for (auto el : date) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  // Part B: 
  // Parsing out deliminator '/'
  std::vector<std::string> delimiters;  // this will hold the deliminators
  
  // this parses them out 
  std::copy(std::sregex_token_iterator(S3.begin(), S3.end(), myReg10, 0),
            std::sregex_token_iterator(),
            std::ostream_iterator<std::string>(std::cout, " "));



}
