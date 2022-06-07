// Level5_Section5.2_Exercise3.cpp
// Fiona Ross 
// Regex Iterators 

#include <iostream>
#include <string>
#include <regex>
#include <set>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>


int main() {
  // generating inputs
  std::string S2 = "1,1,2,3,5,8,13,21";
  std::regex myReg("(\\d+),?");

  // Part A:
  // instance of sregex_iterator based on S2 and myReg
  auto it_begin = std::sregex_iterator(S2.begin(), S2.end(), myReg);
  auto it_end = std::sregex_iterator();

  // Part B:
  // iterate over and convert dereferenced values and insert into output
  for (std::sregex_iterator i = it_begin; i != it_end; ++i) {
    std::smatch match = *i;               // dereference
    std::string match_out = match.str();  // insert into output result
    std::cout << match_out << std::endl;  // incorporating print here in loop
                                          // but could do a seperate function
  }

  // Part C: (look above at print in the loop)

  // Part D:
  // Modify the code so that the output is of type std::set<int>.
  std::set<int> set_match_out;
  for (std::sregex_iterator i = it_begin; i != it_end; ++i) {
    std::smatch match = *i;                  // dereference
    std::string match_out = match.str();  // insert into output result
    int match_num = std::stoi(match_out);
    set_match_out.insert(match_num);  // extra set of adding to set 
  }


}

