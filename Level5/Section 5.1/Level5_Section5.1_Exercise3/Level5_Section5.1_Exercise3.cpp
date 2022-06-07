// Level5_Section5.1_Exercise3.cpp
// Fiona Ross 
// Splitting and Joining Strings 

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"

std::map<std::string, double> nameMap(std::string input) {
    // Not sure how to delimit the string since could be so many options 
    // so assuming string already has been delimited 
    // erasing spaces 
    boost::erase_all(input, " ");

    // We know the port, pin & value come after the "=" sign so use that as delimiter 
    std::vector<std::string> parsedVec; 
    boost::split(parsedVec, input,
                 boost::is_any_of(",="));  
    
    std::map<std::string, double> outMap; // outputted map 

    for (int i = 0; i < parsedVec.size();
         i++) {  // iterate through vector and add keys/values to map
      if (boost::all(parsedVec[i], (boost::is_lower() || boost::is_upper()))) {
        outMap[parsedVec[i]];
      } else {
        outMap[parsedVec[i - 1]] = boost::lexical_cast<double>(parsedVec[i]);
      }
    }
    return outMap;
}

int main()
{
    // Part A: 
    // Desired output = sA("1/2/3/4/5/9/56")
    // setting up string input  
    std::string sA("1,2,3,4/5/9*56");

    // in order to join strings using '/' as a deliminator need to split them up first 
    std::vector<std::string> strVec; 
    // splits strings and inserts them into vector 
    boost::split(strVec, sA, boost::is_any_of("/,*")); 
    
    // could have made this a print function
    for (std::string elem : strVec) {
      std::cout << elem << std::endl; 
    }

    // joining individual vectors of strings using '/'
    auto outStr = boost::join(strVec, "/"); 

    // printed output looks good 
    std::cout << outStr << std::endl; 
    

    //Part B: Converting String to Boost Date 
    std::string bdate("2015 - 12 - 31");
    boost::gregorian::date toDate;
    toDate = boost::gregorian::from_string(bdate);
    std::cout << toDate << std::endl; 

    // Part C: STring pairs and key 
    std::string mapInput("port = 23, pin = 87, value = 34.4");
    std::map<std::string, double> mapOut = nameMap(mapInput);
    
    // could have made this a print function 
    std::cout << "port: " << mapOut["port"]
              << std::endl;  // print out values using key for each element
    std::cout << "pin: " << mapOut["pin"] << std::endl;
    std::cout << "value: " << mapOut["value"] << std::endl;

}

