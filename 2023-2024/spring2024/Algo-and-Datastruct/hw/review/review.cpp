#include "review.h"
//#include <iostream>
//using namespace std;
// This function will take in a prompt from a user, and will print
// out the first 3 space-separated inputs on separate
//
// I.E an entered prompt of "1 -3.5 hello" the result will be 
// "
// 1
// -3.5
// hello
// "
void ReadStdIn(){
	
	//This will hold the input line
	string input;
 
 	//This will store user input as a string
	getline(cin, input);
	
	//This will be used to check if the max of 
	//three inputs or less has been reached
	int spaces = 0;

	//This will loop through the user input, dividing the input
	//based on spaces and print the characters before the space
	//
	//This does not account for the input having less than 3 spaces
	while(spaces < 3 ){
		//Holds a substring based on the index of the
		//next space
		string temp = input.substr(0, input.find_first_of(" "));
		
		if(spaces == 0 && (temp.find_first_of(".") != string::npos)){
			//This accounts for the special case where the input text
			//has the int entered as a double, this will split
			//the double into an int, and then the decimal value
			
			//This splits the integer part of the input into an int and
			//prints that out
			cout << stoi(temp.substr(0, temp.find_first_of("."))) << endl;
			
			//This splits the decimal off the input into a decimal itself
			double doubleValue = stod(temp.substr(temp.find_first_of(".") + 1));
			
			//This fixes an error where a decimal value is represented as a 
			//whole value
			//i.e .6 would be printed as 6 
			if(doubleValue / 10.0 < 1.0){
				cout << doubleValue / 10.0 << endl;
			} else {
				cout << doubleValue << endl;
			}


			spaces = 2;
		} else {

			//This runs if the user input the text
			//normally, printing input up to a space
			switch(spaces){
				case 0:
					cout << stoi(temp) << endl;
					break;
				
				case 1:
					
					cout << stod(temp) << endl;
					break;
				
				case 2:
					cout << temp << endl;
					break;
			}
			spaces++;
		}
		
		
		//This removes everything found up to and including
		//the current space
		input.erase(0, temp.length() + 1);

	}
}

int WriteOut(string output){
	cout << output << endl;
	return 1;
}

int WriteOut(int output){
	cout << output << endl;
	return 2;
}

int WriteOut(double output){
	cout << output << endl;
	return 3;
}

//Reads in user input character by character, if the user
//puts in a 'q' then the program ends
void ReadStdIn2(){

	//This keeps track of how many characters were typed before 'q'
	//was typed
	int wordsInput = 0;

	//String to be checked
	string input;
	
	//Continues reading in input as long
	//as q is not found
	do {
		//getline(cin, input);
		
		cin >> input;
		//This checks there is no empty input
		/*if(input.find_first_not_of(' ') != string::npos){

			//loops through the entered input making sure 
			//no q is found

			for(unsigned x = 0; x < input.length(); x++){

				//This allows for more than one word or character
				//to be entered at once and counted
				if(x == input.length() - 1 || (input[x] == ' ' && input[x + 1] != ' ')){
					wordsInput++;
					//cout << " increased ";

					//This accounts for input with just a space or 
					//puncuation
					if((input[x] == ' ' && input.length() <= 1) || 
							(ispunct(input[x]) && input.length() <= 1 )){
						wordsInput--;
						//	cout << " minus ";
					}
					
				}
			}
		}*/
		wordsInput++;
	} while (input != "q");
	
	//This prints out the words entered without q
	//and subtracts one to account for off by one error
	cout << wordsInput - 1<< endl;	
}



//Reads in user input character by character, if the user
//puts in a 'q' then the program ends
void ReadWrite(){
	//String to be checked
	string input;

	string output;
	
	//Continues reading in input as long
	//as q is not found
	do {
		//getline(cin, input);
		cin >> input;
		//This checks there is no empty input
		/*if(input.find_first_not_of(' ') != string::npos){

			//loops through the entered input making sure 
			//no q is found

			for(unsigned x = 0; x < input.length(); x++){

				//This allows for more than one word or character
				//to be entered at once and counted
				if(x == input.length() - 1 || (input[x] == ' ' && input[x + 1] != ' ')){
					wordsInput++;
					//cout << " increased ";

					//This accounts for input with just a space or 
					//puncuation
					if((input[x] == ' ' && input.length() <= 1) || 
							(ispunct(input[x]) && input.length() <= 1 )){
						wordsInput--;
						//	cout << " minus ";
					}

					//	if(input
				}
			}
			*/
		if(input != "q"){
			output += input;
			output += " ";
		}
	} while (input != "q");
	
	//This prints out the words entered without q
	//and subtracts one to account for off by one error

	cout << output << endl;	
}




vector <int> InitializeArray(int size){
	vector <int> newVector;
	for(int x = 0; x < size; x++){
		newVector.push_back(0);
	}

	return newVector;

}

void LoopThrough(double * data, int size){
	double * firstIndex = data;

	for(int x = 0; x < size; x++){
		(*(firstIndex + x))++;
	}
}

int Fibonacci(int a){
	
	//base case
	if(a == 1 || a == 0){
		return a;
	}
	return (Fibonacci(a - 2) + Fibonacci(a - 1));

}















