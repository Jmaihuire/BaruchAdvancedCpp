// Level6_Section6.4_Exercise1.cpp 
// Fiona Ross 
// Access Proxy

#include <iostream>
#include "ProtectedAccount.h"

int main()
{
  // Testing
      // make account:
      ProtectedAccount accnt1(24.00, "5532");

  // valid password 
  std::cout << "Getting balance: " << accnt1.GetBalance("5532") << std::endl;

  // Incorrect password 
  try {
    accnt1.GetBalance("4342");
  } catch (NoAccessException& e) {
    std::cout << e.what();
  }


  // Withdraw reasonable balance:
  accnt1.Withdraw(12);

  // No Funds Catch 
  // Withdraw too much:
  try {
    accnt1.Withdraw(100);
  } catch (NoFundsException& e) {
    std::cout << e.what();
  }
}
