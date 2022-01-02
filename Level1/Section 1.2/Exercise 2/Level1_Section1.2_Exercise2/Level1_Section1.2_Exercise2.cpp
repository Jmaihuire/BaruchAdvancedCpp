// Level1_Section1.2_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 2: Move Semantics 101

#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <string>
#include <cstdlib>

// Part C)
//      Create a string and move it to another string. 
//      Check the contents of the source and target 
//      strings before and after the move.
//----------------------------------------
//      Class H
//        Excercise 2c:      
//----------------------------------------
template <typename T>
class H
{
private:
    int m_size;
    T* m_data;

public:
    // I. default constructor 

    H()
    {
        cout << "Class H default constructor" << endl;
        m_size = 0; m_data = nullptr;
    }


    // II. constructor with size 
    H(int size)
    {
        cout << "Class H constructor with size input" << endl;
        // allocate data for array 
        m_size = size;
        m_data = new T[m_size];

    }

    // move constructor. this is called when the input is a mutable rvalue 
    explicit H(H<T>&& source)
    {
        cout << "Class H Move constructor with rvalue" << endl;
        // move the dynamic data
        m_size = source.m_size;
        m_data = source.m_data; //m_data is taking source's data 
        source.m_data = nullptr; // therefore, source becomes null 
    }

    // III. Copy constructor 
    H(const H<T>& source)
    {
        cout << "Class H Copy constructor" << endl;
        m_size = source.m_size;
        m_data = new T[m_size];
        for (int i = 0; i < m_size; i++) m_data[i] = source.m_data[i];
    }

    //IV. Destructor 
    ~H() {
        cout << "Class H Destructor" << endl;
        if (m_data != nullptr)  delete[] m_data;
    }

    H& operator[](int index)
    {
        cout << "Class H index operator" << endl;
        //Check if there is data and check the index 
        if (m_data == nullptr) throw "Arrays has no data";
        if (index < 0 || index >= m_size) throw "Index out of bounds";

        // return the indexed element
        return m_data[index];
    }

    // Add two vectors returning the result 
    friend H<T> operator + (const H<T>& vect1, const H<T>& vect2)
    {
        cout << "index operator" << endl;
        H<T> result(vect1.m_size + vect2.m_size); // create resulting vector 

        // copy array 1 and array to the result array and return the result 
        int index = 0;
        for (int i = 0; i < vect1.m_size; i++) result.m_data[index++] = vect2.m_data[i];
        for (int i = 0; i < vect2.m_size; i++) result.m_data[index++] = vect2.m_data[i];
        return result;
    }

    //Assignment Operator 
    H<T>& operator = (const H<T>& source)
    {
        if (this == &source) return *this; //Exit if sae object
        // Delete old data, allocate new and copy data 
        if (m_data != nullptr) delete[] m_data;
        m_size = source.m_size; m_data = new T[m_size];
        for (int i = 0; i < m_size; i++) m_data[i] = source.m_data[i];
        return *this;
    }

    // move assignment operator. This is called with the input is a mutable rvalue. 
    H<T>& operator = (H<T>&& source)
    {
        // Exit if same object
        if (this == source) return *this;

        //Delete old data 
        if (m_data != nullptr) delete[] m_data;

        // Move the dynamic data 
        m_size = source.m_size;
        m_data = source.m_data; source.m_data = nullptr;

    }

};

template <typename T>
class PracticeMove
{
private:
    H<T> m_points; //this points of the practicePoint

public:
    // move constructor 
    PracticeMove(PracticeMove&& source)
    {
        m_points = std::move(source.m_points);

    }

    PracticeMove operator = (PracticeMove&& source)
    {
        m_points = std::move(source.m_points);
        return *this;
    }
};


// Creating an rValue String 

string getString()
{
    return "Hello World!";
};

// -----------------------------------------
//              Excercise 2c)
//------------------------------------------
template < typename T >
void SwapCopyStyle(T& a, T& b)
{
    cout << "SwapCopyStyle called" << endl;
    // Swap a and b in copying way; temporary object needed
    T tmp(a); // Copy constructor
    a = b; // Copy all elements from b to a
    b = tmp; // Copy all elements from tmp to b
    cout << tmp;
}


int main()
{
    // Part A) 
    // Create a string and move it to another string. 
    // Check the contents of the source and target strings 
    // before and after the move.

    auto tStrStart = std::chrono::steady_clock::now();

    // moving a string 
    string sourceStr = "this is a source string";
    string targetStr;
    cout << "source string is:" << sourceStr << endl;
    cout << "target string is: " << targetStr << endl;


    targetStr = std::move(sourceStr);
    // computeing time to move string 
    auto tStrEnd = std::chrono::steady_clock::now();

    // calculating time 
    std::chrono::duration<double> ellapsedTimeStr = tStrEnd - tStrStart;
    cout << "It took " << ellapsedTimeStr.count() << " second(s) to create and move string." << endl;

    cout << "source string is:" << sourceStr << endl;
    cout << "target string is: " << targetStr << endl;

    // Part B) 
    // Create a vector and move it to another vector. 
    // Check the contents of the source and target vectors before 
    // and after the move. Compare the time it takes 
    // to move a vector compared to a copy constructor or a 
    // copy assignment statement.
    auto tVecStart = std::chrono::steady_clock::now();

    // creating a vector 
    std::vector<int> sourceVec{ 5,10,20,30,40,50,60,70 }; //defined as rvalue
    cout << "sourceVec pre move is:" << endl;
    std::for_each(sourceVec.begin(), sourceVec.end(), [](const auto& elem) {cout << elem << " "; });

    // moving vector using std::move 
    std::vector<int> targetVec = std::move(sourceVec);
    cout << "\n sourceVec after move is: " << endl;
    std::for_each(sourceVec.begin(), sourceVec.end(), [](const auto& elem) {cout << elem << " "; }); //sourceStr gets destroyed once it is moved using std::move() function 

    // computeing time to move vector
    auto tVecEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> ellapsedTimeVec = tVecEnd - tVecStart;
    cout << "It took " << ellapsedTimeVec.count() << " second(s) to create and move vector." << endl;

    // Part C) 
    // Consider the following user - defined code to swap two objects :
    int size = 100;
    vector<int> lgInputVec1(size, 0); vector<int> lgInputVec2(size, 0);
    generate(lgInputVec1.begin(), lgInputVec1.end(), rand);
    generate(lgInputVec2.begin(), lgInputVec2.end(), rand);
    H<string>&& inputString = ("HelloWorld", 10);

    //testing time using swap function 
    void SwapCopyStyle(vector<int>&lgInputVec1, vector<int>&lgInputVec2);
    
    // How many temporary copies are created? 
    
    // For each element in the array or vector, a new temporary copy is made.
    // The more elements in an array the more copies are made. 
    // To swap elements using copy style takes almost twice as long as using move semantics.


}
