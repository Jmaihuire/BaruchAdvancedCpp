// Level5_Section5.7_Exercise3.cpp 
// Fiona Ross 
// UML Association Class 

#include <iostream>
#include <tuple>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>

using namespace boost::bimaps;


void Test() {

   // Part A: 1N association between book title & author 
  // multiple authors but one title
  typedef bimap<multiset_of<std::string>, set_of<std::string>,
                with_info<double>>  // with_info could be own data type
      BMType;

  typedef BMType::value_type Book;

  BMType bm;

  bm.insert(Book("Daniel J. Duffy", "The Meaning of Life", 42.00));

  // Part B: Printing book / author 
  // print author
  std::cout << bm.right.at("The Meaning of Life") << std::endl; 

  // print the price of book 
  BMType::left_iterator i = bm.left.find("Daniel J. Duffy");
  std::cout << i->info << std::endl;

  i->info += 12.3;
  std::cout << i->info << std::endl;

  //print the new price 
  std::cout << bm.right.info_at("The Meaning of Life") << std::endl;

  // Part C: 
  // Association attribute containing tuple 
  // Tuple consists of book abstract and price 
  typedef bimap < multiset_of<std::string>,      // author
      set_of<std::string>,                       // title
      with_info < std::tuple<std::string, double>>>BMType2;  // abstract + price
                
          

  typedef BMType2::value_type Book2; 

  BMType2 bm2; 

  bm2.insert(Book2("Daniel J. Duffy", "The Meaning of Life",
                   std::make_tuple("A-Z", 42.00)));

  std::cout << std::get<0>(bm2.right.info_at("The Meaning of Life"))
            << std::endl;
  std::cout << std::get<1>(bm2.right.info_at("The Meaning of Life"))
            << std::endl; 
}

int main() { Test();}

