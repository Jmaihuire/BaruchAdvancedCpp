#pragma once
#include "BaseClass.h"
class DerivedClass :
    public BaseClass
{
private:
public:
    DerivedClass() : BaseClass() { }
    ~DerivedClass() { std::cout << "Derived destructor\n"; }
    void print() const { std::cout << "derived object\n"; }
};

