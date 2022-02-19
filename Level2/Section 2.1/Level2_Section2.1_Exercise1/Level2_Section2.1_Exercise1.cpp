// Level2_Section2.1_Exercise1.cpp 
/*
    Fiona Ross - 02-01-2022
    These exercise consists of calling some functions from Primary type categories.
    
    Part A: Function identifying pointer/null pointer/ lvalue/ rvalue
    Part B: Identifying member function pointer / non static member object
    Part C: Identifying shared pointer type / raw pointer 
*/


#include <iostream>

// Part A: Write a function to determine if a type is a pointer
//         null pointers, lvalue reference or rvalue reference. 

template <typename T>
void EvaluateType(const T& t)
{
    // Checking if it is a pointer
    if (std::is_pointer<T>::value)
    {
        std::cout << "Pointer type argument detected" << std::endl;
    }
    else if (std::is_null_pointer<T>::value)
    {
        std::cout << "Null pointer type argument detected" << std::endl;
    }
    else if (std::is_lvalue_reference<T>::value)
    {
        std::cout << "This is a lvalue type argument" << std::endl;
    }
    else if (std::is_rvalue_reference<T>::value)
    {
        std::cout << "This is a rvalue type argument" << std::endl;
    }
    else
    {
        std::cout << "This is neither a pointer, null pointer, rvalue nor lvalue" << std::endl;
    }     
}

// Part B: Determine if a type is a member function pointer or if it is a pointer to a non-static member object.
template <typename T>
void IsMemberFuncPointer(T val)
{
    // testing member functions (only is true for non-static func pointers)
    if (std::is_member_function_pointer<T>::value)
    {
        std::cout << "This is a non-static member function pointer" << std::endl;
    }
    else
    {
        std::cout << "This is a static member function pointer" << std::endl;
    }
}

// Creating function pointer to member function
// ** Note: not putting class in own file because so small & small component of exercise
class A {
public:
    int fun1();
    int (A::* x)(); //declared saying what class it is a pointer to 
};

// declaring class fun1...doesn't really need to do much
int A::fun1() {
    std::cout << "Fun1 called \n";
    return 1;
}

// Part C: Is a shared pointer a pointer type? Is it a pointer type when 
//         converted to a raw pointer?
template <typename T>
void IsPointerPartC(const T& t)
{
    // checking if pointer 
    if (std::is_pointer<T>::value)
    {
        std::cout << "This is a pointer type argument\n";
    }
    else
    {
        std::cout << "_not_ a pointer type argument\n";
    }
}

int main()
{
    // Part A: Write a function to determine if a type is a pointer
    //         null pointers, lvalue reference or rvalue reference. 

    // Testing pointer 
    int x = 10;
    int *iptr; // initializing ptr
    iptr = &x; // assigning pointer 
    
    EvaluateType(iptr);
    
    // Testing Null Pointer
    EvaluateType(nullptr);

    // Testing lvalue 
    int lval = 10;
    EvaluateType<int&>(lval);

    // Testing rvalue 
    EvaluateType<decltype(std::move(lval))>(lval);

    // Part B: 
    int val = 20; 
    // static pointer variable declared
    // re-declaration is not done for static variables
    static int* stat_var; 
    stat_var = &val; 
    IsMemberFuncPointer(stat_var);

    // non static member function 
    A a;
    a.x = &A::fun1; 
    IsMemberFuncPointer(a.x); // use together with an object of its class

    // Part C:
    // Testing a shared pointer 
    std::shared_ptr<int>ptr1(new int); //created a shared ptr object that stores the pointer to the int obj
    std::shared_ptr<int>ptr2(ptr1); // second shared pointer obj will point to same ptr internally & ref count goes to 2
    IsPointerPartC(ptr1);
    IsPointerPartC(ptr2);
    // Outcome --> Shared pointers are not pointer types 

    // Testing a raw pointer 
    int inval = 10; 
    int* rawptr = &inval;
    IsPointerPartC(rawptr);
    // Outcome --> Raw pointers are pointer types 
}

