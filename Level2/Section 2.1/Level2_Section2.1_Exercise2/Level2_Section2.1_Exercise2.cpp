// Level2_Section2.1_Exercise2.cpp 
/*  
    Fiona Ross - 02-01-2022
    Template Function that supports pointers and reference types. 
    For Pointers:
        dereferenced and then printed
    Non Pointer types:
        if scalar then printed directly
    Other Requirements:
        Use the is_pointer() function in conjunction with std::true_type and 
        std::false_type to determine which implementation should be called.
*/
#include <iostream>
#include <array>

template <typename T>
void IsPointer_impl(const T& t, std::true_type)
{
    // this function is called for a pointer (switch)
    std::cout << "Pointer argument impl: " << *t << std::endl;
};

// functions so if reference can print directly
template <typename T>
void PrintType(const T& t, std::true_type)
{
    std::cout << "Non-Pointer...printing output: " << t << std::endl;
};

// function so if not a scalar reference will not print
template <typename T>
void PrintType(const T&, std::false_type)
{
    std::cout << "Non sclalar reference type...not printing" << std::endl;
};

template <typename T>
void IsPointer_impl(const T& t, std::false_type)
{
    // this function is called for a non-pointer (switch)
    // instead of printing directly, calls PrintType in order to check
    // if inputs are scalar or not 
    PrintType<T>(t, std::is_scalar<T>());
};

template <typename T>
void IsPointer2_mod(const T& val)
{
    // main function that calls IsPointer depending on input arguments 
    IsPointer_impl(val, std::is_pointer<T>());
};

int main()
{
    // Testing Pointers:
     
    // Shared pointer 
    std::shared_ptr<int> ival(new int); 
    *ival = 200;  
    IsPointer2_mod(ival); 
    // Observations -> results in non-pointer scalar

    // Raw Pointer 
    IsPointer2_mod(ival.get()); //results in pointer 

    // De-referencing 
    IsPointer2_mod(*ival);
    // observations -> results in non-pointer scalar

    // Pointer 2 
    int ival2 = 100; //initializing object
    int* ptr2 = &ival2; // assigning pointer 
    std::array<int, 5> in_arr = { 2, 4,6,8,10 };

    // Testing bridge with pointer 
    IsPointer2_mod<int*>(ptr2); // observation -> pointer argument printed

    // Testing bridge with reference
    IsPointer2_mod<int>(ival2);  // observation -> non pointer 

    // Testing bridge with non scalar reference
    IsPointer2_mod<std::array<int, 5>>(in_arr); //observation -> non scalar not printing

}

