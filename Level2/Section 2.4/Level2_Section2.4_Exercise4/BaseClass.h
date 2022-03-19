#pragma once
#include <iostream>
class BaseClass
{
private:
public:
    BaseClass() { }
    virtual void print() const = 0;
protected:
    virtual ~BaseClass() { std::cout << "BaseClass destructor\n\n"; }
};

