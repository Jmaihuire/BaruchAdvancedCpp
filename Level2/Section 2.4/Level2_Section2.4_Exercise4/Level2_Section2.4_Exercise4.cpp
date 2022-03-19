// Level2_Section2.4_Exercise4.cpp : 
// Fiona Ross - 02-25-2022

#include <iostream>
#include <memory>
#include "BaseClass.cpp"
#include "DerivedClass.cpp"
#include <list>
#include <vector>

auto factoryDerivedClass() {

    std::shared_ptr<BaseClass> ptr(new DerivedClass);
    return ptr;

}

int main()
{

    // Part A: 
    // Create a list of smart pointers to Base.
    // In particular, test the above code with both shared and unique pointers.
    // Which option compiles and why does unique pointer not compile ?

    std::list<std::shared_ptr<BaseClass>> pt_shared_list(3); // this works 
    // std::list<std::unique_ptr<BaseClass>> pt_unique_list(3); // this has error C2248 cannot access protected member declared in class "BaseClass"
    // The unique pointer cannot access the protected destructor in the Base class 
    // The unique pointer default constructor contains a deleter field while shared pointer does not

    // Part B & C: 
    // Factory Function
    // there is no memory leak because this factory class calls the base class & derived class memory leak. 
    pt_shared_list.push_back(factoryDerivedClass());
}

