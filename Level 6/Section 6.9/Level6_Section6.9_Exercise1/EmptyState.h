#pragma once
#include "StackState.h"
#include "Singleton.hpp"

class EmptyState :
    public StackState
{
//let singleton be able to create instance
friend class Singleton<EmptyState>;

private:

public:

    void Push(Stack* stack, const double& elem); //empty state push function

    double Pop(Stack* stack); //empty state pop function

    static EmptyState* Instance(); //use singleton to create instance

};

