#pragma once
#include <string>
#include "Exception.h"
class NoAccessException : public Exception {
 public:
  // Want to throw an exception when client doesnt have access permision
  std::string what() { return "Permission denied...\n"; }
};
