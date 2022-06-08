// Level5_Section5.9_Exercise4.cpp 
// Fiona Ross 
// Numeric Combiners 

#include <iostream>
#include <boost/signals2/signal.hpp>

// from boost reference 
void get_args(float x, float y) {
  std::cout << "The arguments are " << x << " and " << y << std::endl;
}

float get_sum(float x, float y) {
  std::cout << "The sum is " << x + y << std::endl;
  return x + y;
}

float get_product(float x, float y) {
  std::cout << "The product is " << x * y << std::endl;
  return x * y;
}

float get_difference(float x, float y) {
  std::cout << "The difference is " << x - y << std::endl;
  return x - y;
}

float get_quotient(float x, float y) {
  std::cout << "The quotient is " << x / y << std::endl;
  return x / y;
}


// Create a signal + custom combiner
// also from boost reference but changed it a bit to take sum not maximum
template <typename T>
struct SumCombiner {
  // Iterate in slots and return sum of returned values
  using result_type = T;
  template <typename InputIterator>
  result_type operator()(InputIterator first, InputIterator last) const {
    //If no slots to call, return the default value
    result_type sum = *first;
    ++first;
    while (first != last) {
      sum += *first; //basically just had to change this line 
      ++first;
    }
    return sum;
  }
};


int main()
{
  // from HW slide 
  boost::signals2::signal<double(double x, double y), SumCombiner<double>> sig;

  sig.connect(&get_sum);
  sig.connect(&get_product);
  sig.connect(&get_difference);
  sig.connect(&get_quotient);
  std::cout << "Total Output Sum: " << sig(1.0, 2.0);

  // seemed right based on all the individual outputs and math done by hand 
}
