#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <cmath>
#include <iomanip>

//Used for finding substring of user principal
//for debt payment calculator
#include <string>

using namespace std;

class Loan {
 public:
  void paymentDriver();
  
 private:
  int paymentMonths(double, double, double);
  bool isValidLoan(string);
};
#endif
