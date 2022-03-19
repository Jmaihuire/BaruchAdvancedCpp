// Level2_Section2.8_Exercise4.cpp : 
// Fiona Ross - 03-19-2022
// Using std::vector<bool> instead of Bitsets 

#include <iostream>
#include <vector>

std::vector<bool> Intersect(std::vector<bool> v1, std::vector<bool> v2) {
    std::vector<bool> output(v1.size());
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] == v2[i]) {
            output[i] = 1;
        }
        else {
            output[i] = 0;
        }
    };
    return output;
}

int main()
{

    // Part A: 
    // std::vector<bool>
    //      Includes 
    //          - pop_back function 
    //          - push_back functions
    //          - resize
    //          - flip
    //          - swap
    //          - It also has the standard vector functionality, so it can be modified during runtime.
    //      Does NOT Include
    //          - bitwise operators 

    // Part B: A function to intersect two instances of std::vector<bool> 
    std::vector<bool> v1 = { 0, 0, 1, 1, 1 };
    std::vector<bool> v2 = { 0, 0, 1, 1, 0 };
    auto intersect_out = Intersect(v1, v2);

    // Output the results 
    std::cout << "output is: " << std::endl;
    for (bool b : intersect_out)
    {
        std::cout << b << " " << std::endl;
    };

}
