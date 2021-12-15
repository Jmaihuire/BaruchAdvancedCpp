//// Level1_Section1.5_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//// Exercise Resources: 
//// https://dzone.com/articles/variadic-template-c-implementing-unsophisticated-t
//
#include <iostream>
#include <tuple>
#include <complex>
//
//// Defining a variadic template function 
//
//// Sum Function 
//
//// Complex Sum Function 
//
//
//template <typename T, typename Tuple, std::size_t N>
//struct Calculator
//{
//    //static std::complex<T> complex_sum(const Tuple& tuple)
//    //{
//    //    T tmp = Calculator<std::complex<T>, Tuple, N - 1>::complex_sum(tuple);
//    //    T real_tmp = tmp.real();    // getting the real portion of the number
//    //    real_tmp += std::get<N - 1>(tuple).real();
//    //    T img_tmp = tmp.imag();
//    //    img_tmp += std::get<N - 1>(tuple).imag();
//
//    //    static T ret(real_tmp, img_tmp);
//    //    return ret;
//    //}
//    static T sum(const Tuple& tuple)
//    {
//        T tmp = Calculator<T, Tuple, N - 1>::sum(tuple);
//        T ret_tmp = tmp + std::get<(N - 1)>(tuple);
//        return ret_tmp;
//    }
//
//};
////    static T maximum(const static Tuple& pack, std::size_t N) {
////        //Checking that more than one element in the tuple 
////        if (N == 1)
////        {
////            return std::get<N>(pack);
////        }
////
////        else
////        {
////            // format (a<b?a:b) where if a<b return a | if a > b return b
////            return (std::get<N>(pack) < std::get<N - 1>(pack) ? std::get<N>(pack) : std::get<N - 1>(pack));
////        }
////        print(pack, N);
////    };
////
////
////};
//    
//        
//
////template <typename T, typename Tuple, std::size_t N>
////struct Calculator
////{ 
////    static T maximum(T, const static Tuple& pack, std::size_t N)
////
////        // This iterates and does comparison  
////    {
////        if (N == 1)
////        {
////            return std::get<N>(pack)
////        }
////        else
////        {
////            return maximum();
////        }
////        
////    }
////       
////};
//
////template<typename Tuple, std::size_t N>
////static void print(const Tuple& pack, std::size_t N)
////{
////    std::cout << std::get<N - 1>(pack) << "," << std::endl;
////}
////
////template<typename Tuple, std::size_t >
////struct TuplePrinter
////
////{  
////    static void print(const Tuple& pack, std::size_t N)
////    {
////        if (N == 1)
////        {
////            return;
////        } 
////        else
////        {
////            TuplePrinter<Tuple, N - 1>::print(pack);
////            
////        }
////       
////    }
////};
//
//int main()
//{
//    //using TD2 = std::tuple<double, double>;
//    //using CD2 = Calculator<double, TD2, 2>;
//    //TD2 td2_1(100, 10); //instance
//    //std::cout << CD2::maximum(td2_1, 2) << std::endl; //call Sum function
//
//    // Complex Sum 
//    //std::complex<int> c1(1, 1);
//    //std::complex<int> c2(2, 3);
//    //using tupTyp = std::tuple < std::complex<int>, std::complex<int>>;
//    //tupTyp c_tuple{ c1,c2 };
//    //using calTyp = Calculator<std::complex<int>, tupTyp, 2>; 
//    //std::cout << calTyp::complex_sum(c_tuple) << std::endl;
//
//    // Sum 
//    int b1(1);
//    int b2(2);
//    /*using intTupType = std::tuple <int, int>;*/
//    std::tuple<int,int> i_tuple{ 1,2 };
//    /*using intCalType = Calculator<int, const intTupType&, 2>;*/
//    std::cout << Calculator<int, std::tuple<int,int>,2>::sum(i_tuple);
//
//}


template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
    // Max 
    static T max(const Tuple& inTuple)
    {
        if (std::get<N - 1>(inTuple) > Calculator<T, Tuple, N - 1>::max(inTuple))
        {
            T max = std::get<N - 1>(inTuple) ;
            return max;
        }
        else {
            T max = Calculator<T, Tuple, N - 1>::max(inTuple);
            return max;
        }  

    }

    // Sum
    static T sum(const Tuple& inTuple)
    {
        T sum = std::get<N - 1>(inTuple) + Calculator<T, Tuple, N - 1>::sum(inTuple);
        return sum;
    }

    // Average 
    static T avg(const Tuple& inTuple)
    {
        T total = sum(inTuple);
        T avg = total / (static_cast<T>(N));
        return avg;
    }
    
    
};

// Ending function for recursion purposes 
template <typename T, typename Tuple>
struct Calculator<T,Tuple,1>
{
    // Max 
    static T max(const Tuple& input) 
{
        T max = std::get<0>(input);
        return max;
}  // end max for recursion 

    static T sum(const Tuple& input)
    {
        T sum = std::get<0>(input);
        return sum;
    } // end sum for recursion 

}; // end calc struct for recursion 


  
int main()
{
    // Part B: Test code on tuples with two and three elements whose underlying 
    //         type is double

    // Two Element Tuple
    std::cout << "Two element tuple: \n";

    using dblTupType2 = std::tuple <double, double>;
    dblTupType2 b2 = {102.1 , 1021.0 };
    const std::size_t tupleSize_b2 = std::tuple_size<dblTupType2>();

    // Max 
    double maxVal_b2 = Calculator<double, dblTupType2, tupleSize_b2>::max(b2);

    // Sum 
    double sumVal_b2 = Calculator<double, dblTupType2, tupleSize_b2>::sum(b2);

    // Average 
    double avgVal_b2 = Calculator<double, dblTupType2, tupleSize_b2>::avg(b2);

    // Outputting values
    std::cout << "Max is: " << maxVal_b2 << std::endl;
    std::cout << "Sum is: " << sumVal_b2 << std::endl;
    std::cout << "Average is: " << avgVal_b2 << std::endl;

    // Three element tuple 
    std::cout << "\nThree element tuple\n";
    using dblTupType3 = std::tuple <double, double, double>;
    dblTupType3 b3 = {10.2, 102.1 , 1021.0 };
    const std::size_t tupleSize_b3 = std::tuple_size<dblTupType3>();

    // Max 
    double maxVal_b3 = Calculator<double, dblTupType3, tupleSize_b3>::max(b3);
    
    // Sum 
    double sumVal_b3 = Calculator<double, dblTupType3, tupleSize_b3>::sum(b3);

    // Average 
    double avgVal_b3 = Calculator<double, dblTupType3, tupleSize_b3>::avg(b3);

    // Outputting values
    std::cout << "Max is: " << maxVal_b3 << std::endl;
    std::cout << "Sum is: " << sumVal_b3 << std::endl;
    std::cout << "Average is: " << avgVal_b3 << std::endl;

    // Part C: Sum and average of tuple using complex numbers 
    std::cout << "\nComplex Elements: \n"; // Three elements 
    using cplxTupType = std::tuple<std::complex<int>, std::complex<int>>;
    std::complex<int> cplx1(1, 6);
    std::complex<int> cplx2(3, 2);
    cplxTupType c2 = { cplx1, cplx2 };
    const std::size_t tupleSize_c2 = std::tuple_size <cplxTupType>();

    std::complex<int> sumCplxVal_c2 = Calculator<std::complex<int>, cplxTupType, tupleSize_c2>::sum(c2);
    std::complex<int> avgCplxVal_c2 = Calculator<std::complex<int>, cplxTupType, tupleSize_c2>::avg(c2);
    std::cout << "Complex sum is: " << sumCplxVal_c2 << std::endl;
    std::cout << "Complex avg is: " << avgCplxVal_c2 << std::endl;
    
    /* dblTupType i_tuple = { b2, b2 };
    using intCalType = Calculator<int, dblTupType, 2>;
    std::cout << Calculator<int, dblTupType,2>::max(i_tuple);*/
}