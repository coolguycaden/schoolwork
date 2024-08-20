/* Caden Allen
 * A++
 * CPSC 1071
 * 10/1/2023
 *
 * Clementine Finnacial
 *
 * 	An investment calculator and debt repayment calculator. Takes in user's inputs and calculates the results.
 *
 * 	Used https://www.investor.gov/financial-tools-calculators/calculators/compound-interest-calculator as a reference
 * 	for accuracy on month-to-month calculations for the investment calculator
 *
 */


#include <iostream>
#include <cmath>
#include <iomanip>

//Used for finding substring of user principal
//for debt payment calculator
#include <string>

using namespace std;

//Prototypes here so that I do not have to rearrange 
//function locations
int paymentMonths(double, double, double);
void runMenuSystem();

//Checks if user input is valid for the estimateEarnings() function
//and the paymentMonths() function
bool isValidPayment(string input){
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

//This function will check if user input
bool isValidMenu(string input){
	//If user input is not one, then the
	//input is obviously invalid
	if(input.length() != 1){
		return false;
	}
	
	//Checks if user input is an available option
	//(E, L, or Q), is NOT case-sensitive 
	switch(input.at(0)){
		case 'E': case 'e':
		case 'L': case 'l':
		case 'Q': case 'q':
			return true;
		
		default:
			return false;
	}

	return false;
}

double estimateEarnings(int currentAge, double ageForComparison, int retirementAge, double amountSavedNow, double plannedContribution, double annualReturn){
	cout<<".\n.\n...calculating\n";

	cout<<"For starting to save at retirement at age " << currentAge<< ":\n\n";

	double firstSavings = amountSavedNow;
	double firstGrowth;
	
	//This will make the APR into a monthly interest rate for the savings calculation
	double monthlyReturn = annualReturn / 12;
	
	//This will make monthlyReturn into a percentage ( out of 100)
	monthlyReturn *= 0.01; 
	
	//The difference in years between the two input ages
        //abs() used in case ages are different
        int differenceInYears = abs(currentAge - ageForComparison);
	
	//Calculate how long to compound interest
	int months = (retirementAge - currentAge) * 12;

	//Compounds interest monthly, along with added in contribution after interest
	for(int x = 1; x <= months; x++){
		firstSavings *= (1 + monthlyReturn);
	       	firstSavings += plannedContribution;
	}	
	
	//Growth is just principal and contribution removed from total
	firstGrowth = firstSavings - ((plannedContribution * months) + amountSavedNow);
	
	//Same exact calcuations above, but the beginning investment age is ageForComparison
	double secondSavings = amountSavedNow;
	double secondGrowth;
	
	months = (retirementAge - ageForComparison) * 12;
        
	for(int x = 1; x <= months; x++){
                secondSavings *= (1 + monthlyReturn);
                secondSavings += plannedContribution;
	}	

	//Growth is only the interest acculumated on principal
	//and contribution
	secondGrowth = secondSavings - ((plannedContribution * months) + amountSavedNow);
	
	//Difference between the earlier invest(firstSavings) 
	//and the later investment (second savings)
	//abs() is used because either savings could be the 
	//earlier one
	double differenceInSavings = abs(firstSavings - secondSavings);	
	
	firstSavings = round(firstSavings * 100.0 ) / 100.0;
	secondSavings = round(secondSavings * 100.0) / 100.0;

	cout << "Estimated Retirement Savings: $" << fixed << setprecision(2) << firstSavings << endl;
        cout << "Estimated Retirement Growth: $" << firstGrowth << endl << endl;

        cout << "For starting to save at retirement at age " << setprecision(0) << ageForComparison << ":"<<endl << endl;
	
	cout << "Estimated Retirement Savings: $" << setprecision(2) << secondSavings <<endl;
	cout << "Estimated Retirement Growth: $" << secondGrowth << endl;
		
	cout <<"\n\n\nFor a difference in waiting " << differenceInYears << " years before starting to invest";
	cout<<" in retirement, you can miss out potentially on $" << differenceInSavings << endl;
	
	return firstSavings; 
}

void estimateDriver(){

	//Variables that will be put into estimateEarnings() function
	string currentAge, ageForComparison, retirementAge, amountSavedNow, 
	       plannedContribution, annualReturn;
	
	//Will be used to check if user input is valid
	bool valid;

	//Section for reading in user input into variables
	cout<<"Estimate Savings at Retirement"<<endl;
	cout<<"Disclaimer: This is only a rough estimate!"<<endl<<endl;

	cout<<"\tEnter the first starting age in years: ";
	cin >> currentAge;
	valid = isValidPayment(currentAge);
	while(!valid){
		cout<<"\tAge cannot be 0 or less."<<endl;
		cout<<"\tRe-enter your age in years: ";
		cin >> currentAge;		
		valid = isValidPayment(currentAge);
	}
	
	cout << "\tEnter the second starting age in years: ";
	cin >> ageForComparison;
        valid = isValidPayment(ageForComparison);
        while(!valid){
                cout<<"\tAge cannot be 0 or less."<<endl;
                cout<<"\tRe-enter your age in years: ";
                cin >> ageForComparison;
                valid = isValidPayment(ageForComparison);
        }

	cout<<"\tEnter your target retirement age: ";
	cin >> retirementAge;
	valid = isValidPayment(retirementAge);
	while(!valid || stoi(retirementAge) <= stoi(currentAge) || stoi(retirementAge) <= stoi(ageForComparison)){
                cout<<"\tYour target age cannot be less than or equal your current age."<<endl;
                cout<<"\tRe-enter your target age in years: ";
                cin >> retirementAge;
                valid = isValidPayment(retirementAge);
        }	
	

	cout << "\tHow much have you saved already towards retirement?: $";
	cin >> amountSavedNow;
	valid = isValidPayment(amountSavedNow);
	while(!valid){
                cout<<"\tYour savings cannot be negative."<<endl;
                cout<<"\tRe-enter your savings: $";
                cin >> amountSavedNow;
                valid = isValidPayment(amountSavedNow);
        }

	cout << "\tEnter your monthly contribution to retirement: $";
	cin >> plannedContribution;
	valid = isValidPayment(plannedContribution);
	while(!valid){
                cout<<"\tYour monthly contribution cannot be less than or equal to zero."<<endl;
                cout<<"\tRe-enter your monthly contribution: $";
                cin >> plannedContribution;
                valid = isValidPayment(plannedContribution);
        }

	cout << "\tEnter the estimated annual return on investment (in percent): ";
	cin >> annualReturn;  
	valid = isValidPayment(annualReturn);	
	while(!valid){
                cout<<"\tYour rate cannot be less than zero."<<endl;
                cout<<"\tRe-enter your rate (in percent): ";
                cin >> annualReturn;
                valid = isValidPayment(annualReturn);
        }	

	//runs the estimateEarnings() function with string parameters
	//but using stoi() will give the int version of the string
	//and using stod() will give the double version
	estimateEarnings(stoi(currentAge), stoi(ageForComparison), stoi(retirementAge), 
			 stod(amountSavedNow), stod(plannedContribution), stod(annualReturn));	

	

	string input;

        do {
                if(!valid){
                        cout << "Invalid input, input must be y or n." << endl;
                }
                cout << "Calculate another estimate? (y/n): ";
                cin >> input;
                if(input.length() == 1 && (input.at(0) == 'y' || input.at(0) == 'n')){
                        valid = true;
                } else {
                        valid = false;
                }
        } while (!valid);

        cout << endl;

        if(input.at(0) == 'y'){
                estimateDriver();
        } else {
                runMenuSystem();
        }	
}

void paymentDriver(){
	//These variables will go into paymentMonths()
	//but they are strings for easy input validation
	string principal;
	string payment;
	string interest;
	
	cout<<"Loan Payment Calculator"<<endl<<endl;

	//Section for reading in user input
	
	cout<<"Enter the principal amount: $";
	cin >> principal;
	
	//Checks if input is valid
	bool valid = isValidPayment(principal);
	while(!valid){
		cout<<"Invalid value, try again: ";
		cin>>principal;
		valid = isValidPayment(principal);		
	}
	

	cout<<"Enter the annual interest rate (in percent): ";
	cin >> interest;
	
	valid = isValidPayment(interest);

	while(!valid){
		cout<<"Invalid value, try again: ";
		cin >> interest;
		valid = isValidPayment(interest);
	}

	cout<<"Enter the monthly payment: $";
        cin >> payment;

	//Checks if input is valid
        valid = isValidPayment(payment);
        
	while(!valid){
                cout<<"Invalid value, try again: ";
                cin>>payment;
		valid = isValidPayment(payment);
        }

	cout<<"\nCalculating..."<<endl<<endl;
	
	paymentMonths(stod(principal), stod(interest), stod(payment));
	
	string input;
	
	do {
		if(!valid){
			cout << "Invalid input, input must be y or n." << endl;
		}
		cout << "Calculate another loan payoff? (y/n): ";
		cin >> input;
		if(input.length() == 1 && (input.at(0) == 'y' || input.at(0) == 'n')){
                	valid = true;
		} else {
			valid = false;
		}
	} while (!valid);

	cout << endl;

	if(input.at(0) == 'y'){
		paymentDriver();
	} else {
		runMenuSystem();
	}
}

void runMenuSystem(){
	string input;
	bool valid;
	
	do {
		cout<<"******* Welcome to Clementine Financial *******"<<endl;
	
		cout<<"\nMenu: "<<endl;
		cout<<"\t[E] Estimate how much money at retirement"<<endl;
		cout<<"\t[L] Loan payoff calculator"<<endl;
		cout<<"\t[Q] Quit program"<<endl;

		cout<<"\n Enter your choice and press enter: ";
		cin >> input;

		valid = isValidMenu(input);
		
		if(!valid){
			cout<<"\nThe provided choice was invalid! Please select again."<< endl<<endl;
		}
	} while(!valid); 

	switch(input.at(0)){
                case 'E': case 'e':
			estimateDriver();
			break;
               		 
		case 'L': case 'l':
			paymentDriver();
			break;
                
		case 'Q': case 'q':
                       
			break;
                
		default:
        		break;                
	
        }

}

int paymentMonths(double principal, double interest, double payment){
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
  
	cout << "R is: " << result << "    S: " << secondResult << endl;

  //Will give a month difference between the two (secondResult will be better)
 int total = round(result) - round(secondResult);
  
  cout << "Did you know if you paid an additional $15 per month, you would pay off your loan " << total << " months earlier?"<<endl<<endl;
	
  }
	cout<<"rounded r: " << round(result);  
  return round(result);
}

int main(){	
	runMenuSystem();	
		


}
