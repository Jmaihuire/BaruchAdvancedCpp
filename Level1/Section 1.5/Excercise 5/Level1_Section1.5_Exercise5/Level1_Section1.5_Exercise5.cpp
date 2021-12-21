// Level1_Section1.5_Exercise5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Part A) 
// Create derived classes Circleand Line.Create I / O device classes to display 
// CAD shapes in different ways.

// Part B)
// We wish to configure different shapes to work with various I / O devices.
// To this end, we create the well - known interface for the Builder pattern 
// but in this case the newly created objects are elements of a tuple :

#include <iostream>
#include<tuple>

// Forward declaring Class 
class IODevice;
class Circle;
class Line;
class Point;

// Base class for shape 
class Shape
{
public:
    virtual void display(IODevice& ioDevice) const = 0;
};

// Base Class for IODevice
class IODevice
{
    // Interface for displaying CAD objects
public:
    virtual void operator << (const Circle& c) = 0;
    virtual void operator << (const Line& c) = 0;
};

// Derived class circle 
class Circle: public Shape
{
public: 
    int center;
    int rad; 
    Circle(int c, int r) : center(c), rad(r) {};
    void display(IODevice& ioDevice) const override { ioDevice << *this; };

};

// Derived class line 
class Line : public Shape
{
public: 
    int center; 
    int leng; 
    Line(int c, int l) : center(c), leng(l) {}; 
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
};

// Derived class point 
class Point : public Shape
{
public: 
    // Default constructor 
    Point();
    Point(double new_x, double new_y);

    // Member Functions 
    double GetX(); // accessor 
    double GetY(); // accessor 
    double SetX(); // mutators 
    double SetY(); // mutators 

private:
    double xCoord, yCoord;
};

// IODevice Class was here prior 

class IODeviceA : public IODevice
{
    // interface for displaying CAD objects 
public: 
    
    // Part A: displaying CAD shape 
    void operator << (const Circle& c) override
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << c.center << " and Radius: " << c.rad << std::endl;
    };


    void operator << (const Line& c) override
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << c.center << " and Length: " << c.leng << std::endl;
    };

    void operator << (const Point& c) override
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << c. << " and Length: " << c.leng << std::endl;
    };
};
// Class shape was here 

int main()
{
    std::cout << "Hello World!\n";
}

