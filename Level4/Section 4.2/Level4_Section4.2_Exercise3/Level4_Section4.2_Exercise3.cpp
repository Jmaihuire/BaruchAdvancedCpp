// Level4_Section4.2_Exercise3.cpp 
// Fiona Ross 
// Classifying and Implimenting Algorithms 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>	
#include <list>
#include <random>
#include <chrono>

// Vector print functions 
void print(std::vector<int> v) {
  for (int elem : v) {
    std::cout << elem << ", ";
  }
}

// another print function for lists 
void print(std::list<int> list) {
  for (int elem : list) {
    std::cout << elem << ", ";
  }
}

int main()
{
   // Possible Algorithm Choices: Non-modifying, modifying, removing, 
   // mutating, sorting, sorted ranges, numeric 
   
	std::vector<int> v1 = {1,2,3,4}; 
   // Part A: scale all values by a given factor 
	std::cout << "\n";
    std::cout << "Part A: scale factor" << std::endl; 
	int sf = 4; // scale factor 
	std::transform(v1.begin(), v1.end(), v1.begin(),
                       [=](int el) { return sf * el; });
    print(v1);
	std::cout <<std::endl; 
	// adding a lambda function to transform makes scale factoring a vector easy 

	//Part b) Count the number of elements whose values are in a given range.
    std::cout << "\n";
    std::cout << "Part B: Counting Vector" << std::endl; 
	int range[] = { 1, 34};
    int num_elem = std::count_if(v1.begin(), v1.end(), [&range](int el) {
      return (el > range[0]) && (el <= range[1]);
    });

    std::cout << num_elem << std::endl; 

	//Part c) Find the average, minimum and maximum values in a container.
    std::cout << "\n";
    std::cout << "Part C: Min, max & average values: "
              << *std::min_element(v1.begin(), v1.end()) << ", "
              << *std::max_element(v1.begin(), v1.end()) << std::endl;
    // getting sum 
    double average = std::accumulate(v1.begin(), v1.end(), 0) / v1.size();
    std::cout << "Average: " << average << std::endl;


	//Part d) Find the first element that is (that is not) in a range.
    std::cout << "\n";
    std::cout << "Part D: In and Out of Range\n";
    int range2[] = {5, 9};
    auto firstEl = std::find_if(v1.begin(), v1.end(), [&range2](int el) {
      return (el > range2[0]) && (el < range2[1]);
    });
    std::cout << "Elements in range: " << *firstEl << std::endl;

    //e) Search for all occurrences of ‘3456’ in the container.
    std::cout << "\n";
    std::cout << "Part E subvector in vector: \n";
    std::list<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,13}; 
    std::list<int> subvec = {3, 4, 5, 6};  // subrange to look for
    std::list<int>::iterator pos = vec.begin();
    // Search for first subrange
    pos = std::search(vec.begin(), vec.end(), subvec.begin(), subvec.end());
    // keep looping through range until the iterator is at the end
    while (pos != vec.end()) {
      // distance between the iterators (plus 1): position := distance +1
      std::cout << "Subvec found at position: "
                << std::distance(vec.begin(), pos) + 1 << std::endl;
      pos = std::search(++pos, vec.end(), subvec.begin(), subvec.end());
    }

    //f) Determine if the elements in two ranges are equal. 
    std::cout << "\n";
    std::cout << "Part F elements in two ranges: \n";
    std::vector<int> vec1 = { 1, 2, 3, 4};
    std::vector<int> vec1a(vec1);
    std::vector<int> vec2 = {2, 3, 4};
    std::cout << "vec1 = vec2? " << std::boolalpha << std::equal(vec1.begin(), vec1.end(), vec1a.begin()) << std::endl;
    
    //g) Determine if a set is some permutation of ‘12345’.
    std::cout << "\n";
    std::cout << "Part G: \n";
    std::cout << "vec1 permutation of vec2? " << std::boolalpha
              << std::is_permutation(vec1.begin(), vec1.end(), vec1a.begin())
              << std::endl;


    //h) Is a container already sorted?
    std::cout << "\n";
    std::cout << "Part H: check if vector is sorted \n";
    std::cout << "L5 is sorted? " << std::boolalpha
              << std::is_sorted(vec2.begin(), vec2.end()) << std::endl;

    //i) Copy a container into another container.
    std::cout << "\n";
    std::cout << "Part I: Copying containers \n";
    std::cout << "vec2 copied to vec3: \n";
    std::vector<int> vec3 = {1, 2, 3, 5};
    std::copy(vec2.begin(), vec2.end(), vec3.begin());
    print(vec3);

    //j) Move the last 10 elements of a container to the front.
    std::cout << "\n";
    std::cout << "Part J: Move the last 10 elements to the front: \n";
    auto vecBegin = vec.begin();
    std::advance(vecBegin, 3); // which elements we want to bring to front
    std::rotate(vec.begin(), vecBegin, vec.end());
    print(vec);

    //k) Swap two ranges at a given position.
    std::cout << "\n";
    std::cout << "Part K: swap first three elements of vec into vec1 \n";
    std::cout << "Original Vectors: " << std::endl;
    print(vec);
    print(vec1);
    auto swapPos = vec.begin();
    std::advance(swapPos, 3);
    std::swap_ranges(vec.begin(), swapPos, vec1.begin());
    std::cout << "Swapped Vectors: " << std::endl;
    print(vec);
    print(vec1);
    

    //l) Generate values in a container based on some formula.
    std::cout << "\n";
    std::cout << "Part L: Making container based on formula \n";
    std::list<int> vec5(5);
    std::generate_n(vec5.begin(), 5, []() {
      static int i = 0;
      return ++i;
    });
    print(vec5);

    //m) Replace all uneven numbers by zero.
    std::cout << "\n";
    std::cout << "Part M: uneven numbers \n";
    std::replace_if(
        vec.begin(), vec.end(), [](int i) { return ((i % 2) == 1); },
        0);  // replace number if odd
    print(vec);

    //n) Remove all elements whose value is less than 100.
    std::cout << "\n";
    std::cout << "Part N: Removing elements of value less than 100\n";
    std::list<int> vec6 = {100, 1, 101, 50, 20, 1200, 300};
    std::list<int>::iterator pos2 =
        remove_if(vec6.begin(), vec6.end(), [](int i) { return (i < 100); });
    vec6.erase(pos2, vec6.end());
    print(vec6);

    //o) Shuffle a container randomly (pre- and post-C++11 versions).
    std::cout << "\n";
    std::cout << "Part O: Shuffle container randomly \n";
    std::random_device rng;
    std::mt19937 urng(rng());
    std::vector<int> vec7 = {1, 2, 3, 4};
    std::shuffle(vec7.begin(), vec7.end(), urng);  // post c++11
    print(vec7);

    //p) Compute one-sided divided differences of the values in a container.
    std::cout << "\n";
    std::cout << "Part P: compute one sided difference \n";
    auto v2(vec1);
    std::transform(++vec1.begin(), vec1.end(), v2.begin(), ++vec1.begin(),
                   [](int i, int i2) {
                     return i - i2;
                   });  // start the iterators offset by one from each other so
                        // we can use the binary operator to perform difference
    print(vec1);


}
