#ifndef PIZZAWARS_H
#define PIZZAWARS_H
#include "Date.h"
#include "PizzaStore.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class PizzaWars{
	protected:
		static Date * allocateWeekOfDates(Date date);
		// Dynamically allocates & fills a date array with 7 days starting with
		// // the date passed in
		// // The return should point to the first date in the 7-day array
		static void runSeriesSimulation(Date *dates, int length);
		// // Given an array of dates, will iterate through each day and call
		// // runDaySimulation with it. Writes the results from runDaySimulation
		// // to the log.txt using writeToFile
		static string runDaySimulation(Date *datePtr, PizzaStore*C, PizzaStore*S);
		// // Determines which of the two pizza stores win
		// // Returns the name of the store which won
		// // Throughout the day simulation, this will print the status of the stores
		static void marchToSunday(Date* datePtr);
		// Given a pointer to a date object
		// // Will continue incrementing the date until it is Sunday
		static void writeToFile(Date *datePtr, PizzaStore *winner);
		// // Appends a line to log.txt with
		// // "<dayofweek> <mm/dd/yyyy> <winner> won with <slicesLeft> slices left!"
		// // If winner is a null pointer, then use it as a tie
		// // "<dayofweek> <mm/dd/yyyy> Tie!"

	public:
		static void runSimulation();	
};

#endif
