#pragma once
#include "Account.h"
#include "NoFundsException.h"
class RealAccount : public Account {
 private:
  double balance;

 public:
  // constructor with initial balance of zero
  RealAccount();

  // constructor with user defined balance
  RealAccount(double startingBalance);

  // withdraw function
  void Withdraw(double amount) throw(NoFundsException);

  // get balance function
  double GetBalance();
};
