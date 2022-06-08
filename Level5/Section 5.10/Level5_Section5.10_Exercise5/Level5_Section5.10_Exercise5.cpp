// Level5_Section5.10_Exercise5.cpp 
// Fiona Ross 
// Unified Vector Interface using Template Template Parameters

#include <iostream>
#include <tuple>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

// Pulled from Homework 
template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
void print(const std::string& comment, const Container<T, TAlloc>& container) {
  // A generic print function for general containers
  std::cout << comment << ": ";

  // We use lambda for readability
  // a. iterators
  auto f = [](const T& t) { std::cout << t << ", "; };
  std::for_each(container.begin(), container.end(), f);
  std::cout << std::endl;

  std::cout << std::endl;
}



using namespace boost::numeric::ublas; //this is the main difference because now we use ublas vectors & stl vectors 

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

void print(Result r) {
  auto range = std::get<0>(r);
  std::cout << "Range " << std::get<0>(range) << ", " << std::get<1>(range)
            << "\n";
  std::cout << "Success: " << std::get<1>(r) << std::endl;
};

// Part A:
// Using ublas & std::find 
template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
Result find_sequential_greater(const Container<T, TAlloc>& v, T x) {
  auto it = std::find_if(v.begin(), v.end(), [&](const T& el) {
    auto it = &el;
    it++;
    return (el <= x && *it > x);
  });  // make lambda function that compares value to current element and next
  if (it != std::end(v)) {
    auto ind = std::distance(v.begin(), it);
    return std::make_tuple(std::make_tuple(ind, ind + 1), true);
  };
  return std::make_tuple(std::make_tuple(999, 999), false);
}

// Part A: 
// gets index to corresponding value 
template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
int findIndex(const Container<T, TAlloc>& v, T x) {
  auto it = std::find(v.begin(), v.end(), x);
  return std::distance(v.begin(), it);
}

// Part B
// function that is now more generic 
template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
Result find_sequential_greater_lower(const Container<T, TAlloc>& v, T x) {
  auto lowIt = std::lower_bound(v.begin(), v.end(),
                                x);  // same steps are followed as above
  int lowInd = std::distance(v.begin(), lowIt);
  std::cout << "lower index" << lowInd << std::endl;
  if (lowIt != v.end()) {
    if (v[lowInd] == x && v[lowInd + 1] > x) {
      return std::make_tuple(std::make_tuple(lowInd, lowInd + 1), true);
    } else {
      return std::make_tuple(std::make_tuple(lowInd - 1, lowInd), true);
    };
  }
  return std::make_tuple(std::make_tuple(999, 999), false);
}

template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
Result find_sequential_greater_upper(const Container<T, TAlloc>& v, T x) {
  auto highIt =
      std::upper_bound(v.begin(), v.end(), x);  // same steps followed as above
  int highInd = std::distance(v.begin(), highIt);
  std::cout << "higher index" << highInd << std::endl;
  if (highIt != v.end()) {
    if (v[highInd - 1] <= x) {
      return std::make_tuple(std::make_tuple(highInd - 1, highInd), true);
    };
  };
  return std::make_tuple(std::make_tuple(999, 999), false);
}

// Part C
// function is now more generic 
template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
Result find_sequential_greater_range(const Container<T, TAlloc>& v, T x) {
  auto pair1 = std::equal_range(v.begin(), v.end(), x);  // perform operation
  int highInd = std::distance(v.begin(), pair1.second);  // get index
  if (pair1.second != v.end()) {  // check if stl function found a value
    if (v[highInd - 1] <= x) {  // check if prior value is less than target val
      return std::make_tuple(std::make_tuple(highInd - 1, highInd),
                             true);  // make output
    };
  };
  return std::make_tuple(std::make_tuple(999, 999), false);
}

// Part D 
// More generic 
bool isOdd(int d) {
  if (d % 2 == 1) return true;
  return false;
}

// Part D wrapper:
template <typename T, template <typename S, typename Alloc> class Container,
          typename TAlloc>
Result test_find_if_not(const Container<T, TAlloc>& v) {
  auto it = std::find_if_not(v.begin(), v.end(), isOdd);  // get first odd
  int ind = std::distance(v.begin(), it);
  if (it != v.end()) {
    return std::make_tuple(std::make_tuple(ind, ind),
                           true);  // return first even value index
  };
  return std::make_tuple(std::make_tuple(999, 999), false);
}

int main()
{
  // Running and Testing Functions here
  // ublas vector 
  vector<int> vec1(8);
  for (int i = 0; i < vec1.size(); i++) {
    vec1(i) = i * i;
  }

  // boost vector 
  std::vector<int> vec2 = {0, 1, 4, 9, 16, 25, 36, 49};

  std::cout << "Given Function:" << std::endl;
  Result out1 = find_sequential_greater(vec1, 1);  // Part A:
  Result out1b = find_sequential_greater(vec2, 1);  // Part A:
  print(out1);
  print(out1b);

  std::cout << "Part A, Index Function:" << std::endl;
  int indx1 = findIndex(vec1, 1);  // Part A:
  int indx1b = findIndex(vec2, 1);  // Part A:
  std::cout << indx1 << std::endl;
  std::cout << indx1b << std::endl;

  std::cout << "Part B:" << std::endl;
  Result out2 = find_sequential_greater_lower(vec1, 1);  // Part A:
  Result out2b = find_sequential_greater_lower(vec2, 1);  // Part A:
  print(out2);
  print(out2b);

  std::cout << "Part C:" << std::endl;
  Result out3 = find_sequential_greater_upper(vec1, 1);  // Part A:
  Result out3b = find_sequential_greater_upper(vec2, 1);  // Part A:
  print(out3);
  print(out3b);

  std::cout << "Part D:" << std::endl;
  Result out4 = test_find_if_not(vec1);  // Part A:
  Result out4b = test_find_if_not(vec2);  // Part A:
  print(out4);
  print(out4b);
}

