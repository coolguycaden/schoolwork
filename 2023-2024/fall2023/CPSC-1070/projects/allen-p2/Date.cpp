#include "Date.h"
#include "MysteryMachine.h"
using namespace std;

// PRIVATE FUNCTIONS
//
//This function will increment month if
//an incrementation of day would be greater
//than the days in the month
void Date::changeDate(){
    	
	switch(month){
		//Months with 31 days
		//This cases will do subtraction, each month is special
		//because the previous month may not have the same number
		//of days, they are grouped by the number of days in the month
		//before it (For example, January and August both have a previous month
		//with 31 days (December and July)
		case 1:
			if(day < 1){
				month = 12; 
				year--;
				day = 31 - abs(day);
			}

		case 8:
			if(day < 1){
				month--;
				day = 31 - abs(day);
			}

		case 3:
			if(day < 1){
				month--;
				if(year % 400 == 0){
					day = 29 - abs(day);
				} else {
					if(year % 4 == 0){	
						day = 29 - abs(day);
					} else {
						day = 28 - abs(day);
					}
				}
			}

		case 5: case 7: case 10:
			if(day > 31){
				month++;
				day = day - 31; 
			}
			
			if(day < 1){
				month--;
				day = 30 - abs(day);
			}
			
			if(day > 31){
				this->changeDate();
			}

			break;

			
		//END OF REGULAR MONTHS WITH 31 DAYS
		

		//Special because the day after the 
		//31st day of December is the Jan 1st 
		//of the next year
		case 12:
			if(day > 31){
				month = 1;
				year++;
				day = day - 31;
			}

			if(day < 1){
				month--;
				day = 30 - abs(day);
			}

			if(day > 31){
				this->changeDate();
			}

			break;
		
		

		//Months with 30 days
		//All of these months have months before
		//them that have 31 days
		case 4: case 6:
		case 9: case 11:
			if(day > 30){
				month++;
				day = day - 30;
			}

			if(day < 1){
				month--;
				day = 31 - abs(day);
			}

			if(day > 30){
				this->changeDate();
			}
			break;

			//February is special case due to leap years
			//a leap year is when the year is divisble
			//by 4 HOWEVER end-of-century years must be divisble
			//by 400 to be a leap year
		case 2:
			//Checks if the year is an end-of-century year
			//and if the year is divisble by 400
			if(year % 400 == 0){
				if(day > 29){
					month++;
					day = day - 29;
				}

			} else { 
				//Checks if year is leap-year (divisible by 4)
				if(year % 4 == 0){
					if(day > 29){
						month++;
						day = day - 29;
					}

				} else {
					if(day > 28){
						month++;
						day = day - 28;

					}

				}
			}

			if(day < 1){
				month--;
				day = 31 - abs(day);
			}

			break;

	}

}

//Accessor functions

int Date::getDay(){	
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}


//OVERLOADED OPERATORS

Date Date::operator+(int dd){
	Date sum(month, day + dd, year);
	sum.changeDate();
	return sum;
}

Date Date::operator-(int dd){
	Date sum(month, day - dd, year);
	sum.changeDate();
	return sum;
}

//prefix ++ operation
Date Date::operator++(){
	Date sum(month, day + 1, year); 
	sum.changeDate();
	*this = sum;
	return *this;
}

//postfix operation
Date Date::operator++(int dd){
	Date sum(month, day + 1, year);
	sum.changeDate();	
	*this = sum;
	return *this - 1;
}

//prefix operation
Date Date::operator--(){
	Date sum(month, day - 1, year);
	sum.changeDate();
	*this = sum;
	return *this;
}

//postfix operation
Date Date::operator--(int dd){
	Date sum(month, day - 1, year);
	sum.changeDate();
	*this = sum;
	return *this + 1;
}

string Date::getDayOfWeek(){
	std::string day = MysteryMachine::getDayOfWeek((*this));
	return day;
}

/*
 *
 * !!!!! Accidentally made my own getDayOfWeek but don't want 
 * 	 to delete it so I will keep it commented 
 * !!!!!  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
 *
//To explain how this function works is difficult
//https://www.almanac.com/how-find-day-week
//The above link is how I made this function
//the function will do the exact same as the steps
//listed on the website
string Date::getDayOfWeek(){
	
	//Will hold the sum of all the steps
	//and be divided
	int total = 0;
	
	//Step 1: "Take the last two digits of the year"
	//This will get the last two digits
	//of the year
	int digits = year % 100;
	
	//Step 2: "Add to that one-quarter of those two digits (discard any remainder)"
	int remainder = floor(digits / 4);

	//Step 3: "Add to that the day of the month and the Month Key number for that month"
	
	//Will hold Month Key number
	int monthKey;
	
	switch(month){
		case 7: case 4:
			monthKey = 0;
			break;
		
		case 1:
			//If the year is NOT a leap year
			monthKey = 1;

			//If the year IS a leap year
			if((year % 100 == 0 && year % 400) || year % 4 == 0){
				monthKey = 0;
			}
			break;
		
		case 2:
			//If the year is NOT a leap year
			monthKey = 4;

			//If the year IS a leap year
			if((year % 100 == 0 && year % 400) || year % 4 == 0){
				monthKey = 3;
			}
			break;	

		case 10:
			monthKey = 1; 
			break;
		
		case 5:
			monthKey = 2;
			break;

		case 8: 
			monthKey = 3;
			break;

		case 11: case 3:
			monthKey = 4;
			break;

		case 6:
			monthKey = 5;
			break;

		case 9: case 12:
			monthKey = 6;
			break;
	
	}

	total = digits + remainder + monthKey + day;

	//If year is between 2000 and 2099
	//subtract 1 from total and divide by 7
	if(year >= 2000 && year < 2100){
		total -= 1;
		total = total % 7;		
	}

	//If year is between 1900 and 1999
	//divide by 7
	if(year >= 1900 && year < 2000){
		total = total % 7;
	}

	string dayOfWeek;

	//The remainder of the division is the day of the week
	//starting at 0 on Saturday, and ending on Friday with 6
	switch(total){
		case 0:
			dayOfWeek = "Saturday";
			break;
		
		case 1:
			dayOfWeek = "Sunday";
			break;

		case 2:
			dayOfWeek = "Monday";
			break;

		case 3:
			dayOfWeek = "Tuesday";
			break;

		case 4:
			dayOfWeek = "Wednesday";
			break;

		case 5:
			dayOfWeek = "Thursday";
			break;

		case 6:
			dayOfWeek = "Friday";
			break;
	}

	return dayOfWeek;

}
*/

//Takes in a string input and cuts it into 3 parts,
//Month, Day, and Year and then returns a Date with that date
Date Date::stringToDate(string input){
	
	
	int mm = stoi(input.substr(0, input.find(" ")));	
	
	//This cuts the month, and the space out of the input
	input = input.substr((input.find(" ")) + 1);
	
	//This will get the input day
	int dd = stoi(input.substr(0, input.find(" ")));

	//This cuts out everything but the year from the input
	input = input.substr(input.find(" "));
	int yyyy = stoi(input.substr(0));
	
	//Date formed with the values taken from input
	Date t1(mm, dd, yyyy);
	
	return t1;	
}
