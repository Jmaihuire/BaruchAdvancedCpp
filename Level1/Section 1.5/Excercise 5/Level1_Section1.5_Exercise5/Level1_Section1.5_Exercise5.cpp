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
#include <string.h>
#include <memory>

// Forward declaring Class 
class Shape;
class IODevice;
class IODeviceA;
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
    // default constructor 
    Circle() { center = 1; rad = 2; };

    // constructor 
    Circle(int c, int r) { center = c; rad = r; };

    // display 
    using Shape::display; 
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
    

};

// Derived class line 
class Line : public Shape
{
public: 
    int center; 
    int leng; 
    
    // default constructor 
    Line() { center = 1; leng = 3; };

    // constructor 
    Line(int c, int l) : center(c), leng(l) {}; 

    // display 
    using Shape::display;
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
};

// Derived class rectangle 
class Rectangle : public Shape
{
public: 
    int width; 
    int height;
    // default constructor
    Rectangle() { width = 1; height = 5; };

    // constructor 
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
    
    // display 
    using Shape::display;
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
};



class IODeviceA : public IODevice
{
    // interface for displaying CAD objects 
public: 

    // Part A: displaying CAD shape 
    using IODevice::operator<<;
    void operator << (const Circle& c)
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << c.center << " and Radius: " << c.rad << std::endl;
    };

    void operator << (const Line& c)
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << c.center << " and Length " << c.leng << std::endl;
    };

    void operator << (const Rectangle& c)
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



// the builder creates part of the complex object each time it is called and maintains 
// all intermediate state. When product is finished, the client retrieves the result 
// from the builder 

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

class Builder
{    
     // hook function that derived classes must implement
     virtual ShapePointer getShape() = 0;
     virtual IODevicePointer getIODevice() = 0;
     virtual std::tuple<ShapePointer, IODevicePointer> getProduct() = 0;
};

// Builder 1: combines Circle and IODevice A 
class Builder_1 : public Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    ShapePointer getShape() {
        std::shared_ptr<Circle> mys(new Circle);
        return mys;
    }
    
    IODevicePointer getIODevice() {
        std::unique_ptr<IODeviceA> myc(new IODeviceA);
        return myc;
    }

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        std::tuple<ShapePointer, IODevicePointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// Builder 2 : Circle and IODevice B
class Builder_2 : public Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    ShapePointer getShape() {
        std::shared_ptr<Circle> mys(new Circle);
        return mys;
    }

    IODevicePointer getIODevice() {
        std::unique_ptr<IODeviceB> myc(new IODeviceB);
        return myc;
    }

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        std::tuple<ShapePointer, IODevicePointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// Builder 3 : Line and IODevice A 
class Builder_3 : public Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    ShapePointer getShape() {
        std::shared_ptr<Line> mys(new Line);
        return mys;
    }

    IODevicePointer getIODevice() {
        std::unique_ptr<IODeviceA> myc(new IODeviceA);
        return myc;
    }

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        std::tuple<ShapePointer, IODevicePointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// Builder 4 : Line and IODevice B
class Builder_4 : public Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    ShapePointer getShape() {
        std::shared_ptr<Line> mys(new Line);
        return mys;
    }

    IODevicePointer getIODevice() {
        std::unique_ptr<IODeviceB> myc(new IODeviceB);
        return myc;
    }

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        std::tuple<ShapePointer, IODevicePointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// Builder 5: Rectangle and IODevice A
class Builder_5 : public Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    ShapePointer getShape() {
        std::shared_ptr<Rectangle> mys(new Rectangle);
        return mys;
    }

    IODevicePointer getIODevice() {
        std::unique_ptr<IODeviceA> myc(new IODeviceA);
        return myc;
    }

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        std::tuple<ShapePointer, IODevicePointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// Builder 6 : Rectangle and IODevice B
class Builder_6 : public Builder
{
    // A Builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    ShapePointer getShape() {
        std::shared_ptr<Rectangle> mys(new Rectangle);
        return mys;
    }

    IODevicePointer getIODevice() {
        std::unique_ptr<IODeviceB> myc(new IODeviceB);
        return myc;
    }

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        std::tuple<ShapePointer, IODevicePointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};


int main()
{   
    // Builder 1:  Circle + IODeviceA
    Builder_1 b1; // deligating a 2D cicle 
    ShapePointer circle_B1 = std::get<0>(b1.getProduct());
    IODevicePointer iodA_B1 = std::get<1>(b1.getProduct());
    (*circle_B1).display(*iodA_B1);

    // Builder 2:  Circle + IODeviceB
    Builder_2 b2;
    ShapePointer circle_B2 = std::get<0>(b2.getProduct());
    IODevicePointer iodB_B2 = std::get<1>(b2.getProduct());
    (*circle_B2).display(*iodB_B2);


    // Builder 3: Line + IODeviceA 
    Builder_3 b3; 
    ShapePointer circle_B3 = std::get<0>(b3.getProduct());
    IODevicePointer iodA_B3 = std::get<1>(b3.getProduct());
    (*circle_B3).display(*iodA_B3);

    // Builder 4: Line + IODeviceB
    Builder_4 b4;  
    ShapePointer circle_B4 = std::get<0>(b4.getProduct());
    IODevicePointer iodA_B4 = std::get<1>(b4.getProduct());
    (*circle_B4).display(*iodA_B4);

    // Builder 5: Rectangle + IODeviceA 
    Builder_5 b5;
    ShapePointer circle_B5 = std::get<0>(b5.getProduct());
    IODevicePointer iodA_B5 = std::get<1>(b5.getProduct());
    (*circle_B5).display(*iodA_B5);

    // Builder 6: Rectangle + IODeviceB 
    Builder_6 b6;
    ShapePointer circle_B6 = std::get<0>(b6.getProduct());
    IODevicePointer iodA_B6 = std::get<1>(b6.getProduct());
    (*circle_B6).display(*iodA_B6);
}

