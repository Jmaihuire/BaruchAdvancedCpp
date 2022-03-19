// Level2_Section2.8_Exercise1.cpp :
/*
Bitset 101 
Part A: 
Create bitset from unsigned long and unsigned long long 

Part B: 
Create bitset from full strings 

Part C: 
Exception handling to check out of range values and invalid arguments 

Part D: 
Set the bits in bitset in different ways 
*/

#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include <string>
#include <bitset>
#include <functional>
#include <cstddef>

template <typename T>
void print(const boost::dynamic_bitset<T>& bitSet)
{
    for (int i = 0; i < bitSet.size(); ++i)
    {
        std::cout << bitSet[i];

    }
    std::cout << std::endl; 
}


int main()

{
    // Part A :
    // Create bitset from unsigned long and unsigned long long
    boost::dynamic_bitset<unsigned long> ulong(4);
    ulong[0] = 1; ulong[1] = 0; ulong[2] = 0; ulong[3] = 1; 
    std::cout << "unsigned long bitset: " << std::endl;
    print(ulong);

    boost::dynamic_bitset<unsigned long long> ullong(4);
    ullong[0] = 1; ullong[1] = 0; ullong[2] = 0; ullong[3] = 1;
    std::cout << "unsigned long long bitset: " << std::endl;
    print(ulong);

    // Part B: 
    // Create bitset from full & partial strings 
    // bitsets are read left to right 
    // string is read right to left so will be opposite 

    std::string str= "010101111"; 
    int start_idx = 0; 
    int N = 8;
    std::bitset<9> fullstr{ str };
    std::cout << "fullstring is: " << std::endl;
    std::cout << fullstr << std::endl;

    // what ever is not coppied over from the string will be zeros 
    std::bitset<6> partstr{ str, 4, 2 };
    std::cout << "partstring is: " << std::endl;
    std::cout << partstr << std::endl;

    // Part C: 
    // In the case of strings(for example), 
    // use exception handling to check for out - of - range values and invalid arguments(bits that are neither 0 nor 1).

    // Trying to initiate something out of range 
    try {

        std::string out_of_range_str = "0100101"; 
        std::bitset<9> out_of_range_bstr{ out_of_range_str , 9 }; // this index is out of range 
    }
    catch (const std::out_of_range& err) // catching out of range index 
    {
        std::cout << "Error! Bitset is out of range" << std::endl; 
    }

    try {

        std::string out_of_range_str2 = "01e0701"; 
        std::bitset<7> out_of_range_bstr2{ out_of_range_str2}; // non 0 or 1 value 
    }
    catch (const std::invalid_argument& err) //catching invalid bitset
    {
        std::cout << "Error! Bitset is out of range" << std::endl;
    }

    // Part D: 
    std::bitset<5> bit_func; 
    bit_func.set(0, 1); bit_func.set(1, 1); bit_func.set(2, 0); bit_func.set(3, 0); bit_func.set(4, 1);
    std::cout << "Using bitset .set(): " << bit_func << std::endl; // output bitset with all asigned values 

    std::cout << "Using bitset .test(1): " << bit_func.test(1) << std::endl; // testing bitset .test()
    std::cout << "Using bitset .all(): " << bit_func.all() << std::endl; // testing bitset .all()
    std::cout << "Using bitset .none(): " << bit_func.none() << std::endl; // testing bitset .none()
    std::cout << "Index accessing elements [2]: " << bit_func[2] << std::endl; // accessing space [2]
    std::cout << "Count the number of set bits .count(): " << bit_func.count() << std::endl; //counting the number of set bits

    bit_func.reset();
    std::cout << "Using bitset .reset(): " << bit_func << std::endl; // output reset bitset 

    // Part E: 
    // Converting bitset to std::string, unsigned long, unsigned long long 
    std::bitset<5> bit_orig;
    bit_orig.set(0, 1); bit_orig.set(1, 1); bit_orig.set(2, 0); bit_orig.set(3, 0); bit_orig.set(4, 1);
    std::bitset<5> bit_long(bit_orig);
    std::bitset<5> bit_llong(bit_orig);
    std::bitset<5> bit_str(bit_orig);

    std::cout << bit_orig << " as a long is: " << bit_long.to_ulong() << '\n';
    std::cout << bit_orig << " as a long long is: " << bit_llong.to_ullong() << '\n';
    std::cout << bit_orig << " as a string is: " << bit_str.to_string() << '\n';

    // Part F: 
    // Testing if two bitsets are equal or not
    std::bitset<5> bset1; 
    std::bitset<5> bset2;
    bset1.set(0, 1); bset1.set(1, 1); bset1.set(2, 0); bset1.set(3, 0); bset1.set(4, 1);
    bset2.set(0, 1); bset2.set(1, 1); bset2.set(2, 0); bset2.set(3, 0); bset2.set(4, 1);

    // this should be equal 
    if (bset1 == bset2)
    {
        std::cout << "Bitsets are equal \n"; 
    }

    bset2.reset(); 
    // this should not be equal since bitset 2 was reset 
    if (bset1 != bset2)
    {
        std::cout << "Bitsets are not equal \n";
    }

}


