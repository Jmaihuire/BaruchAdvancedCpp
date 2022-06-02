// Level4_Section4.2_Exercise5.cpp 
// Fiona Ross 
// Comparing Styles 

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Pulling in the usual print statements 
void print(std::vector<int> v) {
  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

// Part A: Creating user defined addition
int add(const int& elem1, const int& elem2) { return elem1 + elem2; }

bool less_than(const int& elem1, const int& elem2) {
    if (elem1 <= elem2) {
    return true; 
    }
    return false; 
}

int main()
{
    // Part A: Comparing user defined func, stl func, lambda func 

  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {2, 3, 4, 5, 6};
  std::transform(v1.begin(), v1.end(), v2.begin(), v1.begin(),
                 std::plus<int>());  // STL function object
  print(v1);
  std::transform(v1.begin(), v1.end(), v2.begin(), v1.begin(),
                 add);  // user defined function
  print(v1);
  std::transform(v1.begin(), v1.end(), v2.begin(), v1.begin(),
                 [](int a, int b) { return a * b; });  // lambda
  print(v1);

  // Part B: Transfomring vector 
  int thresh = 4;
  auto v3(v2);  // make copy to erase
  
  std::cout << "\nLambda Function Transform: ";
  std::vector<int>::iterator pos2 = remove_if(v3.begin(), v3.end(), [=](int i) {
    return (i <= thresh);
  });  // lambda function
  v3.erase(pos2, v3.end());
  print(v3); //print results 

  std::cout << "\n STL Function Transform: ";
  v3 = v2;  // reset
  std::vector<int>::iterator pos3 = remove_if(
      v3.begin(), v3.end(),
      std::bind2nd(std::less_equal<int>(), thresh));  // STL built in function
  v3.erase(pos3, v3.end());
  print(v3);

  std::cout << "\n User Defined Function Transform: "; 
  v3 = v2;  // reset
  using namespace std::placeholders;
  std::vector<int>::iterator pos4 =
      remove_if(v3.begin(), v3.end(),
                std::bind(less_than, _1, thresh));  // lambda function
  v3.erase(pos4, v3.end());
  print(v3);

  // Part C: 
  // Maintainability - the user defined are definitely easier to maintain since more control
  // Understandability - lambda functions becuase you can see the code right in front of you 
  // Efficiency - STL functions because they are already written and usually somewhat optimized 
}
