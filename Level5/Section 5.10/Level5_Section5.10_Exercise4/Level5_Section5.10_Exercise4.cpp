// Level5_Section5.10_Exercise4.cpp 
// Fiona Ross 
// 

#include <iostream>
#include <tuple>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

template <typename T, typename ValueType>
Result find_sequential_greater(const vector<T>& v, ValueType x) {
  for (std::size_t j = 0; j < v.size(); ++j) {
    if (v[j] <= x && v[j + 1] > x) {
      return std::make_tuple(std::make_tuple(j, j + 1), true);
    } else {
      return std::make_tuple(std::make_tuple(999, 999), false);
    };
  }
 }

// Part A: 
// Same functionality using std::find, std::distance(converting iterators to indexes)
template <typename T, typename ValueType>
int findIndex(vector<T> v, ValueType x) {
  auto it = std::find(v.begin(), v.end(), x);
  return std::distance(v.begin(), it);
}


// Part B: 
// Same functionality using std::lower_bound & std::upper_bound
Result find_sequential_greater_lower(const vector<int>& v, int x) {
  auto lowIt = std::lower_bound(v.begin(), v.end(),
                                x);  // same steps are followed as above
  int lowInd = std::distance(v.begin(), lowIt);
  if (lowIt != v.end()) {
    if (v[lowInd] == x && v[lowInd + 1] > x) {
      return std::make_tuple(std::make_tuple(lowInd, lowInd + 1), true);
    } else {
      return std::make_tuple(std::make_tuple(lowInd - 1, lowInd), true);
    };
  };
}

  Result find_sequential_greater_upper(const vector<int>& v, int x) 
  {
    auto highIt = std::upper_bound(v.begin(), v.end(), x);  // same steps followed as above
    int highInd = std::distance(v.begin(), highIt);
    if (highIt != v.end()) {
      if (v[highInd - 1] <= x) {
        return std::make_tuple(std::make_tuple(highInd - 1, highInd), true);
      };
    };
    return std::make_tuple(std::make_tuple(999, 999), false);
  }

//Part C: 
// same functionality using std::equal_range
Result find_sequential_greater_range(const vector<int>& v, int x) {
    auto pair1 = std::equal_range(v.begin(), v.end(), x);  // perform operation
    int highInd = std::distance(v.begin(), pair1.second);  // get index
    if (pair1.second != v.end()) {  // check if stl function found a value
      if (v[highInd - 1] <= x) {    // check if prior value is less than target
                                  // val
        return std::make_tuple(std::make_tuple(highInd - 1, highInd),
                               true);  // make output
      };
    };
    return std::make_tuple(std::make_tuple(999, 999), false);
  }

// Part D: 
// testing find_if_not using an example...pulled the isOdd example from slides

bool isOdd(int d) {
    if (d % 2 == 1) return true;
    return false;
  }

Result test_find_if_not(const vector<int>& v) {
    auto it = std::find_if_not(v.begin(), v.end(), isOdd);  // get first odd
    int ind = std::distance(v.begin(), it);
    if (it != v.end()) {
      return std::make_tuple(std::make_tuple(ind, ind),
                             true);  // return first even value index
    };
    return std::make_tuple(std::make_tuple(999, 999), false);
  }


void print(Result r) {
    auto range = std::get<0>(r);
    std::cout << "Range " << std::get<0>(range) << ", " << std::get<1>(range)
              << "\n";
    std::cout << "Success: " << std::get<1>(r) << std::endl;
  }

  int main() {
    // Running and Testing Functions here

    vector<int> vec1(8);
    for (int i = 0; i < vec1.size(); i++) {
      vec1(i) = i * i;
    }
    std::cout << "Given Function:" << std::endl;
    Result out1 = find_sequential_greater(vec1, 1);  // Part A:
    print(out1);

    std::cout << "Part A, Index Function:" << std::endl;
    int indx1 = findIndex(vec1, 1);  // Part A:
    std::cout << indx1 << std::endl;

    std::cout << "Part B:" << std::endl;
    Result out2 = find_sequential_greater_lower(vec1, 1);  // Part A:
    print(out2);

    std::cout << "Part C:" << std::endl;
    Result out3 = find_sequential_greater_upper(vec1, 1);  // Part A:
    print(out3);

    std::cout << "Part D:" << std::endl;
    Result out4 = test_find_if_not(vec1);  // Part A:
    print(out4);
  }

