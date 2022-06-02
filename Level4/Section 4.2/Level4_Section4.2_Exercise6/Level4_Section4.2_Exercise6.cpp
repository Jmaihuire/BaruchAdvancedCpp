// Level4_Section4.2_Exercise6.cpp 
// Fiona Ross 
// Modifying the Elements of a Container 

#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"
#include <array>
#include <string>

// Using this to sort the Points by their X value 
bool sortcol(Point& p1, Point& p2) { return p1.X() > p2.X(); }

// removing duplicates 
std::vector<Point> remove_duplicates(std::vector<Point>& rawVec) {

  std::vector<Point> vcpc;  // output is a vector of points 

  std::sort(rawVec.begin(), rawVec.end(), sortcol);  // sort input vector

  double counter = 0; 
  // iterate through all x,y points 
  for (int i = 0; i < rawVec.size(); i++) {
    if (i + 1 == rawVec.size()) {
      vcpc.push_back(rawVec[i]);
    } else {
      // Compare X value to the X value to the point to the right 
      if (rawVec[i].X() != rawVec[i + 1].X() &&
          rawVec[i].Y() != rawVec[i+1].Y()) {
        vcpc.push_back(rawVec[i]);
      }
            else {
        std::cout << "this point already exists, excluding it" << std::endl;
      }
    }
  }
  return vcpc;
}

// removing max distance 
std::vector<Point> remove_maxdist(std::vector<Point>& rawVec, double maxDist) {
  std::vector<Point> vcpc;  // output is a vector of points
  Point p_compare(0,0);

  // iterate through all x,y points
  for (int i = 0; i < rawVec.size(); i++) {
    if (Point::distance(rawVec[i], p_compare) > maxDist) {
        vcpc.push_back(rawVec[i]);
      } else {
        std::cout << "this point does not meet max distance" << std::endl;
      }
  }
  return vcpc;
}


//Blank Space Trimming function 
const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s) {
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s) {
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s) { return rtrim(ltrim(s)); }

// Trimming based on unary input 
void trim_if(std::string& s, std::function<bool(char)> f) {
  std::string::iterator it = std::find_if(
      s.begin(), s.end(),
      f);  // get iterator for first instance of element meeting predicate
  while (
      it !=
      s.end()) {  // keep looping through in case there are trailing characters
    auto pos = std::remove(s.begin(), s.end(), *it);  // get positions to erase
    s.erase(pos, s.end());                            // erase from string
    it = std::find_if(it, s.end(), f);                // find next character
  }
}

// Combining strings (from online tutorial) 
std::vector<std::string> combine_strings(std::string s, std::string delimiter) {
  std::vector<std::string> chars;
  auto it = s.find(delimiter);  // find next delimiter position

  while (it != std::string::npos) {
    // keep looping through to find more cases
    std::string nextString = s.substr(0, it);
    s = s.substr(it + 1, s.size());  // remove first substrings + delimeter
    chars.push_back(nextString);
    it = s.find(delimiter);
  }
  // assuming the last term in delmited string will not have a trailing
  // delimeter so add it here
  std::string nextString = s.substr(0, it);
  s = s.substr(it + 1, s.size());  // remove first substrings + delimeter
  chars.push_back(nextString);
  return chars;
}


// joining strings
std::string join_strings(std::string s, std::string s2) { return s + s2; }

// including the usual print statements 
template <typename T>
void print(std::vector<T> v) {
  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

void print(std::string s) {
  for (auto el : s) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

void print(std::vector<Point> rawVec) {
  for (int i = 0; i < rawVec.size(); i++) {
    std::cout << "(" << rawVec[i].X() << ", " << rawVec[i].Y() << ")";
  }
  std::cout << std::endl;
}

template <int size>
void print(std::array<Point, size> p) {
  for (auto el : p) {
    el.print();
  }
  std::cout << std::endl;
}

int main()
{
  // Part A: 
  std::vector<char> S1 = {'a', 'b', 'c', 'd', 'e', 'k'};
  std::vector<char> S2 = {'a', 'e'};
  std::for_each(S2.begin(), S2.end(), [&](const char& c) {
    std::vector<char>::iterator pos = std::remove(S1.begin(), S1.end(), c);
    S1.erase(pos, S1.end());
  });
  print(S1);

  // Part B: Created class of Point 

  // Array of points (with duplicates)
  Point pt(2.0, 3.0);
  Point pt1(1.0, 4.0);
  Point pt2(10.0, 12.0);
  std::vector<Point> vecPt = {pt, pt, pt1, pt2, pt1, pt, pt2}; 

  // remove duplicates 
  std::vector<Point> no_duplicates = remove_duplicates(vecPt); 

  // checking that no duplicates slipped through 
  //print(no_duplicates);

  // Remove any point that doesn't meet max distance 
  double maxDist = 6.0;
  std::vector<Point> out_vec = remove_maxdist(no_duplicates, maxDist); 
  
  print(out_vec);

  // Part C:
  std::string s1 = "   22traveling nomad!  ";
  std::string sOut = trim(s1);
  print(sOut);

  trim_if(s1, [](unsigned char c) {
  return std::isdigit(c);
  });  // trim based on unary predicate - trimming the digits 
  std::cout << s1 << std::endl;
  std::string s2 = "parsing;out;key;words;test";
  auto string_vec = combine_strings(
      s2,
      ";");  // Produce a vector of strings from a character-separated string.
  print(string_vec);
  auto joined_strings = join_strings(s1, s2);  // Join two strings.
  std::cout << joined_strings;
}

