// Level1_Section1.6_Exercise3.cpp : 
//Exercise 4: Alias Template and its Advantages compared to typedef

#include <iostream>
//----------------------------
// Example Code using typedef
//----------------------------
template <typename T>
class Client
{
    // An example of Composition
private:
    typename Storage<T>::type data; // typename mandatory
public:
    Client(int n, const T& val) : data(n, val) {}
    void print() const {
        std::for_each(data.begin(), data.end(),
            [](const T& n) { std::cout << n << ","; });
        std::cout << '\n';
    }
};

// C++ 98 approach
// Data storage types
template <typename T> struct Storage
{
    // Possible ADTs and their memory allocators
    // typedef std::vector<T, CustomAllocator<T>> type;
    // typedef std::vector<T, std::allocator<T>> type;

    typedef std::list<T, std::allocator<T>> type;

};

int main()
{
    //----------------------
    // typedef Code Usage
    //----------------------
    // Client of storage using typedef (C++ 98)
    int n = 10; int val = 2;
    Client<int> myClient(n, val); myClient.print();

}
