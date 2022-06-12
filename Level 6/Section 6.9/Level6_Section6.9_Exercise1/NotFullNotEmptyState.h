#pragma once
#include "StackState.h"
#include "Singleton.hpp"

class NotFullNotEmptyState :
    public StackState
{
    //let singleton be able to create instance
    friend class Singleton<NotFullNotEmptyState>;

private:
    //NotFullNotEmptyState();
    //NotFullNotEmptyState(const NotFullNotEmptyState& source);
    //NotFullNotEmptyState& operator = (const NotFullNotEmptyState& source);

public:

    void Push(Stack* stack,const double& elem); //not full not empty push function

    double Pop(Stack* stack); //not full not empty pop function

    static NotFullNotEmptyState* Instance(); //use singleton to create new states
};

