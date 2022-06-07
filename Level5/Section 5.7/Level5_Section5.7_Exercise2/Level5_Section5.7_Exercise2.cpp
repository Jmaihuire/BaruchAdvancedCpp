// Level5_Section5.7_Exercise2.cpp
// Fiona Ross 
// UML Association Class 

#include <iostream>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

// From Lecture Video 
using Uuid = boost::uuids::uuid;

// Tags 
struct IpAddress {}; 
struct DomainName {};

using namespace boost::bimaps;
using namespace boost::uuids;

using DNS =
    bimap<unordered_set_of<tagged<uuid, DomainName>>,
          unordered_set_of<tagged<std::string, IpAddress>>, list_of_relation>;

// Part A: Left & Right iterators
// define iterator type for left map
using LeftIt = DNS::left_map::iterator;

// define iterator type for right map
using RightIt = DNS::right_map::iterator;


// Part C:
// Print Functions (from lecture video ) 
void print(DNS dnsDB) {
  for (DNS::const_iterator i = dnsDB.begin(), i_end = dnsDB.end(); i != i_end;
       ++i) {
    std::cout << i->get<DomainName>() << " < --- > " << i->get<IpAddress>()
              << std::endl;
  }
}

  int main()
{
  DNS dnsDB;
 
  // Use push_back because the collection of relations is a 'list_of_relation'
  // Creating UUids from strings 
  string_generator strGen;

  // random IP addresses 
  uuid u1 = strGen("000010000 - 00101 - 10101 - 1001010110");
  uuid u2 = strGen(" 12eljrlsgjo;iaubdanfodsg;isadgn;sdgjis");

  // IP addresses as boost UUID instances and Domain Names as strings 
  dnsDB.push_back(DNS::value_type(u1, "www.hello.com"));
  dnsDB.push_back(DNS::value_type(u2, "www.secret.com"));

  DNS::map_by<DomainName>::const_iterator name =
      dnsDB.by<DomainName>().find(u1);

  // Part B: 
  // looking up domain name from given IP address 
  if (name != dnsDB.by<DomainName>().end()) {
    std::cout << u1 << " has dns name: " << name->get<IpAddress>() << std::endl;
  }

  DNS::map_by<IpAddress>::const_iterator ip =
      dnsDB.by<IpAddress>().find("www.hello.com");

  // looking up IP address for given domain name 
  if (ip != dnsDB.by<IpAddress>().end()) {
    std::cout << u1 << " has ip address: " << ip->get<DomainName>()
              << std::endl;
  }

  // Part C: 
  print(dnsDB);



  }

