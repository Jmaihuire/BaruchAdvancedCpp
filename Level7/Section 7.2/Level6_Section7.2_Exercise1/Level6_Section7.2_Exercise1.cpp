// Level6_Section7.2_Exercise1.cpp 

#include <iostream>
#include "Shape.h"
#include "Factory.h"
#include "ConsoleShapeFactory.h"
#include "Line.h"
#include "Circle.h"
#include "ExactDistance.h"

// Part B: 
// For part B need to instantiate using a function object so made one that makes a
// a constant distanced line and returns that distance

// this mini class is essentially pulled from the real line class 
class constLine
{
 private:
  Point p1_;
  Point p2_;

 public:
  constLine(Point pt1s,Point pt2s) : p1_(pt1s), p2_(pt2s){};
  
  std::shared_ptr<Line> operator()() {
    Line const_line(p1_, p2_);
    return std::make_shared<Line>(const_line);
  }
};


int main()
{
    // Part A: 
    
    // These functions were grabbed from the ConsoleShapeFactory previous code. 
    Factory* factory = new Factory(ConsoleShapeFactory::CreateCircle,
                                   ConsoleShapeFactory::CreatePoint,
                                   ConsoleShapeFactory::CreateLine);

    // Had to change inputs but rest of this is previous code 
    
    // Assigning and making Point
    std::shared_ptr<Point> point = factory->CreatePoint();

    // Assigning and making circle
    std::shared_ptr<Circle> circle = factory->CreateCircle();

    // Assigning and making line 
    std::shared_ptr<Line> line = factory->CreateLine();

    // PART B
    //  // Instantiating the factory method using lambda functions, function objects and std::bind
    // ie. we are essentially just redefining these so they are in the same factory to make code more concise
 
    // Lambda function implimentation 
    auto cline_lambda = []() {
      Point p1(2, 3);
      Point p2(3, 6);
      return constLine(p1, p2)();
    };  

    // Now we need to make the lambda function into the builder 
    factory->AssignLineBuilder(
        cline_lambda);  
    std::cout << "Printing Line from Lambda: " << *factory->CreateCircle();

    Point p1(2, 3);
    Point p2(3, 6);
    auto cline = constLine(p1,p2);

    // This makes the function object and turns it into a builder 
    factory->AssignLineBuilder(cline); 
    std::cout << "Line Output: " << *factory->CreateLine();

    

    // Part C: 
    // Question: consider the suitability of this design to other pattern such as Strategy and Command? 
    //           How does the new design compare with the corresponding GOF design?
    // Benefits: 
    // Less coupling so code overall is more flexible and easy to impliment for different use cases 
    // Another reason why more flexible is because you don't need as many executes()

    // PART D:
    // Example packing factory into new factory with values for Point:
    double pt3_x = 1;
    double pt3_y = 2;
    double pt4_y = 3; 
    double pt4_x = 4; 
    Point pt3(pt3_x, pt3_y);
    Point pt4(pt4_x, pt4_y);
    auto lambdaLineMaker = [&pt3, &pt4, &factory]() {
      auto l_out = factory->CreateLine();
      Line ln(pt3, pt4);
      l_out = std::make_shared<Line>(ln);
      return l_out;
    };
    std::cout << "Lambda circle builder: " << *lambdaLineMaker();

    // Worked off this as an example but obviously needed modification 
    //Pointer<ProductFactoryModel_A> factory(new ProductFactoryModel_A());
    //short val = 3;
    //// auto facP1= [val](){ return Pointer<P1>(new P11(val)); };
    //auto facP1 = [&val, &factory]() {
    //  auto p1 = factory->CreateP1();
    //  p1->data = val;
    //  return p1;
    //};
}

