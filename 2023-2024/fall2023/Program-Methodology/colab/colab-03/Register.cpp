#include "Register.h"

//Prompts user for a file to read from
string Register::getFileName(){
	
	cout << "\tPlease enter the filename: ";

	cin >> fileName;

	cout << "\n\tOpening the file <" << fileName << ">" << endl;

	ifstream file(fileName);

	//This checks if the file exists
	if(file.fail()){
		cout << "Error opening file. Please retry." << endl;
		getFileName();
	}

	return fileName;
}

//Takes in enum values of Transaction and easily
//turns them into equivalent strings
string Register::enumToString(int t){
	switch(t){
		case 0:
			return "Restaurant";
		case 1:
			return "Merchandise";
		case 2:
			return "Utility";
		case 3:
			return "Coffeeshop";
		case 4:
			return "Automotive";
		case 5:
			return "Deposit";
		default:
			return "Other";
	}

	return "INVALID";
}

//Turns a string into a value of the enum Transactions
//Works based on the first letter of the "category" of the
//enum type (each enum category has a unique first letter)
//returns the Transactions value of the character
int Register::stringToEnum(char firstLetter){
	switch(firstLetter){
		case 'R':
			return 0;
		case 'M':
			return 1;
		case 'U':
			return 2;
		case 'C':
			return 3;
		case 'A':
			return 4;
		case 'D':
			return 5;
		default:
			return 6;
	}
}

//Adds file data into the classes' private vectors
//returns true if the data has been applied succesfully
//else, returns false
bool Register::readFromFile(){
	ifstream file(fileName);
	
	string line;

	//This will continue to loop
	//as long as there is a line to be read
	while(getline(file, line)){
		int startIndex = 0;
		string temp;

		//Loops through a line 4 times, getting each of 
		//the 4 different data and putting them
		//into their respective vectors
		for(int x = 0; x < 4; x++){
			//This will cut off information that has already
			//been used once x < 0
			temp = line.substr(startIndex);

			//Gets a substring of the line of desired information
			temp = temp.substr(0, temp.find(" "));

			switch(x){
				case 0:
					fileDates.push_back(temp);
					break;	
				
				case 1:
					fileTypes.push_back(stringToEnum(temp[0]));
					break;
			
				case 2:
					fileLocations.push_back(temp);
					break;
				
				case 3:
                                        fileAmounts.push_back(stod(temp));
					break;
			
			}

			//Sets start index to the start of the next "category"
			//(the index will be the next first letter)
			startIndex += temp.length() + 1;
		}
	}

	return true;
}

void Register::printFile(){
	cout << "Printing Transaction Ledger" << endl;

	for(size_t i = 0; i < fileTypes.size(); i++){
		cout << setw(10) << fileDates.at(i) << " |";
		cout << setw(15) << fileLocations.at(i) << " |";
		cout << fixed << setprecision(2) << setw(10) << fileAmounts.at(i) << " |";
		cout << setw(9) << right << "   " << enumToString(fileTypes.at(i)) << endl;	
		cout << left << endl;
	}	
}

bool Register::processTransaction(){
	getFileName();
	readFromFile();
	printFile();
	return false;	
}
