// Level3_Section3.5_Exercise3.cpp 
// Fiona Ross - Exercise 3: Forward List 101

#include <forward_list>
#include <iostream>

// Part B: Size function 
template <typename T>
int fl_size(std::forward_list<T>& fl_input) {
  int len_ = std::distance(fl_input.begin(), fl_input.end());
  return len_;
};

// 
template <typename T>
void print_fl(std::forward_list<T>& fl_input) {
  for (T e : fl_input) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
};

// Part D erase function with position
template <typename T, typename It>
void eraseElement(std::forward_list<T>& fl_input, It it) {
  fl_input.erase_after(it);
}

// Part D erase function between iterators
template <typename T, typename It>
void eraseElement(std::forward_list<T>& fl_input, It it1, It it2) {
  fl_input.erase_after(it1, it2);
}

int main() {
  // Part A:
  // default list 
  std::forward_list<int> fl1(
      10, 3);  // create a default list with n elements and a given value
  std::forward_list<int> fl2{1, 2, 3, 4, 5};  // using initialization list 

  // Part B:
  // using own size function for forward list 
  std::cout << "Fl2 has size: " <<fl_size(fl2) << std::endl;

  // Part C:
  // directly calling std::forward_list::insert_after
  std::cout << "Fl2 Original: ";
  print_fl(fl2);

  auto beginIt = fl2.begin();  // get begin iterator
  fl2.insert_after(beginIt,
                   11);  // insert value aftera  given position based on value
  std::cout << "Fl2 insert1: ";  // print
  print_fl(fl2);

  auto anotherIt = beginIt;  // create second iterator
  ++anotherIt;
  anotherIt = fl2.insert_after(anotherIt, 3, 42);  // value and count
  std::cout << "Fl2 insert2: ";                    // print
  print_fl(fl2);

  auto initList = {77, 88, 99};
  anotherIt =
      fl2.insert_after(anotherIt, initList.begin(),
                       initList.end());  // two iterators and initializer list
  std::cout << "Fl2 insert3: ";          // print
  print_fl(fl2);

  // Part D:
  eraseElement(fl2, beginIt, anotherIt);
  std::cout << "Fl2 erase1: ";  // print
  print_fl(fl2);

  // Part E:
  fl2.splice_after(beginIt, fl1, fl1.begin(), fl1.end());  // splice fl1 into
                                                           // fl2
  std::cout << "Fl2 splice1: ";  // print
  print_fl(fl2);
  fl2.sort();  // sort both lists so we can merge
  fl1.sort();
  fl2.merge(fl1);              // merge lists
  std::cout << "Fl2 merge: ";  // print sorted merged lists
  print_fl(fl2);
}
