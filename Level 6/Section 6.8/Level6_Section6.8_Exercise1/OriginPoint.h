#ifndef OriginPoint_hpp
#define OriginPoint_hpp

#include "Singleton.hpp"

class OriginPoint :
    public Singleton<Point>
{

public:
//    //PART A: derived originpoint sub class
//
//    //Pulling some from forum
    OriginPoint() {};//default constructor

    OriginPoint(const OriginPoint& source) = delete;//copy constructor

    OriginPoint& operator = (const OriginPoint& source) = delete;//assignment operator


};

#endif