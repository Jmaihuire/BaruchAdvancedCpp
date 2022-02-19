// Level2_Section2.3_Exercise1.cpp : 
/*
Fiona Ross - 02-10-2022
Advanced Lambda Programming 
*/

#include <iostream>

//User defined deprecated entities : 
// a) Free / global functions.
double squared(double x) { return x * x; };

// b) Deprecated classand non - deprecated class with deprecated member function.
class [[deprecated("old class")]] C
{
public:
    [[deprecated]] int data; 
    [[deprecated("deprecated member function")]] void print() { std::cout << "Depreciated Class & Member Functions"; }
};

class D
{
public: 
    [[deprecated]] int data;
    [[deprecated("deprecated member function")]] void print() { std::cout << "Current Class & Depreciated Member Func"; }
};

// c) Deprecated global variable.
[[deprecated("depreciated global variables")]] int global{};


// d) Deprecated enumand deprecated enumclass
    enum [[deprecated("old enum")]] days { yesterday, today, tomorrow};   
   
    enum class[[deprecated("old enum class")]] timed{yesterday, today, tomorrow};  
// e) Deprecated template class specialization.
    template<typename T>
    class ABC {};

    template<>
    class [[deprecated("old template specializaiton")]] ABC<int> {};


#include <iostream>

int main()
{
    // f) Deprecated lambda function.
    // [[deprecated("Old lambda function")]] auto func = []() {std::cout << "Deprecated Lambda"; }; // Get error C4996 saying 'func' is old lambda function 
    std::cout << "Hello World!\n";

    // a) Free / global functions
    // This was okay because not deprecated 
     double x = 10.3;
     double y = squared(x);
     std::cout << "Output of y is: " << y << std::endl; 
    
    // b) Deprecated classand non - deprecated class with deprecated member function.
    // Error C4996 for all of these 
    // C Cclass;
    // Cclass.data = 12; 
    // Cclass.print();
    // D Dclass;
    // Dclass.data = 15; 
    // Dclass.print();

    // c) Deprecated global variable 
     int global = 19; 
     std::cout << "Output of global: " << global << std::endl;  // global variable was not deprecated 

    // d) Depreciated enum and depreciated enum class 
    // days yesterday; // Get error C26812 & C4996 saying enum 'days' is unscoped and 'days' is an old enum 
    // timed yesterday; //Error C4996 'timed' is an old enum class 
}

