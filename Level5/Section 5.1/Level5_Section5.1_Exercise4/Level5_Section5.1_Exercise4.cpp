// Level5_Section5.1_Exercise4.cpp 
// Fiona Ross
// Time Series Data Mini Application 

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

// pulled the date conversion from the previous exercise and putting it in as a function 
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

    // iterate through each row splitting up strings, loading data and data changes
    while (std::getline(input, row_string)) {
      std::vector<std::string> strVec; 
      boost::split(strVec, row_string, boost::is_any_of(",")); //seperating using comma
      std::get<0>(row_data) = changeDate(strVec[0]); 

      // conversion to double 
      for (int i = 1; i < strVec.size(); i++) {
        std::get<1>(row_data).push_back(boost::lexical_cast<double>(strVec[i]));  // convert each remaining element to double and add
                          // to vector
      }

      // add the new data row to output 
      output.push_back(row_data); 
    }
    return output;
}

int main()
{
  ResultSet loadedData = inportData("local.csv");
  std::vector<double> row1 = std::get<1>(loadedData.front());
  
    // printing results for verification 
  for (auto el : row1) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

