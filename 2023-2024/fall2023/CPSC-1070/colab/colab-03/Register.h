#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// !!! More detailed commenting on functions in !!!
// !!! Register.cpp file			!!!
class Register {

	private:
		string fileName;
		vector<string> fileDates;
		vector<int> fileTypes;
		vector<string> fileLocations;
		vector<double> fileAmounts;		
		enum Transaction {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
	public:

		//Mutator method
		void setFileName(string f) {fileName = f;}
		
		//Prompts user for file to read from		
		string getFileName();
		
		//Adds file data into respective vectors
		bool readFromFile();

		//Prints the file transactions in neat format
		void printFile();


		int stringToEnum(char);

		//Easy way to read enum values to strings
		string enumToString(int);
		
		//Runs the rest of the functions
		bool processTransaction();
};

#endif 
