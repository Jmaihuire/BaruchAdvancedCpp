#pragma once
#include <string>
#include "Exception.h"
class NoFundsException : public Exception {
 public:
  // create exception instance when not enough funds to take out 
  std::string what() {
    return "Not enough funds -- Check balance and only take out available "
           "money\n";
  }
};
