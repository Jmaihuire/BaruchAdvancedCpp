// Level2_Section2.5_Exercise1.cpp 
// Fiona Ross - 03-04-2022

/*
Floating point arithmetic & examining round off error

*/
#include <iostream>
#include <cmath>

template <typename T>
const char* Classify(T t)
{
    switch (std::fpclassify(t))
    {
    case FP_INFINITE:  return "Inf";
    case FP_NAN: return "NaN";
    case FP_NORMAL:    return "normal";
    case FP_SUBNORMAL: return "subnormal";
    case FP_ZERO: return "zero";
    default:  return "unknown";
    }
}

template <typename T>
const char* TestVals(T t)
{
    // Testing 3 test cases seperately because one type might fullfill multiple categories
    if (std::isfinite(t))
    {
        return "is finite";
    }

    if (std::isinf(t))
    {
        return "is infinite";
    }

    if (std::isnan(t))
    {
        return "is NAN";
    }

    if (std::isnormal(t))
    {
        return "is normal";
    }
}

int main()
{

    // Part A: 
    double val = std::numeric_limits<double>::max(); // classified as normal 
    std::cout << "Classify val, the numeric limit of the max of a double: " << Classify(val) << std::endl;
    2.0 * val; // Inf
    std::cout << "Classify val, the numeric limit (2.0 * val) + 3.145: " << Classify(2.0 * val) << std::endl;
    3.1415 + val; // normal 
    std::cout << "Classify val, the numeric limit 3.145 + (2.0 * val): " << Classify(3.1415 + val) << std::endl;
    double val2 = std::numeric_limits<double>::min() - 3.1415; // normal 
    std::cout << "Classify val2, the numeric limit min - 3.1415: " << Classify(val2) << std::endl;
    val2 / 2.0; // normal 
    std::cout << "Classify val2, the numeric limit min / 2.0 " << Classify(val2/2.0) << std::endl;
    DBL_MIN / 2.; // subnormal
    std::cout << "Classify DBL_MIN / 2: " << Classify(DBL_MIN / 2) << std::endl;

    // Part B: 
    double factor = 2.0; // is finite 
    std::cout << "Classify double factor = 2.0 : " << TestVals(factor) << std::endl; 
    val = factor * std::numeric_limits<double>::max(); // is infinite 
    std::cout << "Classify factor * numeric limit double max: " << TestVals(factor * std::numeric_limits<double>::max()) << std::endl;
    val - val; // is NAN
    std::cout << "Classify val - val: " << TestVals(val - val) << std::endl;
    std::sqrt(-1.0); // is NAN
    std::cout << "Classify sqrt(-1.0): " << TestVals(std::sqrt(-1.0)) << std::endl;
    std::log(0.0); // is infinite
    std::cout << "Classify log(0.0): " << TestVals(log(0.0)) << std::endl;
    std::exp(val); // is inf 
    std::cout << "Classify exp(val): " <<std::exp(val) << std::endl;
}


