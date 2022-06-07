// Level5_Section5.3_Exercise6.cpp 
// Fiona Ross 
// The full Monte 

#include <iostream>
#include <unordered_set>
#include <boost/algorithm/string.hpp>
#include <boost/unordered_set.hpp>


// Hash Value Functions pulled from lecture
template <typename T>
void hash_value(std::size_t& seed, const T& val) {
  // adapted from lecture notes
  boost::hash_combine(seed, val);
}

template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args) {
  // adapted from lecture notes:
  boost::hash_combine(seed, val);
  hash_value(seed, args...);
}

template <typename... Types>
std::size_t hash_value(const Types&... args) {
  std::size_t seed = 0;
  hash_value(seed, args...);
  return seed;
}

// Implimenting the Struct S (pulled from lecture) 
// Part A: 
struct S {
  std::string f;
  std::string s;
  S(const std::string& s1, const std::string& s2) : f(s1), s(s2) {}
};

class SHash  // Hash for class S
{
 public:
  std::size_t operator()(const S& s) const { return hash_value(s.f, s.s); }
};

class SEqual  // Equality for S
{
 public:
  bool operator()(const S& lhs, const S& rhs) const {
    return (rhs.f == lhs.f && rhs.s == lhs.s);
  }
};

// Bucket Information pulled from 5.3.5
//Part B:
template <typename Key, typename Hash, typename EqPred>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c)
{
  // Part A - number of buckets and maximum number of possible buckets
  std::cout << "Number of Buckets: " << c.bucket_count() << std::endl;
  std::cout << "Max Number of Buckets: " << c.max_bucket_count() << std::endl;

  // Part B - Show current load factor and max load factor
  std::cout << "Load factor: " << c.load_factor() << std::endl;
  std::cout << "Max Load Factor: " << c.max_load_factor() << std::endl;

  // Part C - Size of each bucket
  for (auto bucket : c) {
    std::cout << "Bucket size: " << c.bucket_count() << std::endl;
  }
}


int main()
{
    // Part A: Adding Elements 
        // Part A
    // initializing unordered set
  std::unordered_set<S, SHash, SEqual> set1;

  // creating the S structure 
  S s1("Pickled", "Cucumbers");
  S s2("Slow", "Wifi");
  S s3("Farm", "Work");

  // adding elemnets 
  set1.insert(s1);
  set1.insert(s2);
  set1.insert(s3);

  // Part B: Bucket Information
  BucketInformation(set1);
}
