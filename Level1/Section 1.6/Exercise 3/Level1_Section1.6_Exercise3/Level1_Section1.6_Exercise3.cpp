// Level1_Section1.6_Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Resources: 
https://docs.microsoft.com/en-us/cpp/cpp/initializers?view=msvc-160 
https://en.cppreference.com/w/cpp/language/initialization

The different ways to initialise objects and data are:
    1. Default initialisation: object is constructed without an initializer.
    2. Value initialisation: object is constructed with an empty initializer.
    3. Direct initialisation: object is initialised from an explicit set of constructor arguments.
    4. Copy initialisation: object is initialised from another object.
    5. List initialisation: object is initialised from braced-init-list.
    6. Aggregate initialisation: initialise an aggregate from a braced-init-list.
    7. Reference initialisation: bind a reference to an object.

*/

#include <iostream>
#include <vector>
#include <functional>

// 1. Default Initialization 
class DefaultInit
{
public: 

};

// 2. Value Initialization 
class ValueInit
{
public:
    int m_init;
};

// 3. Direct Initialization 
class DirectInitBase {
public:
    DirectInitBase(int n) :m_int(n) {} // m_int is direct initialized
private:
    int m_int;
};

class DirectInitDerived : public DirectInitBase {
public:
    // DirectInitBase and m_char are direct initialized
    DirectInitDerived(int n, char c) : DirectInitBase(n), m_char(c) {}
private:
    char m_char;
};

// 4. Copy Initialization 
class CopyInit {
private:
    int m_int = 7;
public:
    CopyInit(int myInt) {}
    void set_int(int myInt) { m_int = myInt; }
    int get_int() const {
        return m_int;
    };
}; 

// 5. List Initialization 
class ListInit {
private:
    int m_int[3]{ 3 };
    char m_char;
public: 
    ListInit(int myInt, char myChar) {};
};

class ListSetGet {
public:
    void set_class(ListInit LSG) {}
    ListInit get_class() { return ListInit{ 0,'\0' }; }
};

struct ListStruct {
    int m_int; 
    char my_char; 
    ListInit my_list_init;
};

// 6. Aggretage Initialization 
struct AggregateInitA {
    int myInt;
    char myChar;
};
struct AggregateInitB {
    int myInt; 
    char myChar = 'Z';
};

// 7. Reference Initialization 
int iVar;
long lVar;

// Applying Aggregate initialization to the class 
struct S
{
    int x;
    struct Foo
    {
        int i; int j; int a[3];
    }b;
};

    int main()
    {
        //  1. Default initialisation: object is constructed without an initializer.
        //  Default initialization for variables 
        int defVar1;
        float defVar2;
        // Default Class 
        DefaultInit DC1;
        DefaultInit* DC2 = new DefaultInit;
        // Default array/vector 
        int def_arr[4];
        std::vector<int> def_vec[4];

        // 2. Value initialisation : object is constructed with an empty initializer.
        // Value Init for variables 
        int valVar1{}; // valVar1 has value 0
        double valVar2{}; // valVar2 has value 0.0000
        // Value Init for classes 
        ValueInit VI1{}; // class initialized 
        ValueInit* VI2 = new ValueInit(); //class initialized m_int value is zero 
        // Value Init for array/variables 
        int val_arr[4]{}; // all members in array initialized to zero 
        std::vector<int> val_vec[4]{}; // all members in vector initialized to zero 

       //3. Direct initialisation : object is initialised from an explicit set of constructor arguments.
       // Direct Init lambda functions 
        int lambda_var = 1;
        std::function<int()> func = [lambda_var]() { return lambda_var + 1; }; //lambda_var is directly initialized  
        int n = func();
        // Direct Init class
        DirectInitBase DIB1(5);
        DirectInitDerived DID{ 1, 'c' };
        DirectInitBase* DIB2 = new DirectInitBase(7);
        DirectInitBase DIB3 = static_cast<DirectInitBase>(DID);

        // 4. Copy initialisation : object is initialised from another object.
        int i = 10; // copy initialization of i 
        CopyInit CI1{ i };
        CopyInit CI2 = CI1; // copy initialization of CI2 from CI1
        CI1.set_int(i); // copy initialization of parameter from i
        int i2 = CI2.get_int(); // copy initialization of i2 from return value of get_int()

        // 5. List initialisation : object is initialised from braced - init - list.
        // List initialization variable 
        std::string s1{ 'a', 'b', 'c', 'd' }; 
        // List initialization class 
        ListInit LI1{ 1, 'a' };
        ListInit* LI2 = new ListInit{ 2,'b' };
        ListInit LI3 = { 3, 'c' };

        ListSetGet LSG;
        LSG.set_class(ListInit{ 3,'c' });
        LSG.set_class({ 4,'d' });

        ListStruct LS1{ 1,'a',{2,'b'} };

        // 6. Aggregate initialisation : initialise an aggregate from a braced - init - list.
        AggregateInitA agg1{ 1,'c' };
        AggregateInitB agg2{ 2 };
        int MyArr1[]{ 1,2,3,4,5 };
        int MyArr2[3]= { 2,4,6 };
        int MyArr3[5] = { 3,6,9 }; // first three values will be 3,6,9 and last two will be 0,0

        // 7. Reference initialisation : bind a reference to an object.
        long& LongRef1 = lVar; // no conversion needed 
        //long& LongRef2 = iVar;  // this would produce an error (ill formed case) 
        int& LongRef2 = iVar;
        const long& LongRef3 = iVar; 
        LongRef1 = 23L;     // changing lVar through a reference 
        LongRef2 = 11L;     // changing iVar through a reference 
        //LongRef3 = 11L    // this would produce an error (ill formed case) 

        // Aggregate initialization to Struct S
        S::Foo f1 = { 1,2, {6,4,2} };
        S aggS1{ 1, {f1} };

        // How many different ways can you think of to initialise the S class?
        // I believe each method of initialization except maybe reference initialization 
    }
