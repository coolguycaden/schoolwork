#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>

//Caden Allen
//CPSC 1071: Section 5
//A++
// 9/14/2023

using namespace std;

int main(){
  double principal;
  double interest;
  double payment;
  double result;

  //This section is for reading in user input
  cout<<"** Welcome to the CPSC 1071 Payment Calculator **"<<endl<<endl;
  
  cout<<"Enter the principal amount: ";

  cin >> principal;
  while(principal < 0){
    cout<<"Invalid value, try again: ";
    cin >> principal;
  }
  
  cout<<"Enter the annual interest rate (in %): ";
  cin >> interest;
  while(interest < 0){
    cout<<"Invalid value, try again: ";
    cin >> interest;
  }

  cout<<"Enter the monthly payment: ";
  cin >> payment;
  while(payment < 0){
    cout<<"Invalid value, try again: ";
    cin >> payment;
  }
  cout<<"\nCalculating..."<<endl<<endl;
  
  //Simplies the equation needed to calculate payment time into 3 equations
  double log1 = log(payment);
  double log2 = log(payment - (interest/1200.0) * principal);
  double log3 = log((interest/1200.0)+1.0);
  
  //This is the full equation, but simplified 
  result = (log1 - log2) / log3;
  result = round(result);
  
  //Result (which is months to pay off) will be rounded after turned into years.
  double years = round((result/12) * 10000.0 ) / 10000.0 ;
  if(years < 1){
    years = 0;
  }
  
  //This will check if the loan is able to be paid or not. If log2 is NaN (not a number) then that means the log was negative
  //Which means that the loan is unable to be paid off with the current monthly payment. Else, will print out the normal lines
  if(isnan(log2)){
    cout << "This loan is unable to be repaid with your current monthly payment." <<endl<<endl;
  } else {
    cout << result  << " months ("<<setprecision(2)<<years<<" years) are needed to pay your loan off."<<endl<<endl;
  

  //Will increase the input payment by $15 in order to inform user
  //how much earlier their debt will be paid off if they did that
  //Will also redo calculations so accuracy is maintained
  payment = payment + 15; //added $15 to payment
  log1 = log(payment);
  log2 = log(payment - (interest/1200.0) * principal);
  log3 = log((interest/1200.0)+1.0);
  int secondResult = ((log1) - (log2)) / log3;
  
  //Will give a month difference between the two (secondResult will be better)
  int total = round(result) - round(secondResult);
  
  cout << "Did you know if you paid an additional $15 per month, you would pay off your loan " << total << " months earlier?"<<endl<<endl;
  }

}
