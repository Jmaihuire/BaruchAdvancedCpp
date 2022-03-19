// Level2_Section2.8_Exercise2.cpp: 
/*
Fiona Ross - 03-12-2020
Boolean Operations on Bitsets 
*/

#include <iostream>
#include <bitset>
#include <functional>
#include <cstddef>
#include <boost/dynamic_bitset/dynamic_bitset.hpp>

int main()
{
	// Part A: Setting bitsets bs1 & bs2
	std::bitset<4> bs1;
	bs1.set(0) = 0; bs1.set(1) = 1; bs1.set(2) = 1; bs1.set(3) = 1;
	std::bitset<4> bs2;
	bs2.set(0) = 0; bs2.set(1) = 1; bs2.set(2) = 1; bs2.set(3) = 1;

	// Part B: Toggling the bits of bs1 & bs2
	bs1.flip();
	bs2.flip(); 

	// Part C: perform bitwise XOR, OR  and AND
	std::cout << "Bitset XOR of bs1 and bs2 " << (bs1 ^= bs2) << std::endl;
	std::cout << "Bitset OR of bs1 and bs2 " << (bs1 != bs2) << std::endl;
	std::cout << "Bitset AND of bs1 and bs2 " << (bs1 &= bs2) << std::endl;

	// Part D: shifting bits 
	int m = 2;  // number of bits to shift by 
	std::bitset<4> bs1L = bs1 << m; // shift m bits to the left 
	std::bitset<4> bs2R = bs2 >> m; // shift m bits to the right

	//Part E: hash values 
	std::size_t bitset_hash1 = std::hash<std::bitset<4>>{}(bs1);
	std::size_t bitset_hash2 = std::hash<std::bitset<4>>{}(bs2);

	// Part F: Binary Literals C++ 
	// This code was pulled from course note s
	auto blit = 0b0011;

	std::byte b{ 0b0011 }; // Create from a binary literal

	std::bitset<4> bs(blit);

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





}


