// Level1_Section1.6_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <memory>
#include <vector>

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

class Derived2 final: public Derived // sealing Derived 2 class 
{

};

int main()
{   // Part B) 
    //          Once fixed, create instances of Derived using Base smart pointers

    std::vector< std::shared_ptr<Base> > v; // this will store multiple smart pointers 
    std::shared_ptr<Base> pa(new Base());   // this is a base smart pointer 
    std::shared_ptr<Base> pb(new Derived());  // this is a derived smart pointer 
    v.push_back(pa);
    v.push_back(pb);   
    v[0]->print();      
    v[1]->print();
    pb->draw();         // this will create an output "print a derived"
    v[0]->draw();       // this will create an output "print a base "

}
