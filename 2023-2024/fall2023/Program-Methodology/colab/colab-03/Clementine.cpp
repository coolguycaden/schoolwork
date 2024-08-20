#include <iostream>
#include <istream>
#include "Retirement.h"
#include "Loan.h"
#include "Register.h"

using namespace std;

//Checks if user wants to do another calculation
//the parameter type will be used to change text depending on
//which menu option is run
bool goAgain(int type){
        bool valid = true;
        string input;

        do {
                if(!valid){
                        cout << "Invalid input! Please choose again." << endl;
                }
		cout << endl;
		//Text changes depending on section
		if(type == 1){
			cout << "Calculate another estimate? (y/n): ";
		}
		if(type == 2){
			cout << "Calculate another loan payoff? (y/n): ";
		}
		if(type == 3){
			cout << "Would you like to process another transaction register? (y/n): ";
		}

                cin >> input;

                //Checks if input is valid
                if(input.length() == 1 && (input.at(0) == 'y' || input.at(0) == 'n' || input.at(0) == 'N' || input.at(0) == 'Y')){
                        valid = true;
                } else {
                        valid = false;
                }

        } while (!valid);

        cout << endl;

        if(input.at(0) == 'y'){
                return true;
        } else {
                return false;
        }
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
		case 'R': case 'r':
			return true;

                default:
                        return false;
        }

        return false;
}


void runMenuSystem(){
        string input;
        bool valid;

        do {
                cout<<"******* Welcome to Clementine Financial *******"<<endl;

                cout<<"\nMenu: "<<endl;
                cout<<"\t[E] Estimate how much money at retirement"<<endl;
                cout<<"\t[L] Loan payoff calculator"<<endl;
                cout<<"\t[R] Run transaction classifier"<<endl;
		cout<<"\t[Q] Quit program"<<endl;

                cout<<"\n Enter your choice and press enter: ";
                getline(cin, input);

                valid = isValidMenu(input);

                if(!valid){
                        cout<<"\nThe provided choice was invalid! Please select again."<< endl<<endl;
                }

        } while(!valid);

        switch(input.at(0)){
                case 'E': case 'e':
			valid = true;
			while(valid){
				Retirement r;
				r.estimateDriver();
				valid = goAgain(1);
			}
			runMenuSystem();
			break;

                case 'L': case 'l':
			valid = true;
			while(valid){
				Loan l;
				l.paymentDriver();
				valid = goAgain(2);
			}
			runMenuSystem();
			break;
		
		case 'R': case 'r':
			valid = true;
			while(valid){
				Register r;
				r.processTransaction();
				valid = goAgain(3);
			}
			runMenuSystem();	
			break;

                case 'Q': case 'q':
			
                        break;

                default:
                        break;

        }

}

int main(){
	cout << "Starting Clementine Financial Bank" <<endl;
	runMenuSystem();
}
