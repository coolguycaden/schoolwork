#include "PizzaWars.h"

//Runs all the class' functions from this
//
void PizzaWars::runSimulation(){
	cout << "Welcome to Pizza Wars!\n"
                "This program simulates an epic battle between Core and Schilletter "
                "and their ability to keep up with the demand for pizza!\n"
                "\nPlease enter the date you'd like to start the simulation in MM DD YYYY format: ";

	string input;
	getline(cin, input);

	Date inputDate = inputDate.stringToDate(input);

	Date * datePtr = &inputDate;

	marchToSunday(datePtr);	
	
	//Creates 7 date objects
	datePtr = allocateWeekOfDates(*datePtr);
	


	//Runs the simulations
	runSeriesSimulation(datePtr, 7);
}

//Will loop runDaySimulation() 7 times, thus simulating the
//entire week of battle between the 2 dining halls
void PizzaWars::runSeriesSimulation(Date *dates, int length){
	int temp = 0;

	//A foor loop works here too, but
	//I think a while loop looks cooler
	while( temp < length){
		//Creates a "fresh" Core and Schilletter
		//on each run through
		PizzaStore Core("Core", 3, 2, 0.9);	
		PizzaStore Schilletter("Schilletter", 6, 1, 0.8);

		//Pointers to each of the halls
		PizzaStore * cPtr = &Core;
		PizzaStore * sPtr = &Schilletter;
		
		//Runs the simulation
		cout << "\n\nRunning simulation for " << (*(dates+temp)).getDayOfWeek() << " " << (*(dates+temp)).toString() << "\n\n\n"; 
		string result = runDaySimulation((dates+temp), cPtr, sPtr);
		PizzaStore * winner = NULL;
		
		//Sets a pointer equal to the winner
		if(result == (*cPtr).getName()){
			winner = cPtr; 
		}

		if(result == (*sPtr).getName()){
			winner = sPtr;
		}
		
		writeToFile((dates+temp), winner);
		temp++;
		
	}


}

//Outputs the winner or tie of runDaySimulation to 
//log.txt
void PizzaWars::writeToFile(Date *datePtr, PizzaStore *winner){
	//Appends text to the log file
	ofstream textToAdd("log.txt", ios::app); 

	string day = (*datePtr).getDayOfWeek();

	//This appends the winner or tie to log.txt
	if(winner != nullptr){
		textToAdd << left << setw(10) << day;
	       	textToAdd << left << setw(10) << (*datePtr).toString();
		textToAdd << " " << (*winner).getName() << " won with " 
			<< (*winner).getTotalSlicesLeft() << " slices left!" << endl;
		textToAdd.close();
	} else {
		textToAdd << left << setw(10) << day << setw(10) << (*datePtr).toString() << " Tie!" << endl;
		textToAdd.close();
	}
}

//Creates an array that holds 7 days, starting
//with the day (or nearest sunday) the user put in
Date * PizzaWars::allocateWeekOfDates(Date date){
	static Date dateArray[7];
	
	dateArray[0] = date;

	for(int x = 1; x < 7; x++){
		Date temp(date.getMonth(), date.getDay() + x, date.getYear());
		dateArray[x] = temp;
	}	

	//Returns the memory address of the 
	//first index of the array
	return dateArray;
}

//Runs a simulation of 
string PizzaWars::runDaySimulation(Date *datePtr, PizzaStore *C, PizzaStore *S){
	//Holds the times of the day, each to be printed
	//after each loop of the while loop
	string weekTime[21] = {"11:00", "11:30", "12:00", "12:30", "1:00",
			   "1:30", "2:00", "2:30", "3:00", "3:30",
			   "4:00", "4:30", "5:00", "5:30", "6:00",
			   "6:30", "7:00", "7:30", "8:00", "8:30", "9:00"};
	
	//halfHour will be the index of weekTime
	int halfHour = 0;

	//closingTime depends on the day of the week
	//Weekdays are open from 11am-9pm
	//Weekends 11am-8pm
	//The closing times are different
	int closingTime;
	if((*datePtr).getDayOfWeek() != "Sunday" && (*datePtr).getDayOfWeek() != "Saturday"){
		closingTime = 20;
	} else {
		closingTime = 18;
	}
	
	while(halfHour <= closingTime){
		cout << weekTime[halfHour] << endl;
		
		//This will generate a random demand of pizza
		//and subtract that from the available
		//slices of each hall
		int sliceConsumed = rand() % (20 - 4) + 5;
		bool coreLive = (*C).consumeSlices(sliceConsumed);
		
		sliceConsumed = rand() % (20 - 4) + 5;
		bool schLive = (*S).consumeSlices(sliceConsumed);
		
		(*C).showStatus();
		(*S).showStatus();
		
		//This checks if either dining hall has lost,
		//and returns (or continues) accordingly
		if((coreLive && schLive) && halfHour != closingTime){
			(*C).tickUpdate();
			(*S).tickUpdate();

			(*C).showStatus();
			(*S).showStatus();

			
			cout << endl;
		} else {
			if(coreLive && !schLive){
				cout << "Core wins!" << endl;
				return "Core";
			} else {

				if(!coreLive && schLive){
					cout << "Schilletter wins!" << endl;
					return "Schilletter";
				} else {
					cout << "TIE!" << endl;
					return "tie";
				}
			}
		}
		
		halfHour++;
	}
	return "";
}



//Increases a Date object's day to the closest future 
//Sunday
void PizzaWars::marchToSunday(Date* datePtr){
	if((*datePtr).getDayOfWeek() != "Sunday"){
		cout << "That day is not a Sunday, so we're moving to the nearest future Sunday to start" << endl;
	}
	
	while((*datePtr).getDayOfWeek() != "Sunday"){
		(*datePtr)++;
	}

	cout << "Starting on " << (*datePtr).toString() << endl;
}
