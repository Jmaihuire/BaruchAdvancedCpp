/*
Fiona Ross
Vector Space Math Functions

Objective: create vector space math funtions using lambda
functions and higher order functions

*/

#include <functional>
#include <iostream>
#include <math.h>

//-----------------------------------------------
// ------------ Part A  ------------------------
//-----------------------------------------------

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

// Addition of 2 functions 
template <typename R, typename D>
FunctionType<R, D> operator + (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	return [=](const D& x)
	{
		return f(x) + g(x);
	};
}

// Subtraction of 2 functions 
template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	return [=](const D& x)
	{
		return f(x) - g(x);
	};
}

// Multiplication of 2 functions 
template <typename R, typename D>
FunctionType<R, D> operator * (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	return [=](const D& x)
	{
		return f(x) * g(x);
	};
}

// Multiplication of a scalar & function 
template <typename R, typename D>
FunctionType<R,D> operator * (const double s,
	const FunctionType<R, D>& g)
{
	return [=](const D& x)
	{
		return s * g(x);
	};
}

// Division of two functions 
template <typename R, typename D>
FunctionType<R, D> operator / (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	return [=](const D& x)
	{
		return f(x) / g(x);
	};
}

// Unary additive inverse of a function 
template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f)
{
	return [=](const D& x)
	{
		return -(f(x));
	};
}

// Composition of 2 functions
template <typename R, typename D>
FunctionType<R, D> operator << (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	return [=](const D& x)
	{
		return f(g(x));
	};
}

//-----------------------------------------------
// ------------ Part B --------------------------
//-----------------------------------------------

// Exponential of a function 
template <typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::exp(f(x));
	};
}

// Log of a function
template <typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::log(f(x));
	};
}

// Cosine of a Function 
template <typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::cos(f(x));
	};
}

// Absolute Value of a Function
template <typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::abs(f(x));
	};
}

// Square Root of a Function
template <typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::sqrt(f(x));
	};
}

//-----------------------------------------------
// ------------ Part C --------------------------
//-----------------------------------------------

// min
template <typename R, typename D>
FunctionType<R, D> min(const FunctionType<R, D>& f, const FunctionType<R,D>&g)
{
	// The exponential function
	return [=](const D& x)
	{
		if (f(x) < g(x)) { return f(x); }
		else { return g(x); };
	};
}


// maximum 
template <typename R, typename D>
FunctionType<R, D> max(const FunctionType<R, D>& f, const FunctionType<R,D>&g)
{

	return [=](const D& x)
	{
		if (f(x) > g(x)) { return f(x); }
		else { return g(x); };
	};
}