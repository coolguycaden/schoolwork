#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include <iostream>
#include <unistd.h> // for usleep 
#include <cmath> //for random number
#include <ctime> //For random seeding 
#include <iomanip> // For setw

using namespace std;

class PizzaStore {
	private:
		string name;
		string pizzasLeft;
		int maxPizzas;
		int slices;
		double productionPerTick;
		double successRate;
	
		
	public:	

		//Constructors
		PizzaStore(){
			name = "Default";
			maxPizzas = 5;
			slices = 40;
			pizzasLeft = "8 8 8 8 8";
			productionPerTick = 2.0;
			successRate = 0.9;
		}

		PizzaStore(string store, int max, double production, double success){
			name = store;
			maxPizzas = max;
			pizzasLeft = "";
			for(int x = 0; x < max; x++){
				pizzasLeft += "8 "; 
			}

			slices = max * 8;
			productionPerTick = production;
			successRate = success;
		}

		//Resets pizzasLeft and slices
		//so that each object can be reused
		void reset();
			
		int tickUpdate();
		
		//Returns how many pizzas have at least 1 slice
	//	int getPizzasLeft();

		//Removes slices, returns false if demand is 
		//greater than available slices left
		bool consumeSlices(int);
		
		//Shows PizzaStore's name and the amount of pizzas left in
		//a specific format
		void showStatus();

		//returns name of PizzaStore
		string getName();

		//Returns slices left
		int getTotalSlicesLeft();
};

#endif
