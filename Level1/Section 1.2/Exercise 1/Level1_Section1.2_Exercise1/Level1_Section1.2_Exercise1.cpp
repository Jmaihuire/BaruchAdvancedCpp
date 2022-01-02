// Level1_Section1.2_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1: Basic Improvements in Classes

#include <iostream>
using namespace std;
#include <vector>
#include <array>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <string>
#include <cstdlib>

//----------------------------
//      Original Class C
//----------------------------

class C {

    // implimenting iterator
    std::size_t size;
    typedef int* iterator;
    typedef const int* const_iterator;

public:
    // Class Data Member 
    std::vector<int> classVec;

    ~C() {}  //I. destructor 
    C() {}; // II. default constructor 
  
    C(std::vector<int> initinput) { this -> classVec = initinput; cout << "Class C Constructor is called..." << endl; } //III. constructor

    C(C& copyClass) { classVec = copyClass.classVec; cout << "Class C Copy Constructor called..." << endl; }; // IV. copy constructor 

    C& operator= (const C& copyvec) //V. assignment operator 
    {
        cout << "Class C assignment operator is called" << endl;
        return *this;
    }

    // member function declaration
    void print() { for (int i = 0; i < classVec.size(); ++i){ cout << classVec[i] << endl; } };
    void scale(double mult) { for (int i = 0; i < classVec.size(); ++i) { cout << classVec[i] * mult << endl; } };

}; 

//----------------------------------------
//      Class D 
//        Excercise 1a: Basic Improvements
//     
//----------------------------------------
// Part A) 
// Modify class C so that 1) its default constructor is absent 
// and 2) copy constructorand assignment are private.
//        To this end, use keyword default to explicitly tell 
//        the compiler to generate a default constructor.
//        Furthermore, use the keyword delete to mark the copy 
//        constructorand assignment operator as deleted functions.
//        Deleted functions may not be used in any way, even by friends.
//        Test your code again, including calling the defaulted and deleted functions.
//        What is the resulting behavior ?

class D {
public:
    // Class Data Member 
    std::vector<int> classVec = { 1,10,20,30 };

    ~D() {}  //I. destructor 
    D() = default; // default constructor (Ex. 1a) 
    D(std::vector<int> initinput) { this->classVec = initinput; cout << "Class D Constructor is called..." << endl; } //III. constructor

    // member function declaration
    void print() { for (int i = 0; i < classVec.size(); ++i) { cout << classVec[i] << endl; } };
    void scale(double mult) { for (int i = 0; i < classVec.size(); ++i) { cout << classVec[i] * mult << endl; } };

private:
    // IV.copy constructor
    D(D& copyClass) = delete; // (Ex. 1a) 

    //V. assignment operator 
    D& operator= (const D& copyvec) = delete;// (Ex. 1a) 

    // {
    // cout << "assignment operator is called" << endl;
    // return *this; }   
    //

};



//----------------------------------------
//      Class E
//        Excercise 1b 
//     
//----------------------------------------
// Part B) Use the explicit keyword in the constructors 
//         to disallow implicit type conversion.
class E {
public:
    // Class Data Member 
    std::vector<int> classVec = { 1,10,20,30 };

    ~E() {}  //I. destructor 
    explicit E() {}; // explicit default constructor (Ex. 1b) 
    explicit E(std::vector<int> initinput) { this->classVec = initinput; cout << "Class E Constructor is called..." << endl; } //III. constructor

    // member function declaration
    void print() { for (int i = 0; i < classVec.size(); ++i) { cout << classVec[i] << endl; } };
    void scale(double mult) { for (int i = 0; i < classVec.size(); ++i) { cout << classVec[i] * mult << endl; } };


    E(E& copyClass) {};   // IV.copy constructor


    E& operator= (const E& copyvec) //V. assignment operator
    {
        cout << "Class E assignment operator is called" << endl;
        return *this;
    };
};


//----------------------------------------
//      Class F
//        Excercise 1c: 
//          Questions: not letting me initialize 
//          size_t and so cannot use constexpr
//----------------------------------------

// Part C) Use constexpr keyword for those functions in which
//        input arguments are known at compile - time(for example,
//        constructorsand setters).Then the data members will also
//        be known at compile - time.

template <class T>
class F
{
private:
    T vec; //Data member
public:
    explicit constexpr F() { vec = {}; std::cout << "Default constructor called...\n"; }; //Default Constructor
    explicit F(const F& f1) { vec = f1.vec; std::cout << "Copy constructor called...\n"; }; //Copy Constructor
    void operator () (T v1) { vec = v1; std::cout << "Assignment operator called...\n"; }; //Assignment Operator
    ~F() {}; //Destructor


    void print() {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    }; //Print vector values

    void scale(double factor) {
        std::for_each(vec.begin(), vec.end(), [factor](double& v) { v *= factor; });
    }
};


//----------------------------------------
//      Class G
//        Excercise 1d:      
//----------------------------------------

// Part D) Use the keyword noexcept for those member functions which 
//         you know will not throw an exception.

template <class T>
class G
{
private:
    T vec; //Data member
public:
    explicit constexpr G() { vec = {}; std::cout << "Default constructor called...\n"; }; //Default Constructor
    explicit G(const G& g1) noexcept { vec = g1.vec; std::cout << "Copy constructor called...\n"; }; //Copy Constructor
    void operator () (T v1) { vec = v1; std::cout << "Assignment operator called...\n"; }; //Assignment Operator
    ~G() {}; //Destructor


    void print() {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    }; //Print vector values

    void scale(double factor) {
        std::for_each(vec.begin(), vec.end(), [factor](double& v) { v *= factor; });
    }
};





int main()
{
    //-----------------------
    //       Part A) 
    //-----------------------
    std::vector<int> testCInputVec{ 5, 10, 15, 20 };
    double testCMult = 3;
    C testC(testCInputVec);
    testC.print();
    testC.scale(testCMult);

    // testing copy constructor 
    C copyTestC = testC;
    C assignTestC(copyTestC);

    // testing assignment constructor 
    assignTestC = copyTestC;

    // Ex 1a: 
    double testDMult = 4.0;
    D testD;
    testD.print();
    testD.scale(testDMult);

    // Testing copy constructor: 
    // D copyTestD = testD; // when try to compile says 'inaccessible' 
    // D assignTest(copyTestD); //when try to compile says 'inaccessible' 
    // copy construct cannot be called from main since a deleted function 

    // Testing assignment constructor: 
    // assignTest = copyTest; // copyTest becomes inaccessible so cannot do the assignment 
    // assignment construct cannot be alled from main since a deleted function 

    // Calling deleted functions 

    //-----------------------
    //       Part B) 
    //-----------------------
    // Ex. 1b: 
    D d1 = std::vector<int>{ 3,6,9,12,15 }; // OK:: copy-initialization selects D::D(std::vector<int>)
    D d2(std::vector<int>{3, 6, 9, 12, 15}); // OK::direct initialization 

    // E e1 = std::vector<int>{ 3,6,9,12,15 }; // cannot copy initialize when constructor has explicit keyword 
    E e2(std::vector<int>{3, 6, 9, 12, 15}); // OK::direct initialization 

    //-----------------------
    //       Part C) 
    //-----------------------

    F<std::array<double, 4>> f1; //Call default constructor
    std::array<double, 4> vecIn1 = { 1.0,2.0,3.0,4.0 }; //Initialize vector data - using array so constexpr can be tested
    f1(vecIn1); //Call assignment operator
    std::cout << "Original Vector: \n";
    f1.print();
    F<std::array<double, 4>> f2(f1); //Call copy constructor
    f2.scale(2.0);
    std::cout << "Scaled Vector Copy: \n";
    f2.print();


    //-----------------------
    //       Part D) 
    //-----------------------

    G<std::array<double, 4>> g1; //Call default constructor
    std::array<double, 4> vecInG = { 1.0,2.0,3.0,4.0 }; //Initialize vector data - using array so constexpr can be tested
    g1(vecInG); //Call assignment operator
    std::cout << "Original Vector: \n";
    g1.print();
    G<std::array<double, 4>> g2(g1); //Call copy constructor
    g2.scale(2.0);
    std::cout << "Scaled Vector Copy: \n";
    g2.print();
};

