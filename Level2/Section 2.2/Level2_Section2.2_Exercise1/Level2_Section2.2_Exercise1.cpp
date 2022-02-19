// Level2_Section2.2_Exercise1.cpp : 
/*
Fiona Ross - 02-05-2022
A Numeric Application: The Beginnings of a Vector Space (advanced type traits)

Add two vectors.
The additive inverse of a vector.
Scalar multiplicity (premultiply the vector by a scalar).

*/

#include <array>
#include <vector>
#include <iostream>
#include <complex>

//------------------------------
// General Functions 
//------------------------------

template <typename T>
int TypeInformationV(const T& val)
{
    //Type traits relating specifically to an array

    //If not an array then quit
    if (std::is_array<T>::value)
    {
        std::cout << "\nAn array type: ";
        return 1;
    }
    else if (std::is_scalar<T>::value)
    {
        std::cout << "\nA scalar type: ";
        return 3;
    }
    else
    {
        std::cout << "\nA vector type: ";
        return 2;
    }
}

//------------------------------
// Addition Functions 
//------------------------------
template <typename T>
T Addition_impl(const T& t1, const T& t2, std::true_type)
{
    // Addition of arrays 
    T result(t1); // this is t1.size
    std::cout << "\nThe result of array addition is: ";

    for (auto i = 0; i < t1.size(); ++i)
    {
        // Push_back did not work for those initialized as arrays
        //result.push_back(t1[i] + t2[i]);
        result[i] = (t1[i] + t2[i]);
        std::cout << result[i] << ", ";
    }

    return result;
}

template <typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type)
{
    // Addition of two scalars
    T result = t1 + t2;
    std::cout << "\nThe result of scalar addition is: " << result << std::endl;
    return result; 
}

template <typename T>
T Addition(const T& t1, const T& t2)
{ 
    return Addition_impl(t1, t2, std::is_compound<T>());
}


//------------------------------
// Additive Inverse Functions 
//------------------------------
template <typename T>
void AdditiveInverse_impl(T& val, std::true_type)
{
    // additive inverse of a vector 
    for (auto it = std::begin(val); it != std::end(val); ++it)
    {
        (*it) = -(*it);
    }
}

template <typename T>
void AdditiveInverse_impl(T& t, std::false_type)
{
    // additive inverse of a scalar quantity
    t = -t;
}

template <typename T>
void AdditiveInverse(T& val)
{
    // val -> -val for a scalar or a vector
    AdditiveInverse_impl(val, std::is_compound<T>());
}


//---------------------------------------------
// Multiplication of Scalar & Array Functions 
//---------------------------------------------

// Putting two different multiplications for different input order of Vector & Scalar
template <typename Vect, typename Scalar>
Vect Multiplication_impl(const Vect& V1, const Scalar& S2, std::true_type, std::false_type)
{
    // Addition of arrays 
    Vect result(V1); // this is V1.size
    std::cout << "\nThe result of array multiplication is: ";

    for (auto i = 0; i < V1.size(); ++i)
    {
        // Push_back did not work for those initialized as arrays only vectors & lists
        //auto input = V1[i] * S2;
        //result.push_back(input);
        result[i] = V1[i] * S2;
        std::cout << result[i] << ",";
    }

    return result;
}

// Putting two different multiplications for different input order of Vector & Scalar
template <typename Scalar, typename Vect>
Vect Multiplication_impl(const Scalar& S1, const Vect& V2, std::false_type, std::true_type)
{
    // Addition of arrays 
    Vect result(V2); // this is V1.size
    std::cout << "\nThe result of array multiplication is: ";
    
    for (auto i = 0; i < V2.size(); ++i)
    {
        // Push_back did not work for those initialized as arrays only vectors & lists
        result[i] = V2[i] * S1;
        std::cout << result[i] << ",";
    }
    
    return result;
}

// Putting two different multiplications for different input order of Vector & Scalar
template <typename Scalar, typename Scalar2>
void Multiplication_impl(const Scalar& S1, const Scalar2& S2, std::false_type, std::false_type)
{
    std::cout << "\nWrong Input! Please input a vector and a scalar";

    return;
}

// Putting two different multiplications for different input order of Vector & Scalar
template <typename Vect, typename Vect2>
void Multiplication_impl(const Vect& S1, const Vect2& V2, std::true_type, std::true_type)
{
    std::cout << "\nWrong Input! Please input a vector and a scalar";

    return;
}

template <typename Vect, typename Scalar>
auto Multiplication(const Vect& V1, const Scalar& S2)
{
    return Multiplication_impl(V1, S2, std::is_compound<Vect>(), std::is_compound<Scalar>());
}


#include <iostream>

int main()
{
    // General declaration
    std::array<double,4> arr = { 1,2,3,4 };
    std::array<double, 4> arr1 = { 11,22,33,44 };
    std::vector<double> arr2 = { 10,20,30,40 };
    std::vector<double> arr3 = { 12,24,36,48 };

    double d = 1.0;
    double d1 = 3.0;

    // Addition 
    std::cout << "\n *** Addition ***";
    auto out_add_scal = Addition(d,d1); //addition of two scalars
    auto out_add_arr = Addition(arr, arr1); //addition of two arrays
    std::vector<double> out_add_vec = Addition(arr2, arr3); //addition of two vectors

    // Multiplication 
    std::cout << "\n *** Multiplication ***";
    Multiplication(arr, arr2); //array & vector
    Multiplication(d, d1);     //2 doubles

    //// this should work
    Multiplication(arr, d); // array & double 
    Multiplication(d, arr); // double & array
    Multiplication(arr2, d); // vector & double

    // Additive Inverse 
    std::cout << "\n *** Additive Inverse ***";
    TypeInformationV(arr);
    TypeInformationV(arr2);

    AdditiveInverse(d);
    AdditiveInverse(arr);  

    // Part D: Testing functions with std::complex<double>
    std::complex<double> comp1(1, 2);
    std::complex<double> comp2(3, 1);
    std::vector<std::complex<double>> comp_vec = { comp1,comp2 };
    
    // auto outAdd = Addition(comp_vec, comp_vec);
    AdditiveInverse(comp_vec);
    auto outMult = Multiplication(d, comp_vec);
}
