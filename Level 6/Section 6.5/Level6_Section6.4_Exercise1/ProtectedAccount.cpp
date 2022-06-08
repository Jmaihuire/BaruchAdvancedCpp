#include "ProtectedAccount.h"
#include <iostream>
// constructor with initial balance of zero
ProtectedAccount::ProtectedAccount(double balance, std::string pwd) {
  linkedAccount_ = std::make_shared<RealAccount>(
      balance);  // define starting balance and the account password
  pwd_ = pwd;
  std::cout << "Created account\n";
}

// withdraw function
void ProtectedAccount::Withdraw(double amount) {
  linkedAccount_->Withdraw(amount);  // delegate
};

// get balance function
double ProtectedAccount::GetBalance(std::string pwd) {
  if (pwd_ != pwd) {
    throw NoAccessException();  // password incorrect
  }
  this->GetBalance();  // delegate
};

// get balance if password is correct
double ProtectedAccount::GetBalance() {
  return linkedAccount_->GetBalance();
}  // get balance with no arguments to match signature in Account signature
   // class
