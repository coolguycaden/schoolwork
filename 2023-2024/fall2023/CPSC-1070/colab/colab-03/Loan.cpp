#include "Loan.h"
//Checks if user input is valid for the estimateEarnings() function
//and the paymentMonths() function
bool Loan::isValidLoan(string input){
	for(int x = 0; x < static_cast<int>(input.length()); x++){
                //Checks if certain part of input is a digit or not
                //if not a digit then the input is invalid
                if(!isdigit(input[x])){
                        return false;
                }

                //Values cannot be negative
                if(input[x] == '-'){
                        return false;
                }

        }

        //The input cannot be zero or start with zero
        if(input.at(0) == '0'){
                return false;
        }

        return true;
}

int Loan::paymentMonths(double principal, double interest, double payment){
  double result;

  //Simplies the equation needed to calculate payment time into 3 equations
  double log1 = log(payment);
  double log2 = log(payment - (interest/1200.0) * principal);
  double log3 = log((interest/1200.0)+1.0);

  //This is the full equation, but simplified
  result = (log1 - log2) / log3;

  //Result (which is months to pay off) will be rounded after turned into years.
  double years = round((result/12) * 100.0) / 100.0;

  if(years < 1){
    years = 0;
  }
  //This will check if the loan is able to be paid or not. If log2 is NaN (not a number) then that means the log was negative
  //Which means that the loan is unable to be paid off with the current monthly payment. Else, will print out the normal lines
  if(isnan(log2)){
    cout << "This loan is unable to be repaid with your current monthly payment." <<endl<<endl;
  } else {
    cout << fixed << setprecision(0) << round(result) << " months ("<< setprecision(1) << years<<" years) are needed to pay your loan off."<<endl<<endl;


  //Will increase the input payment by $15 in order to inform user
  //how much earlier their debt will be paid off if they did that
  //Will also redo calculations so accuracy is maintained
  payment = payment + 15; //added $15 to payment
  log1 = log(payment);
  log2 = log(payment - (interest/1200.0) * principal);
  log3 = log((interest/1200.0)+1.0);
  //Should be a double, but left for future
  int secondResult = ((log1) - (log2)) / log3;


  //Will give a month difference between the two (secondResult will be better)
 int total = round(result) - round(secondResult);

  cout << "Did you know if you paid an additional $15 per month, you would pay off your loan " << total << " months earlier?"<<endl<<endl;

  }
  
  return round(result);
}

void Loan::paymentDriver(){
        //These variables will go into paymentMonths()
        //but they are strings for easy input validation
        string principal;
        string payment;
        string interest;

        cout<<"Loan Payment Calculator"<<endl<<endl;

        //Section for reading in user input

        cout<<"Enter the principal amount: $";
        getline(cin, principal);

        //Checks if input is valid
        bool valid = isValidLoan(principal);
        while(!valid){
                cout<<"Invalid value, try again: ";
                getline(cin, principal);
                valid = isValidLoan(principal);
        }


        cout<<"Enter the annual interest rate (in percent): ";
        getline(cin, interest);

        valid = isValidLoan(interest);

        while(!valid){
                cout<<"Invalid value, try again: ";
                getline(cin, interest);
                valid = isValidLoan(interest);
        }

        cout<<"Enter the monthly payment: $";
        getline(cin, payment);

        //Checks if input is valid
        valid = isValidLoan(payment);

        while(!valid){
                cout<<"Invalid value, try again: ";
                getline(cin, payment);
                valid = isValidLoan(payment);
        }

        cout<<"\nCalculating..."<<endl<<endl;

        paymentMonths(stod(principal), stod(interest), stod(payment));
}
