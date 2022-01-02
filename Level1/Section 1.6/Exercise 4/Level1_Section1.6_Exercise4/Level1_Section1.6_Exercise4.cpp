// Level1_Section1.6_Exercise4.cpp : m execution begins and ends there.
// Exercise 4: Alias Template and its Advantages compared to typedef

/*
The typedef is essentially deprecated. It does not work with templates 
(at least not directly) and we need to do a lot of contortions when working
with templatised classes and structs. To this end, we create a class that 
is composed of a container:
*/

#include <iostream>
#include <list>
#include <algorithm>

// Storage class needs to preceed client class as Client uses storage 
// C++ 98 approach
// Data storage types
template <typename T> struct 
Storage
{
    // Possible ADTs and their memory allocators
    // typedef std::vector<T, CustomAllocator<T>> type;
    // typedef std::vector<T, std::allocator<T>> type;
    typedef std::list<T, std::allocator<T>> type;

};

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

// Using Aliases instead of typedef 

template <typename T>
using AllocAli = std::allocator<T>;
template <typename T>
using TypeAli = std::list<T, AllocAli<T>>;

template <typename T> struct StorageAli
{
    using typeA = TypeAli<T>;
};

template <typename T> 
class ClientAlias
{
private:
    struct StorageAli<T>::typeA data;
public:
    ClientAlias(int n, const T& val) : data(n, val) {}
    void print() const {
        std::for_each(data.begin(), data.end(),
            [](const T& n) { std::cout << n << ","; });
        std::cout << '\n';
    }
};

int main()
{
    // Client of storage using typedef (C++ 98)
    int n = 10; int val = 2;
    Client<int> myClient(n, val); myClient.print();

    // Clienat of storage using aliases 
    int nA = 12; int valA = 4;
    ClientAlias<int> ClientAlias(nA, valA); ClientAlias.print();
}
