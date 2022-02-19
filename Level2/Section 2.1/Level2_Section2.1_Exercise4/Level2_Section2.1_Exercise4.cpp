// Level2_Section2.1_Exercise4.cpp : 
/*
Fiona Ross - 02-05-2022

a) Programmatically determine if type Point has a virtual destructor.

b) Programmatically determine if type Pointhas the following constructors: default, copy, move.

c) Programmatically determine if type Point is copy assignable/move assignable.

d) Set the copy constructor and assignment operator as ‘deleted functions’ and perform steps b)-c) again; do you get the same result?

e) Add move semantics code (explicit move constructor and move assignment operator) and perform steps b)-c) again; do you get the same result?

*/
#include <iostream>
class Shape
{
public:
    virtual void draw() = 0;
};

class Point : public Shape
{
public:
    Point() {}

    // Part C: Copy constructor & assignment operator as deleted functions
    // ------------------------------------------------------------------- 
    // Point() = delete; // explicitly telling constructor to be deleted
    // Point(Point const&) = delete; // explicitly telling constructor to be deleted

    // the move operator should be implicitly delete because constructor is delete but 
    // will explicitly state it below 
    // Point(Point&&) = delete;
    // Point& operator=(const Point&) = delete;
    

    // Part D: Move semantics code (explicit move constructor & move assignment operator)
    // --------------------------------------------------------------------------
    Point(Point&&) = default;
    Point& operator=(const Point&) = default;

    virtual void draw() override {}

};

int main()
{
    Shape* shape1;
    Point* point1;
    // a) Programmatically determine if type Point has a virtual destructor.
    std::cout << "\n*** Virtual Destructor? : **** \n";
    std::cout << "Point: " << std::boolalpha << std::has_virtual_destructor<Point>::value << std::endl;
    // result is False 
    
    // b) Programmatically determine if type Point has default constructor, move, copy .
    std::cout << "\n*** Default constructor? : **** \n";
    std::cout << "Point: " << std::boolalpha << std::is_default_constructible<Point>::value << std::endl;
    // result is True

    std::cout << "\n*** Default move? : **** \n";
    std::cout << "Point: " << std::boolalpha << std::is_move_constructible<Point>::value << std::endl;
    // result is True 

    std::cout << "\n*** Default copy? : **** \n";
    std::cout << "Point: " << std::boolalpha << std::is_copy_constructible<Point>::value << std::endl;
    // result is True
    
    // c) Programmatically determine if type Point is copy assignable/move assignable.
    std::cout << "\n*** Copy assignable? : **** \n";
    std::cout << "Point: " << std::boolalpha << std::is_copy_assignable<Point>::value << std::endl;
    // result is True

    std::cout << "\n*** move assignable? : **** \n";
    std::cout << "Point: " << std::boolalpha << std::is_move_assignable<Point>::value << std::endl;
    // result is True
    
    // d) Set the copy constructor and assignment operator as ‘deleted functions’ and perform steps b)-c) again; do you get the same result?
    // Just re-ran program above and the following results were found:
    
    //      default destructor --> False (this is the same)
    //      default constructor --> False (this is different from the original)
    //      default move --> False (this is different from the original)
    //      default copy --> False (this is different from the original)
    //      copy assignable --> False (this is different from the original)
    //      move assignable --> False (this is different from the original)
   
    // e) Add move semantics code(explicit move constructor and move assignment operator)
    //    and perform steps b) - c) again; do you get the same result ?
    
    //      virtual destructor -->  False (this is the same as the original)
    //      default constructor --> True (this is the same as the original)
    //      default move --> True (this is the same as the original)
    //      default copy --> False (this is different from the original)
    //      copy assignable --> True (this is the different from before)
    //      move assignable --> True (this is the different from before)
}    

