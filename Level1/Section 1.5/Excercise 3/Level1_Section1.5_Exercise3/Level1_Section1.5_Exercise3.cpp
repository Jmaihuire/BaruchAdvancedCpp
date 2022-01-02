// Level1_Section1.5_Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* 
Exercise 3: Application II, Tuples as Return Types of Functions

Part A) Create a function that returns the following statistical properties 
of a numeric vector as a tuple: mean, mean deviation, range 
(the difference between the largest and smallest numbers in the vector), 
standard deviation and variance.
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/io.hpp>
//#include <boost/numeric/ublas/assignment.hpp> 

// Part A) created statistical function that returns the statistical properties
//         mean, mean dev, range, std dev, variance

// *** do we need to do the same thing for this using boost::numeric::ublas::vector? ***
typedef std::vector<double> Vector;

template <typename T, typename Vec,typename Tuple, std::size_t N>
struct StatCalc
{
    // Statistical Properties 
    static Tuple statProp(const Vec& inVec)
    {
        // mean 
        if (inVec.empty()) {
            std::cout << "Vector is empty\n";
        }

        T mean = (std::accumulate(inVec.begin(), inVec.end(),0) / (static_cast<T>(N)));
        std::cout << "Mean is: " << mean << std::endl;

        // mean deviation
        // formula: 1/n * sum(x-mean(X)) where mean(X) is the mean of the dataset
        // inVec is a constant so need to make a local copy
        Vec inVecTmp = inVec;
        for (int i = 0; i < inVec.size(); i++) { inVecTmp[i] = inVec[i] - mean; }
        T meanDev = (std::accumulate(inVecTmp.begin(), inVecTmp.end(),0) / (static_cast<T>(N)));
        std::cout << "Mean Deviation is: "<< meanDev << std::endl;

        // range (difference between largest and smallest numbers)
        std::sort(inVecTmp.begin(), inVecTmp.end());
        T range = inVecTmp.back() - inVecTmp.front();
        std::cout << "Range is: " << range << std::endl;

        // standard deviation 
        T accum = 0;
        std::for_each(std::begin(inVec), std::end(inVec), [&](T x) {
            accum += (x - mean) * (x - mean);
            });
        T stdev = std::sqrt(accum / static_cast<T>(N));
        std::cout << "Standard Deviation is: " << stdev << std::endl;
        
        // variance 
        T var = std::sqrt(stdev);
        std::cout << "Variance is: " << var << std::endl;

        // Populating Tuple for output 
        Tuple tupleOut = std::make_tuple(mean, meanDev, range, stdev, var);
        return tupleOut;

    }

}; // end struct StatCalc

// Part C) A function that computes the median & mode 
//         of a sorted vector. If there are two contenders, 
//         the smaller value is chosen. 

template <typename T, typename Vec, typename Tuple, std::size_t N>
struct getMiddle
{
    // Statistical Properties 
    static Tuple meanMode(const Vec& inVec)
    {
        // Mode
        Vec inVecTmp = inVec; //inVec is a constant vector so have to make tmp to change it
        std::sort(inVecTmp.begin(), inVecTmp.end()); // sort the vector 

        T tgtNum = inVecTmp[0];
        T mode = inVecTmp[0];
        int cnt = 1;
        int cntMode = 1;

        for (int i = 2; i < inVecTmp.size(); i++)
        {
            if (inVecTmp[i] == tgtNum)
            {
                // counting how many times current number exists 
                ++cnt;
            }
            else
            {
                // moving on to next number in array 
                if (cnt > cntMode)
                {
                    // don't need to include an extra loop to ensure if two numbers have equal occurances 
                    // the smaller number is chosen because if the vector 
                    cntMode = cnt; // mode is the most occurance 
                    mode = tgtNum;
                }
                cnt = 1;
                tgtNum = inVecTmp[i];
            }
        } // end iteration through vector 
        std::cout << "Mode is: " << mode << std::endl;

         //  Median 
         // inVec is already sorted from Mode 
         // if even number of elements in vector its the smaller value so index = (inVec.size()/2)
         // if odd number of elements in vector its index = (inVec.size() / 2) and just use the quotent 
        T median;
        int numElemVec =(static_cast<int>(N) % 2);

            if (numElemVec == 0) // if there is no remainder then even number of elements in vector 
        {
            std::size_t idx = (static_cast<int>(N) / 2);
            median = inVecTmp.at(idx);
        }
        else
        {
            div_t divRes = div(static_cast<int>(N), 2);
            median = inVecTmp.at(divRes.quot);
        }
            std::cout << "Median is: " << median << std::endl;
        
            // Populating Tuple for output 
        Tuple tupleOut = std::make_tuple(mode, median);
        return tupleOut;
    } // end meanMode

}; // end getMiddle 


        // creating a print function to output tuple 
        template<std::size_t I = 0, typename... Tp>
        inline typename std::enable_if<I == sizeof...(Tp), void>::type
            print(std::tuple<Tp...>&t)
        { }

        template<std::size_t I = 0, typename... Tp>
        inline typename std::enable_if < I < sizeof...(Tp), void>::type
            print(std::tuple<Tp...>& t)
        {
            std::cout << std::get<I>(t) << std::endl;
            print<I + 1, Tp...>(t);
        }


        int main()
        {
            // Part A: Using std::vector 
            // 
            // Three element vector
            std::cout << "Four element vector: \n";
            const std::size_t N = 4;
            Vector v4(N);
            int val = 3;
            std::for_each(v4.begin(), v4.end(), [&val](double& j) {j = val++; });
            using dblTupType3 = std::tuple <double, double, double, double, double>;
            dblTupType3 v4Out = StatCalc<double, std::vector<double>, dblTupType3, N>::statProp(v4);

            // Printing contents of vector 
            std::cout << "\nTuple print output is: " << std::endl;
            print(v4Out);

            // Part A: Using boost::numeric::ublas::vector
            // **** Boost include is not working since have vs2019 and boost 1_63_0 
            // **** Need to get vs2017 and boost 1_70_0 to get it to work properly 

            //std::cout << "Four element boost vector: \n";
            //namespace boost = boost::numeric::ublas;
            //boost::vector<double, std::vector<double>> vecBoost = std::move(v4); 
            //const boostU::c_vector<double,bvN> bv4 = boostA::list_of(3.0)(2.5)(10.3)(4.0);

            //std::for_each(bv4.begin(), bv4.end(), [&bv4Val](double& m) {m = boostA::list_of(bv4Val++); });
            //using dblTupType3 = std::tuple <double, double, double, double, double>;
            //dblTupType3 bv4Out = StatCalc<double, boostU::vector<double>, dblTupType3, N>::statProp(bv4);

            // Printing contents of vector 
            //std::cout << "\nTuple print output is: " << std::endl;
            //print(bv4Out);

            // Part B) Tying tuple objects for easier code readability 
            double meanOut, rangeOut, varOut;
            std::tie(meanOut, std::ignore, rangeOut, std::ignore, varOut) = v4Out; // unpacking tuples into variables

            std::cout << "\nGetting only relevant outputs: \nmean is: " << meanOut << "\nrange is: " << rangeOut << "\nvariance is: " << varOut << std::endl;

            //// Part C) A function that computes the median & mode 
            std::cout << "\nFour element vector getting median/mode: \n";
            const std::size_t M = 4;
            Vector b4(M);
            double val4 = 3;
            std::for_each(b4.begin(), b4.end(), [&val4](double& k) {k = val4++; });
            using dblTupType4 = std::tuple <double, double>;
            dblTupType4 b4Out = getMiddle<double, std::vector<double>, dblTupType4, M>::meanMode(b4);

            // Printing contents of vector 
            std::cout << "\nTuple print output is: " << std::endl;

             double modeOut, medianOut;
             std::tie(modeOut, medianOut) = b4Out; // unpacking tuples into variables
             std::cout << "\nGetting only relevant outputs: \nmode is: " << modeOut << "\nmedian is: " << medianOut << std::endl;

        }


