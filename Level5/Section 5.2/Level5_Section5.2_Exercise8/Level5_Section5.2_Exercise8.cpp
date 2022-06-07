// Level5_Section5.2_Exercise8.cpp
// Fiona Ross 
// Time Series Data 

#include <iostream>
#include <fstream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <vector>
//#include <boost/regex.hpp>
#include <list>
#include <regex>

// Pulling code from 5.1.4 and then transforming it so it works 
// with regex ... essentially replacing std::string with std::regex

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

// pulled the date conversion from the previous exercise and putting it in as a
// function
boost::gregorian::date changeDate(std::string bdate) {
  return boost::gregorian::from_string(bdate);
}

ResultSet inportData(std::string inputData) {
  // open file
  std::ifstream input(inputData.c_str());

  // initialize output
  ResultSet output;

  // make row data & exclude headers
  Data row_data;

  std::string row_string;
  std::getline(input, row_string);

  // iterate through each row splitting up strings, loading data and data
  // changes this time using regex 
  while (std::getline(input, row_string)) {
    std::vector<std::string> strVec;
    
    // what we are looking for 
    // sregex_token_iterator is : a read-only LegacyForwardIterator that accesses the individual sub-matches of every match of a regular expression within the underlying character sequence
    std::regex delim(",");
    std::copy(std::sregex_token_iterator(row_string.begin(), row_string.end(),
                                        delim, -1),
              std::sregex_token_iterator(), std::back_inserter(strVec));
    
    changeDate(strVec[0]);

    // conversion to double
    for (int i = 1; i < strVec.size(); i++) {
      std::get<1>(row_data).push_back(boost::lexical_cast<double>(
          strVec[i]));  // convert each remaining element to double and add
                        // to vector
    }

    // add the new data row to output
    output.push_back(row_data);
  }
  return output;
}

int main() {

  // get the same output as 5.1.4 so believe it was a sucess! 

  ResultSet loadedData = inportData("local.csv");
  std::vector<double> row1 = std::get<1>(loadedData.front());

  // printing results for verification
  for (auto el : row1) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}
