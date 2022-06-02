// Level4_Section4.2_Exercise4.cpp 
// Fiona Ross 
// Non Modifying Algorithms 

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <functional>

// print functions
void print(std::list<int> list) {
  for (auto el : list) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}
void print(std::vector<int> v) {
  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

// Part B: Function to output min,max,sum, avg of vector
template <typename T>
std::tuple<T, T, T, T> compute_stats(std::vector<T> v) {
  T min = *std::min_element(v.begin(), v.end());
  T max = *std::max_element(v.begin(), v.end());
  T sum = std::accumulate(v.begin(), v.end(), 0.0);
  T avg = sum / v.size();
  return std::make_tuple(min, max, sum, avg);
}



int main()
{
  // Part A: 
  // Make some data
  std::vector<int> v1{1, 2,3, 4, 5, 4, 3,2,1};
  // Part A:
  // iterator through counting number of elements 
  std::list<std::list<int>> out1;
  for (int el : v1) {
    std::list<int> tempList = {el, int(std::count(v1.begin(), v1.end(), el))};
    if (std::find_if(out1.begin(), out1.end(), [=](std::list<int> l) {
          return std::equal(tempList.begin(), tempList.end(), l.begin());
        }) == out1.end()) {      // need to use std::equal here to compare lists
      out1.push_back(tempList);  // if the templist already exists in out list,
                                 // do not duplicate
    }
  }
  for (auto el : out1) {
    print(el);
  };
  std::cout << std::endl;

  // Part B: 
  std::vector<double> v2{2.2, 3.3, 4.4, 5.5};
  auto stats = compute_stats(v2);
  std::cout << "min " << std::get<0>(stats) << ", max " << std::get<1>(stats) << ", sum "
            << std::get<2>(stats) << ", avg " << std::get<3>(stats) << std::endl;

  // Part C: 
  using namespace std::placeholders;
  std::vector<int> vec = {20, 34, 12, -10, 14,14, 14, 89};
  std::cout << "First occurence of 5 at index: "
            << std::distance(vec.begin(), std::find(vec.begin(), vec.end(), 14))
            << std::endl;  // using stl

  // Requirements of using bind 
  std::cout << "First occurence of 5 at index: "
            << std::distance(
                   vec.begin(),
                   std::find_if(vec.begin(), vec.end(),
                                std::bind2nd(std::equal_to<int>(), 14)))
            << std::endl;  // use bind2nd
  std::cout << "First occurence of 5 at index: "
            << std::distance(
                   vec.begin(),
                   std::find_if(vec.begin(), vec.end(),
                                std::bind(std::equal_to<int>(), _1, 14)))
            << std::endl;  // use bind
  std::cout << "First occurence of 5 at index: "
            << std::distance(vec.begin(),
                             std::find_if(vec.begin(), vec.end(),
                                          [=](int a) { return (a == 14); }))
            << std::endl;  // use lambda

  // Part D: 
  std::vector<int> S2 = {1, 2, 5, 5, -3, 4, 5, 5, 5, 6, 3, 4, 5}; // provided vector 
  std::vector<int>::iterator pos1 = search_n(S2.begin(), S2.end(), 3, 5);
  
  // finding elements with 3 consecutive 5's 
  std::cout << "First 3 consecutive 5s are at index: "
            << std::distance(S2.begin(), pos1) << std::endl;

  // finding subvec 3,4,5
  std::vector<int> subrange = {3, 4, 5};  // subvec definitiion
  std::vector<int>::iterator pos2 = std::search(
      S2.begin(), S2.end(), subrange.begin(), subrange.end()); 

  // first subvec 
  std::cout << "First element of first subrange at index: "
            << std::distance(S2.begin(), pos2) << std::endl;

  // last subvec 
  std::vector<int>::iterator pos3 = std::find_end(
      S2.begin(), S2.end(), subrange.begin(), subrange.end());  // use find_end
  std::cout << "Last element of first subrange at index: "
            << std::distance(S2.begin(), pos3) << std::endl;

  // Part E
  std::vector<int> S3 = {1, 2, 5, 5, -3, 4, 5, 5, 5, 6, 3, 4, 5};
  
  // using adjacent find as per requirement
  auto itE = adjacent_find(
      S3.begin(),
      S3.end());  

  std::cout << "first element that has a value of the following element: "
            << std::distance(S3.begin(), itE) << std::endl;

  // Part F: 
  std::vector<int> S4 = {1, 2, 5, 5, -3, 4, 5, 5, 5, 6, 3, 4, 5};
  std::vector<int> s1 = {1, 2, 5};
  // seeing if smaller container has elements that are equal to larger container
  bool equal = std::equal(s1.begin(), s1.end(),
                          S4.begin());
  std::cout << "S1 subset equal to elements in s4? " << std::boolalpha << equal
            << std::endl;

}

