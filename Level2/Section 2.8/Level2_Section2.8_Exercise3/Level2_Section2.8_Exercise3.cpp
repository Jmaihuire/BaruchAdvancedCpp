// Level2_Section2.8_Exercise3.cpp : 
/*
Fiona Ross 03-19-2022
Boost Dynamic Bitset 101
*/

#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include <string>
#include <bitset>

// ---------------------------------
//	Code From Question 1
// ---------------------------------
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
    boost::dynamic_bitset<> ulong(4);
    ulong[0] = 1; ulong[1] = 0; ulong[2] = 0; ulong[3] = 1;
    std::cout << "unsigned long bitset: " << std::endl;
    print(ulong);

    boost::dynamic_bitset<> ullong(4);
    ullong[0] = 1; ullong[1] = 0; ullong[2] = 0; ullong[3] = 1;
    std::cout << "unsigned long long bitset: " << std::endl;
    print(ulong);

    // Part B: 
    // Create bitset from full & partial strings 
    // bitsets are read left to right 
    // string is read right to left so will be opposite 

    std::string str = "010101111";
    int start_idx = 0;
    int N = 8;
    boost::dynamic_bitset<> fullstr{ str };
    std::cout << "fullstring is: " << std::endl;
    std::cout << fullstr << std::endl;

    // what ever is not coppied over from the string will be zeros 
    boost::dynamic_bitset<> partstr{ str, 4, 2 };
    std::cout << "partstring is: " << std::endl;
    std::cout << partstr << std::endl;

    // Part C: 
    // In the case of strings(for example), 
    // use exception handling to check for out - of - range values and invalid arguments(bits that are neither 0 nor 1).

    // Trying to initiate something out of range 
    //try {

    //    std::string out_of_range_str = "0100101";
    //    std::bitset<9> out_of_range_bstr{ out_of_range_str , 9 }; // this index is out of range 
    //}
    //catch (const std::out_of_range& err) // catching out of range index 
    //{
    //    std::cout << "Error! Bitset is out of range" << std::endl;
    //}

    //try {

    //    std::string out_of_range_str2 = "01e0701";
    //    std::bitset<7> out_of_range_bstr2{ out_of_range_str2 }; // non 0 or 1 value 
    //}
    //catch (const std::invalid_argument& err) //catching invalid bitset
    //{
    //    std::cout << "Error! Bitset is out of range" << std::endl;
    //}

    // Part D: 
    std::string str_func = "10011100";
    boost::dynamic_bitset<> bit_func(str_func);
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
    std::string str_orig = "10011010";
    boost::dynamic_bitset<> bit_orig(str_orig);
    boost::dynamic_bitset<> bit_long(bit_orig);
    boost::dynamic_bitset<> bit_llong(bit_orig);
    boost::dynamic_bitset<> bit_str(bit_orig);

    std::cout << bit_orig << " as a long is: " << bit_long.to_ulong() << '\n';
   
    // ullong nor conversion to string are supported in boost library 
    // std::cout << bit_orig << " as a long long is: " << bit_llong.to_ullong() << '\n';
    // std::cout << bit_orig << " as a string is: " << bit_str.to_string() << '\n';

    // Part F: 
    // Testing if two bitsets are equal or not
    std::string sset1 = "10011111";
    std::string sset2 = "00100100";
    boost::dynamic_bitset<> bset1(sset1);
    boost::dynamic_bitset<> bset2(sset2);


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


    // -----------------------------------------
    //      Code from Question 2
    // -----------------------------------------

    // Part A: Setting bitsets bs1 & bs2
    std::string bitString = "01110010";
    boost::dynamic_bitset<unsigned char> bs1(bitString);
    std::string bitString2 = "10101011";
    boost::dynamic_bitset<unsigned char> bs2(bitString2);

    // Part B: Toggling the bits of bs1 & bs2
    bs1.flip();
    bs2.flip();

    // Part C: perform bitwise XOR, OR  and AND
    std::cout << "Bitset XOR of bs1 and bs2 " << (bs1 ^= bs2) << std::endl;
    std::cout << "Bitset OR of bs1 and bs2 " << (bs1 != bs2) << std::endl;
    std::cout << "Bitset AND of bs1 and bs2 " << (bs1 &= bs2) << std::endl;

    // Part D: shifting bits 
    int m = 2;  // number of bits to shift by 
    bs1 << m; // shift m bits to the left 
    bs2 >> m; // shift m bits to the right

    //Part E: hash values 
    // Hash does not seem to be included in the boost bitset libarary 
    // std::size_t bitset_hash1 = std::hash<std::bitset<4>>{}(bs1);
    // std::size_t bitset_hash2 = std::hash<std::bitset<4>>{}(bs2);

    // Part F: Binary Literals C++ 
    // This code was pulled from course note s
    auto blit = 0b0011;

    std::byte b{ 0b0011 }; // Create from a binary literal

    boost::dynamic_bitset <> bs(blit);

    boost::dynamic_bitset<unsigned int> dbs(4); // all 0 by default

    dbs[1] = dbs[0] = 1;

    std::cout << "\nbyte: " << std::to_integer<int>(b) << '\n';

    std::cout << "bitset: " << bs << '\n';

    std::cout << "dynamic bitset: " << dbs << '\n';

    // Part G:
    std::byte b2{ 0b1001 }; //Binary literal
    std::byte b3{ 4 }; // Integer 
    std::byte b4 = b2 ^ b; //Binary logical operator on existing bytes

    // Part H: 
    b3 &= b4; // AND operation (bitwise)
    b3 |= b2; // OR operation (bitwise) 

    // Part I: 
    // this will shift the bits in b2 by 8 bits, meaning any bits set will be shifted out of range of the byte 
    std::cout << "B2 left bit shift " << std::to_integer<int>(b2 << 8) << std::endl;

    // this will shift the bits in b2 by 8 bits, which should be all zeros 
    std::cout << "B2 right bit shift " << std::to_integer<int>(b2 >> 8) << std::endl;

    // Part J: 
    //  Since bytes and bitsets are fixed size, we can use them to represent the fixed size of memory.
    //  This would provide a lightweight way to implement a bitmap.
    // 
    //  Bytes and bitsets may be used to show raw memory bitmap. 

    //  From the lecture, its clear they can be used for setting flags, sparse matrices, huffman coding, bloom filters, information retrieval and compact data structures

    // ---------------------------------------
    //      Excerciese 3 Code 
    // ---------------------------------------

    // Part B: 
    std::string strruntime = "10110001"; 
    boost::dynamic_bitset <> bruntime(strruntime);
    
    bruntime.resize(6);  // It is used to increase or decrease the size of the object by 6 bits 
    std::cout << "bitset after resize is: " << bruntime << std::endl;
    bruntime.push_back(1); //It increases the size of dynamic_bitset object by one and pushes the value at MSB
    std::cout << "bitset after push_back is: " << bruntime << std::endl;
    bruntime.pop_back(); // It removes one bit from MSB
    std::cout << "bitset after pop_back is: " << bruntime << std::endl;
    //It appends the bits at the most - significant bit.This increases the size of the bitset by bits_per_block.For i in the range[0, bits_per_block), the bit at position(size + i) is set to((value >> i) & 1) 
    bruntime.append(1);
    std::cout << "bitset after append is: " << bruntime << std::endl;
    // clearing bitset 
    bruntime.clear();
    std::cout << "bitset after clear is: " << bruntime << std::endl;

    // Part C: 
    boost::dynamic_bitset<> bbase{ 0b0011 }; // Create from a binary literal
    boost::dynamic_bitset <> b5(3);
    boost::dynamic_bitset <> b6 = bbase^b5;
    std::cout << "B4 is bitset of B3? " << b5.is_subset_of(b6) << std::endl; //test if b4 is subset of b3

    // Part D: 
    bbase.set(2);
    bbase.push_back(1);
    std::cout << "First bit: " << bruntime.find_first() << std::endl; //find first set bit from position 0/least significant bit
    std::cout << "Next bit: " << bruntime.find_next(2) << std::endl; //find next set bit from position 2

}
