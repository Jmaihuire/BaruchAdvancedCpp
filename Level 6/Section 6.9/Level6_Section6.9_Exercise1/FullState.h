#pragma once
#include "StackState.h"
#include "Singleton.hpp"

class FullState :
    public StackState
{
    //let singleton be able to create instance
    friend class Singleton<FullState>;

private:
  
public:

    void Push(Stack* stack,const double& elem); //full state push function

    double Pop(Stack* stack); //full state pop function

    static FullState* Instance(); //use singleton to create new state instances
};

