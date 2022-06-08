#pragma once
#include <memory>

#include "Account.h"
#include "NoAccessException.h"
#include "NoFundsException.h"
#include "RealAccount.h"
class ProtectedAccount : public Account {
 private:
  std::shared_ptr<RealAccount> linkedAccount_;  // real account to link to
  std::string pwd_;                             // password
 public:
  // constructor with initial balance of zero
  ProtectedAccount(double balance, std::string pwd);

  // withdraw function
  void Withdraw(double amount) throw(NoFundsException);

  // get balance function
  double GetBalance(std::string pwd) throw(NoAccessException);

  // get balance if password is correct
  double GetBalance();
};
