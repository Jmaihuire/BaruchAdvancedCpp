// Level1_Section1.2_Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 3: Improvements in Classes, Part II

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>

// Part A) Create the move constructor and the move assignment 
//         operator for class C

template <class T>
class MoveClass
{
private:
    T vec; //Data member

public:

    explicit constexpr MoveClass() { vec = {}; std::cout << "Default constructor called...\n"; }; //Default Constructor

    explicit MoveClass(const MoveClass& moveclass) noexcept { vec = moveclass.vec; std::cout << "Copy constructor called...\n"; }; //Copy Constructor

    void operator () (T v) { vec = v; std::cout << "Assignment operator called...\n"; }; //Assignment Operator

    ~MoveClass() {}; //Destructor

    // move operator 
    MoveClass& operator= (MoveClass&& moveclass) {
        std::cout << "Move operator called...\n";
        vec = std::move(moveclass.vec);
        return *this;
    };

    // move constructor 
    MoveClass(MoveClass&& moveclass) noexcept {
        std::cout << "Move constructor called...\n";
        vec = std::move(moveclass.vec);
    };

    // print function 
    void print() {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    };

    //Scaleing function 
    void scale(double factor) {
        std::for_each(vec.begin(), vec.end(), [factor](double& v) { v *= factor; });
    };

}; 

int main()
{
    // Part B) Test these new functions. How can you ensure that a move constructor 
    //         is called instead of a copy constructor?
    std::cout << "Using copy functions: \n";
    MoveClass<std::array<double, 4>> m1; //Call default constructor
    std::array<double, 4> v1 = { 1.0,2.0,3.0,4.0 }; //Initialize vector data - using array so constexpr can be tested
    m1(v1); //Call assignment operator
    std::cout << "Original Vector: ";
    m1.print();
    MoveClass<std::array<double, 4>> m2(m1); //Call copy constructor
    std::cout << "Copied Vector: ";
    m2.print();

    std::cout << "Now implimenting move function";
    MoveClass<std::array<double, 4>> m3(std::move(m1)); 
    MoveClass<std::array<double, 4>> m4 = std::move(m3);
    m3.print();
    m4 = std::move(m3);
    return 0;


    // Part C) What happens if you use an lvalue as the source of a move operation?
    int val = 10; //lval
    int& lval = val;  // reference to val 
    int&& rval(std::move(lval)); // rval reference

}


