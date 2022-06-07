// Level5_Section5.3_Exercise5.cpp 
// Fiona Ross 
// Bucket Interface 

#include <iostream>
#include <unordered_set>
#include <boost/algorithm/string.hpp>


template <typename Key, typename Hash, typename EqPred>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c) {
  // Part A: Max number buckets 

  std::cout << "Number of Buckets: " << c.bucket_count() << std::endl;
  std::cout << "Max Number of Buckets: " << c.max_bucket_count() << std::endl;

  // Part B: Load Factor 
  std::cout << "Load factor: " << c.load_factor() << std::endl;
  std::cout << "Max Load Factor: " << c.max_load_factor() << std::endl;

  // Part C:  Size of each bucket
  for (auto bucket : c) {
    std::cout << "Bucket size: " << c.bucket_count() << std::endl;
  }

}

int main() {
  // showing part A - C
  std::unordered_set<int> set1;
  for (int i = 0; i < 12; i++) {
    set1.emplace(i);
  }

  // getting output printed to console 
  BucketInformation(set1);

  // Part D: 
  // This didn't work the buckets staid constant at 64. Trying another size that is larger than 64 
    //  set1.rehash(10); // rehashing so one bucket is at size 10
  set1.rehash(120);  // this worked and got the buckets to rehash to 128
  BucketInformation(set1); 
}

