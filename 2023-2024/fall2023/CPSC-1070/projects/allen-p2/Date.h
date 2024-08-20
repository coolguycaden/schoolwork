#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <cmath> //used for abs()

using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;

	public:
		//Default and overloaded constructors
		Date() { year = 2000; month = 1; day = 1; }
		Date(int mm, int dd, int yyyy){
			year = yyyy;
		       	month = mm;
		       	day = dd;
			this->changeDate();
	       	}
		
		//Accessor functions
		int getMonth();
		int getDay();
		int getYear();

		//Mutator functions
		void setYear(int yyyy) { year = yyyy; }
		void setMonth(int mm) { month = mm; }
		void setDay(int dd) { day = dd; }

		//Used to manipulate month, year, and day
		//according to operator overloading
		void changeDate();

		//Overloaded operators
		Date operator+(int);
		Date operator-(int);
		
		//Overloaded pre fix operators
		Date operator++();
		Date operator--();

		//Overloaded post fix operators
		Date operator++(int);
		Date operator--(int);

		//Mystery machine implementation
		string getDayOfWeek();

		//Will turn the input string into a date
		//the string MUST MATCH MM DD YYYY format
		Date stringToDate(string);		

		//mm/dd/yyyy format of a Date
		
		string toString(){
			string format = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
			return format;
		};
		
};
#endif
