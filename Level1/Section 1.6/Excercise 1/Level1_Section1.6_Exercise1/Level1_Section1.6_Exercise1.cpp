// Level1_Section1.6_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

// Forward Declaration 
class Base;
class Derived;
class Derived2; 

struct Base
{
    virtual void draw() { std::cout << "print a base\n"; }
    void print() {}
    ~Base() { std::cout << "bye base\n"; }
};

// OLD: struct Derived final : public Base 
    // --> changed this from class Derived2 final because when final is used in a class
    //     definition, final specifies that this class may not appear in the base-specifier-list
    //     of another class definition (in other words, cannot be derived from)
struct Derived : public Base
{
    Derived() {}
    void draw() override { std::cout << "print a derived\n"; }
    void draw() const {} // OLD: void draw() const override {} --> already overriden the base class so unnecessary since now overriding derived class 
    
                         // OLD: void print() override {} --> Not actually changing anything from the base class so can just call the base class function 
    ~Derived() { std::cout << "bye derived\n"; }
};

class Derived2 : public Derived  
{

};

int main()
{
    std::cout << "Hello World!\n";
}
