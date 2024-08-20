#include "Retirement.h"

//Checks if user input is valid for the estimateEarnings() function
bool Retirement::isValidPayment(string input){
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

double Retirement::estimateEarnings(int currentAge, int ageForComparison, int retirementAge, double amountSavedNow, double plannedContribution, double annualReturn){
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

void Retirement::estimateDriver(){

        //Variables that will be put into estimateEarnings() function
        string currentAge, ageForComparison, retirementAge, amountSavedNow,
               plannedContribution, annualReturn;

        //Will be used to check if user input is valid
        bool valid;

        //Section for reading in user input into variables
        cout<<"Estimate Savings at Retirement"<<endl;
        cout<<"Disclaimer: This is only a rough estimate!"<<endl<<endl;

        cout<<"\tEnter the first starting age in years: ";
        getline(cin, currentAge);
        valid = isValidPayment(currentAge);
        while(!valid){
                cout<<"\tAge cannot be 0 or less."<<endl;
                cout<<"\tRe-enter your age in years: ";
                getline(cin, currentAge);
                valid = isValidPayment(currentAge);
        }

        cout << "\tEnter the second starting age in years: ";
        getline(cin, ageForComparison);
        valid = isValidPayment(ageForComparison);
        while(!valid){
                cout<<"\tAge cannot be 0 or less."<<endl;
                cout<<"\tRe-enter your age in years: ";
                getline(cin, ageForComparison);
                valid = isValidPayment(ageForComparison);
        }

        cout<<"\tEnter your target retirement age: ";
        getline(cin, retirementAge);
        valid = isValidPayment(retirementAge);
        while(!valid || stoi(retirementAge) <= stoi(currentAge) || stoi(retirementAge) <= stoi(ageForComparison)){
                cout<<"\tYour target age cannot be less than or equal your current age."<<endl;
                cout<<"\tRe-enter your target age in years: ";
                getline(cin, retirementAge);
                valid = isValidPayment(retirementAge);
        }


        cout << "\tHow much have you saved already towards retirement?: $";
        getline(cin, amountSavedNow);
        valid = isValidPayment(amountSavedNow);
        while(!valid){
                cout<<"\tYour savings cannot be negative."<<endl;
                cout<<"\tRe-enter your savings: $";
                getline(cin, amountSavedNow);
                valid = isValidPayment(amountSavedNow);
	}

        cout << "\tEnter your monthly contribution to retirement: $";
        getline(cin, plannedContribution);
        valid = isValidPayment(plannedContribution);
        while(!valid){
                cout<<"\tYour monthly contribution cannot be less than or equal to zero."<<endl;
                cout<<"\tRe-enter your monthly contribution: $";
                getline(cin, plannedContribution);
                valid = isValidPayment(plannedContribution);
        }

        cout << "\tEnter the estimated annual return on investment (in percent): ";
        getline(cin, annualReturn);
        valid = isValidPayment(annualReturn);
        while(!valid){
                cout<<"\tYour rate cannot be less than zero."<<endl;
                cout<<"\tRe-enter your rate (in percent): ";
                getline(cin, annualReturn);
                valid = isValidPayment(annualReturn);
        }

        //runs the estimateEarnings() function with string parameters
        //but using stoi() will give the int version of the string
        //and using stod() will give the double version
        estimateEarnings(stoi(currentAge), stoi(ageForComparison), stoi(retirementAge),
                         stod(amountSavedNow), stod(plannedContribution), stod(annualReturn));
}


