#include <iostream>

#include "RealAccount.h"
// constructor with initial balance of zero
RealAccount::RealAccount() {
  balance = 0.0;  // start with no money
}

// constructor with user defined balance
RealAccount::RealAccount(double startingBalance) {
  balance = startingBalance;  // start with no money
}

// withdraw function
void RealAccount::Withdraw(double amount) {
  if (amount > balance) {
    throw NoFundsException();  // not enough funds
  }
  std::cout << "Withdrawing $" << amount << " from $" << balance << std::endl;
  balance -= amount;
  std::cout << "Ending balance is $" << this->GetBalance() << std::endl;
};

// get balance function
double RealAccount::GetBalance() { return balance; };
