// Level1_Section1.5_Exercise4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Exercise 4: Adapters for STL algorithms
a) Given a sorted numeric vector v and a target value x ,
   find the first index i, such that:?
        v[i] <= x < v [i+1]?
   Determine the return type.

b) Find the maximum error between two vectors v1 and v2 in a given index range [i; j] .
We wish to compute the difference in some (customisable) norm, specifically the
absolute error, relative error and the index values where these errors occur.
Use:
1. move semantics instead of copy constructors
2. smart pointers
3. function objects and lambda functions
4. STL algorithms

*/

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iterator>

template <typename T, typename Vec, typename Return_t>
struct useAdapters
{
    // Statistical Properties 
    static Return_t numAnalysis(const Vec& inVec, T tgtVal, std::size_t N)
    {
        // Part A) sorted numeric vector v and a target value x , 
        //         find the first index i, such that: v[i] <= x < v[i + 1]?

        // Change N to an int M so can use for indexing 
        int M = static_cast<int>(N);
        // first sort vector in case not sorted 
        Vec inVecTmp = inVec; // making local copy since const 
        std::sort(inVecTmp.begin(), inVecTmp.end());

        // Printing contents of vector
        std::cout << "Vector is: "; 
        for (size_t i = 0; i < inVecTmp.size(); ++i) {std::cout << inVecTmp.at(i) << "; "; }

        // first check if the target value (x) exists in the vector
        if (std::find(inVecTmp.begin(), inVecTmp.end(), tgtVal) != inVecTmp.end())
            // since target exists can work to finding i-1 and i+1 
        {
            // checking to see if there are multiple target values 
            std::cout << "entered if loop" << std::endl;
            auto lBnd = std::find(inVecTmp.begin(), inVecTmp.end(), tgtVal);
            auto nxtVal = std::find(inVecTmp.begin(), inVecTmp.end(), tgtVal);
           
            if (nxtVal != inVecTmp.end())
            {
                // setting upper bound the same as lower bound and then will increment
                auto uBnd = std::find(inVecTmp.begin(), inVecTmp.end(), tgtVal); 
                // Part B) if multiple target values use distance to find how many  
                auto uTgt = std::upper_bound(lBnd, inVecTmp.end(), tgtVal);
                // finding the number of tgt values using distance (returns an int) 
                int dist = std::distance(lBnd, uTgt);
                // increasing lBnd by the number of tgt values to get upper bound  
                std::advance(uBnd, dist); 
            }
            return 0.0;
        }

        else if ((inVecTmp[0] <= tgtVal) && (inVecTmp[M - 1] > tgtVal)) // if target does not exist then need to see if target value is btwn vector values 
        {
            std::cout << "entered else loop" << std::endl; 
           

            // find what indexes it is inbetween 
            for (int i = 1; i < M ; i++) //iterator through finding min distance value 
            {
                std::cout << "\ni is: " << i;
                std::cout << "\nM is: " << M;
                
                // checking to see if the target value is in range & if so find upper & lower bound 
                if (tgtVal - inVecTmp[i-1] >= 0 && tgtVal - inVecTmp[i] <= 0)
                {
                    T Lbnd = inVecTmp[i - 1];
                    T Ubnd = inVecTmp[i];
                    int Lidx = i-1;
                    std::cout << "\nTarget is: " << tgtVal;
                    std::cout << "\nLower bound is: " << Lbnd; 
                    std::cout << "\nUpper bound is: " << Ubnd;
                    std::cout << "\nIndex is: " << Lidx; 
                }
                // Do not need to check for multiple values
            }
            return 0.0;       
        }


        //
       
        //int* p; // pointer 
        //p = std::find(inVecTmp.begin(), inVecTmp.end()-1, tgtVal);
        //if (p != inVecTmp.end() - 1)
        //    return inVecTmp.end(); 

        //

        
    }
};

int main()
{

    // creating use case where target value exists 
    std::cout << "\nFour element vector tgt exists: \n";
    const std::size_t M = 4;
    std::vector<double> b4(M);
    double val4 = 3;
    std::vector<double> incr = { 0.1, 1.8, 1, 1};
    int j = 0;
    std::for_each(b4.begin(), b4.end(), [&val4, &incr, &j](double& k) {k = val4 + incr[j]; j++; });
    double tgtExst = 4; 
        
    double b4Out1 = useAdapters<double, std::vector<double>, double>::numAnalysis(b4, tgtExst, M);

    // creating use case where target value is between elements in vector
    std::cout << "\nFour element vector tgt is btwn elements: \n";
    double tgtBtwn = 4.5;
    double b4Out2 = useAdapters<double, std::vector<double>, double>::numAnalysis(b4, tgtBtwn, M);

}
