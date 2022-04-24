// Level3_Section3.2_Exercise1.cpp 
// 
#include <iostream>
#include <atomic>

struct X {
  double val;

  X() : val(0.0) {}
  void operator()() { std::cout << "An X " << val << std::endl; }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

int main()
{
    //Part A:
    PointerType x(new X); 
    x->val = 3.0;
    
    // Part B: 
    PointerType x2 = nullptr;
    std::atomic_store(&x, x2);

    // Part C: 
    PointerType x3(new X);
    x3->val = 42.0; 
    std::cout << "x val: " << x->val << std::endl;
    std::cout << "x2 val: " << x2->val << std::endl;
    auto former = std::atomic_exchange(&x3, x); 
    auto former2 = std::atomic_exchange(&x3, x2);

    std::cout << "Former 1 (exchange of x & x3) is: " << former->val
              << std::endl;

        std::cout << "Former 2 (exchange of x2 & x3) is: " << former2->val
              << std::endl;

    // Part D: 
    std::cout << "x has shared pointer instances of: " << x.use_count()
                  << std::endl;
   
    std::cout << "x2 has shared pointer instances of: " << x2.use_count()
                   << std::endl;
   
   
    std::cout << "x has shared pointer instances of: " << x3.use_count() << std::endl;
   
    // Part E: 
    // Atomic shared pointers are not possible bc. they are not thread safe. 
    // Atomic object must be trivially copyable. 
    // Data races occur if multiple threads access a non-const member function 


    // Part F:
    // Shared pointers are not lock free. They can be under certain conditions 
    // but this is only when operations on the data are lock free 
    // ie. move operations & destructors are lock free but only if 
    // std::atomic<std::size_t> are lock free 

    std::cout << "Shared pointers are lock free? " << std::boolalpha
              << std::atomic_is_lock_free(&x3) << std::endl;


}

