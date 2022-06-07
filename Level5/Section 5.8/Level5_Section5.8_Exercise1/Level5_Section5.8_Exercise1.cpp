// Level5_Section5.8_Exercise1.cpp 
// Fiona Ross 
// Heap 101

#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int>& v) {
	for (const auto& e : v) 
	{
		std::cout << e << " "; 	
	}
    std::cout << std::endl;
}

int main()
{ 
	// Part A: 
	std::vector<int> vec2{3, 4, 5, 6, 7, 5, 6, 7, 8, 9, 1, 2, 3, 4}; 
	for (int iter : vec2) {
          std::cout << iter << " ";
	}
	std::cout << std::endl; 

	// Part B: 
	std::make_heap(vec2.begin(), vec2.end());
    for (int iter : vec2) {
          std::cout << iter << " ";
    }

	// Part C: 
	std::pop_heap(vec2.begin(), vec2.end()); 
	std::cout << "\n";
	std::cout << "After pop heap" << std::endl; 

	for (int iter : vec2) {
          std::cout << iter << " ";
    }
	std::cout << std::endl; 

	// changing this to a print function because
    // this is a lot of iteration 
	vec2.pop_back();
	std::cout << "\n";
	std::cout << "After pop back" << std::endl;
    for (int iter : vec2) {
          std::cout << iter << " ";
    }
    std::cout << std::endl; 
	// pop back puts the old head from the back of the container into the front 
	// also without pop_back for some reason the sort_heap was not working 
	

	// making non-heap component
	std::vector<int> vec3{1, 5, 10, 15, 20};
    
	// putting the non heap into a heap using pop_heap 
	std::pop_heap(vec3.begin(), vec3.end()); 
	print(vec3);
	// I think the non-heap gets transformed into a heap 

	// Part D: 
	// calling push heap
    vec2.push_back(12);
    print(vec2); 
	std::push_heap(vec2.begin(), vec2.end()); 
	print(vec2);

	// calling push heap with non heap member 
	// if redeclare as vector then throws exception that cannot push_heap on non heap elements
	// std::vector<int> vec4{2, 4, 6, 8}; //redeclaring new vector since pretty confidence vec3 is now heap
    vec3 = {2, 4, 6, 8}; 
	std::push_heap(vec3.begin(), vec3.end());
    print(vec3);
    // unlike part c this doesnt change it into a heap

    // Part E:
    print(vec2); 
	std::sort_heap(vec2.begin(), vec2.end());
    print(vec2);

	// Part F: 
	std::make_heap(vec2.begin(), vec2.end());
    std::cout << "Largest element in vec2 is: " << vec2.front();

}



