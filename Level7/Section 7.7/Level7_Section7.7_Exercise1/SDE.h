#pragma once
#include <memory>
#include "OptionData.h"
class SDE 

    // Changed types from data to double just for simplicity
{ 

private:

    // data is the options data 
    std::shared_ptr<OptionData> data; 

public:

    SDE(const OptionData& optionData) : data(new OptionData(optionData)) {}

    double drift(double t, double S)

    { // drift is essentially r-d 

        return (data->r - data->D) * S; 

    }

    double diffusion(double t, double S)

    {

        return data->sig * S;

    }

};