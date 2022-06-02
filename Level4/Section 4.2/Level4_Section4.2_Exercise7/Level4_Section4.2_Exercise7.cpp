// Level4_Section4.2_Exercise7.cpp
// Fiona Ross 
// Mutating Algorithms 

#include <iostream>
#include <vector>

// Bringing over print function from other lessons 
// print vector
void print(std::vector<int> v) {
  for (auto el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

void power_set(std::vector<int> v) {
  int counter = 1;
  // initializing output vector 
  std::vector<std::vector<int>> outVec;  
  // iteratring through vector 
  while (counter < v.size()) {
    for (int i = 0; i < v.size(); i++) {
      // rotating each element
      std::rotate(v.begin(), v.begin() + 1, v.end());
      // tempVec stores the power vector output 
      std::vector<int> tempVec(
          &v[0], &v[0] + counter);
      // inputs the tempVec intp the output vector 
      outVec.push_back(tempVec);
    }
    counter++;
  }
  outVec.push_back(v);
  for (auto vec : outVec) {
    print(vec); 
  }
}



int main()
{
  // Part A: Reverse
  // initialize vector 
    std::cout << "Part A: " << std::endl; 
  std::vector<int> S = {1, -1, 7, 8, 9, 10};
  std::reverse(S.begin(), S.end());  // modify S to revere its order
  std::vector<int> S2(S);            // copy to second container
  print(S2);

  // Part B: Rotation 
  // making assumption that we keep manipulating the newest version of S
  std::cout << "Part B: " << std::endl; 
  std::rotate(S.begin(), S.begin() + 2, S.end());
  print(S);

  // Part C: Power Set 
  std::cout << "Part C: " << std::endl; 
  power_set(S);  // power set for S

  // Part D: Moving subvector 
  std::cout << "Part D: " << std::endl; 
  std::vector<int> Snew = {1, -1, 7, 8, 9, 10}; 
  auto rotated = std::find(Snew.begin(), Snew.end(), 8);  // find where subset begins
  std::rotate(Snew.begin(), rotated,
              Snew.end());  // rotate vector so 8 9 10 is at front
  print(Snew);

}