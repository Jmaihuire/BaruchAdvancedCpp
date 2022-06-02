// Level5_Section5.1_Exercise1.cpp 
// Fiona Ross 
// String Algorithm - Preprocessing Functions 

#include <iostream>
#include <boost/algorithm/string.hpp>

// defining trimming predicate 
bool isAAA(char c) { return c == 'A'; }

int main()
{
    // generating example strings for with leading & trailing blanks
  std::string s1 = "    in the woods   ";
    std::string s2 = "      canoe";
    std::string s3 = "55canadian wilderness      "; 
    std::string s4 = "AAA is really ehhhhh  ";

    // Part A:
    // modifying the input string 
    boost::trim(s1);  // this function trims leading and trailing blanks
    std::cout << s1 << std::endl;
    // copying the input string 
    auto s2_copy = boost::trim_copy(s2);
    std::cout << s2_copy << std::endl;  // copy of the input string

    // Part B: 
    // Trimming based on differnt predicates 
    std::cout << s4 << std::endl; 

    // both of these options work but cannot have spaces before the "AAA" meaning 
    // it can be "AAA is real ehhh   " not "     AAA is real ehhh  "

    boost::trim_if(s4, &isAAA); //trimming if string contains AAA (didnt work)
    std::cout << s4 << std::endl; 

    boost::trim_if(s4, boost::is_any_of("A")); //this will trim leading AAA
    std::cout << s4 << std::endl; 

    // Part C: 
    // with numbers case sensitive doesn't matter 
    std::cout << boost::starts_with(s3, "55") << std::endl;  // true

    // here case sensitive does matter so will return false 
    std::cout << boost::ends_with(s4, "aaa")
              << std::endl;  // false bc case sensitive

    // this is case insensitive so returns true 
    std::cout << boost::iends_with(s2, "NOE")
              << std::endl;  // true bc case insensitive

    // Part D: Testing substrings 
    // Contains case sensitive 
    std::cout << boost::contains(s1, "woo") << std::endl;  // true
    std::cout << boost::contains(s2, "NOE") 
              << std::endl;  // false bc case sensitive
    std::cout << boost::icontains(s2, "NOE")
              << std::endl;  // true bc case insensitive
    std::cout << boost::equals(s4, "aaa is really ehhhhh  ")
              << std::endl;  // false bc case sensitive

}

