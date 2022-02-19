// Level2_Section2.1_Exercise3.cpp : 
/*
Fiona Ross - 02-01-2022
Type Properties and Type Relationships 
Need to modify classes to answer following questions 
1. which class/types are empty/polymorphic or abstract 
2. Which classes are the same 
3. Which classes have gen/spec (base/derived) relationship
4. Which types can be converted to each other 
*/
#include <iostream>

class Shape
{
public:
    virtual void draw() = 0;
};

class Base
{
private:
    static int y;
public:
    Base() {}
    void draw() {}
};

class Point: public Shape
{
public:
    Point() {}
    virtual void draw() override {}
};

// Making print statement to print out answers
template <typename T>
void EvalStatmentQA(const T& t)
{
    // this the function input is true
    std::cout << "Is a class with no data? " << std::boolalpha << std::is_empty<T>::value << std::endl;
    std::cout << "Polymorphic class type? " << std::boolalpha << std::is_polymorphic<T>::value << std::endl;
    std::cout << "Abstract class type? " << std::boolalpha << std::is_abstract<T>::value << std::endl;

    std::cout << "End *************** \n";
}

// Making print statement to print out answers
template <typename T>
void EvalStatmentQB(const T& t1, const T& t2)
{
    // this the function input is true
    std::cout << "Are these classes the same? " << std::boolalpha << std::is_same<T,T>::value << std::endl;
    std::cout << "End *************** \n";
}

int Base::y = 10;
int main()
{
    Base* base1;
    Shape* shape1;
    Point* point1;

    // 1. Which classes/types are empty / polymorphic or abstract 
    std::cout << "Evaluating Base Class: \n"; 
    EvalStatmentQA(base1);

    std::cout << "Evaluating Shape Class: \n";
    EvalStatmentQA(shape1);

    std::cout << "Evaluating Point Class: \n";
    EvalStatmentQA(point1);

    // 2. Which classes are the same?
    std::cout << "\n*** Evaluating What Classes are the same: **** \n";
    std::cout << "Base, Shape: " << std::boolalpha << std::is_same<Base, Shape>::value << std::endl;
    std::cout << "Base, Point: " << std::boolalpha << std::is_same<Base, Point>::value << std::endl;
    std::cout << "Point, Shape: "<< std::boolalpha << std::is_same<Point, Shape>::value << std::endl;
 
    // 2. Which classes have a gen/spec (base/derived) relationship?
    std::cout << "\n*** Evaluating What Classes are base/derived: **** \n";
    std::cout << "Base 2 Shape: " << std::boolalpha << std::is_base_of<Base, Shape>::value << std::endl;
    std::cout << "Shape 2 Base: " << std::boolalpha << std::is_base_of<Shape, Base>::value << std::endl;
    std::cout << "Point 2 Shape: " << std::boolalpha << std::is_base_of<Point, Shape>::value << std::endl;
    std::cout << "Shape 2 Point: " << std::boolalpha << std::is_base_of<Shape, Point>::value << std::endl;
    std::cout << "Base 2 Point: " << std::boolalpha << std::is_base_of<Base, Point>::value << std::endl;
    std::cout << "Point 2 Base: " << std::boolalpha << std::is_base_of<Point, Base>::value << std::endl;

    // 4. Which types can be converted to each other??
    std::cout << "\n*** Evaluating What Classes can be converted: **** \n";
    std::cout << "Base 2 Shape: " << std::boolalpha << std::is_constructible<Base, Shape>::value << std::endl;
    std::cout << "Shape 2 Base: " << std::boolalpha << std::is_constructible<Shape, Base>::value << std::endl;
    std::cout << "Point 2 Shape: " << std::boolalpha << std::is_constructible<Point, Shape>::value << std::endl;
    std::cout << "Shape 2 Point: " << std::boolalpha << std::is_constructible<Shape, Point>::value << std::endl;
    std::cout << "Base 2 Point: " << std::boolalpha << std::is_constructible<Base, Point>::value << std::endl;
    std::cout << "Point 2 Base: " << std::boolalpha << std::is_constructible<Point, Base>::value << std::endl;

};

