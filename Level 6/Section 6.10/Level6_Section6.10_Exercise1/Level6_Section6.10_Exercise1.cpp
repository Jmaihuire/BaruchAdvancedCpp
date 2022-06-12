// Level6_Section6.10_Exercise1.cpp 
// Fiona Ross 
// Visitor Pattern: Creating Visitor for Shape Hierarchy 

#include <iostream>

#include "Line.h"
#include "Circle.h"
#include "Point.h"
#include "ShapeComposite.h"
#include "PrintVisitor.h"


int main()
{
    // Test program where try to put composites into other composites to confirm the content of the composites are transversed correctly 

    // making the shapes/lines/points 
    Point pt1(10, 12);
    Point pt2(2, 8); // need two points to make a line 
    Line ln1(pt1, pt2); // line 
    Circle crcl(pt1, 8);

    // making the composite 
    ShapeComposite shpcomp;
    std::shared_ptr<Point> sptr = std::make_shared<Point>(pt1); 
    shpcomp.AddShape(sptr);

    std::shared_ptr<Point> sptr1 = std::make_shared<Point>(pt1); //im not sure if I actually need to add both points just being safe 
    shpcomp.AddShape(sptr1);

    std::shared_ptr<Line> sptr2 = std::make_shared<Line>(ln1);
    shpcomp.AddShape(sptr2);

    std::shared_ptr<Circle> sptr3 = std::make_shared<Circle>(crcl);
    shpcomp.AddShape(sptr3);

    // to add a composite into another composite just copying them and then adding them
    ShapeComposite shpcomp2(shpcomp); //the copying is very similar to copying vector/array
    std::shared_ptr<ShapeComposite> sptr4 =
        std::make_shared<ShapeComposite>(shpcomp); // basically same thing as above but now with ShapeComposite

    shpcomp2.AddShape(sptr4); //part of me wonders if you could just directly add sptr4 to shpcomp because would essentially be adding to itself...

    std::cout << "Shape Composite of shapes (line, circle, point): " << shpcomp
              << std::endl;

    std::cout << "Shape Composite of composite: " << shpcomp2
              << std::endl;



}
