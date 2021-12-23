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
#include<functional>

// Forward declaring Class 
class IODevice;
class Circle;
class Line;
class Rectangle;


// Base class for shape 
// this parses the common input into a reader class 
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
    virtual void operator << (const Rectangle& c) = 0;
};

// Builder derived classes are constructed for each target representation: 
// ie. Shape --> circle, line, rectangle 

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

// Derived class rectangle 
class Rectangle : public Shape
{
public: 
    int width; 
    int height;

public: 
    int rectangle(int w, int h)
    {
        width = 0;
        height = 0;
    }
    
    // Setters 
    int set_width(int w)
    {
        width = w;
    }
    int set_height(int h)
    {
        height = h;
    }

    // Calculations 
    int get_area()
    {
        return width * height;
    }

    int get_perimeter()
    {
        return 2 * (width + height);
    }

    void display(IODevice& ioDevice) const override { ioDevice << *this; };
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

    void operator<<(const Rectangle& c)
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Width: " << c.width<< " and Height: " << c.height << std::endl;
    };
};

class IODeviceB : public IODevice
{
    // interface for displaying CAD objects 
public:

    // Part A: displaying CAD shape 
    void operator << (const Circle& c) override
    {
        std::cout << "IODeviceB is on." << std::endl;
        std::cout << "Center: " << c.center << " and Radius: " << c.rad << std::endl;
    };


    void operator << (const Line& c) override
    {
        std::cout << "IODeviceB is on." << std::endl;
        std::cout << "Center: " << c.center << " and Length: " << c.leng << std::endl;
    };

    void operator<<(const Rectangle& c)
    {
        std::cout << "IODeviceB is on." << std::endl;
        std::cout << "Width: " << c.width << " and Height: " << c.height << std::endl;
    };
};

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

// the builder creates part of the complex object each time it is called and maintains 
// all intermediate state. When product is finished, the client retrieves the result 
// from the builder 
class Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    
    std::tuple<ShapePointer, IODevicePointer>getProduct() {
        std::make_tuple(getShape(), getIODevice());
    };

    // hook function that derived classes must implement
    virtual ShapePointer getShape() = 0;
    virtual IODevicePointer getIODevice() = 0;
};

class IODevACircleBuilder : Builder
{

public: 
    ShapePointer getShape() override {
        Circle circ(int c, int r);
    };

    IODevicePointer getIODevice() override {
        IODeviceA iodevA();
    }
    
};



int main()
{
    std::cout << "Hello World!\n";
}

Builder::Builder(Shape shape)
{
}
