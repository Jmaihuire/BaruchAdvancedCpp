// Level5_Section5.8_Exercise2.cpp 
// Fiona Ross 
// Priority Queue

#include <iostream>
#include <vector>
#include <queue>

template <class T, class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type> >
class priority_queue;

template<typename T>
void printQ(T Q) {
  // pulled this from c++ tutorial online
  while (!Q.empty()) {
    std::cout << " " << Q.top();
    Q.pop();
  }
  std::cout << std::endl;
}

int main()
{

    // Part A: 
    // making instance 
    std::priority_queue<int, std::vector<int>> Q1;

    // inserting elements 
    for (int num : {10, 5, 20, 30, 25, 7, 40}) {
      Q1.push(num);
    }
    
    // printing 
    printQ(Q1); 
    
    // Part B: same thing but using comparer 
    std::priority_queue<int, std::vector<int>, std::greater<>> Q2;
    // I think this just will sort the integers as inserted 
    for (int n : {10, 5, 20, 30, 25, 7, 40}) {
      Q2.push(n);
    }
    printQ(Q2);

    // Part C: 
    // from lecture / homework slide 
    auto cmp = [](int left, int right) -> bool { return (left > right); };
    
    // same as Part A & B
    std::priority_queue<int, std::vector<int>, decltype(cmp)> Q3(cmp);
    for (int n : {10, 5, 20, 30, 25, 7, 40}) {
     Q3.push(n);
    }

    printQ(Q3);
}
