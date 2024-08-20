#include "PizzaStore.h"

using namespace std;

string PizzaStore::getName(){
	return name;
}

//This function takes away slices from the "pizzas" left in
//the pizzasLeft variable
bool PizzaStore::consumeSlices(int consumed){
	
	//Holds how many slices should be left, after 
	//accounting for consumption
	int temp = getTotalSlicesLeft() - consumed;

	//Decreases slices in pizzasLeft until the total matches
	//the temp variable (slices left after consumption)
	while(slices > temp && slices > 0){
		//Searches for pizza that has slices left (1-8 slices)
		//and get its index
		int index = pizzasLeft.find_first_not_of("abcdefghijklmnopqrstuvwxyz0 ");
		
		//Removes one slice from that pizza
		pizzasLeft[index] = (static_cast<int>(pizzasLeft[index])) - 1;
		
		slices--;
	}
	
	cout << consumed << " slice(s) are consumed at " << name << endl;
	if(slices == 0){
		
		return false;
	}
	
	return true; 
}


int PizzaStore::getTotalSlicesLeft(){
	int slicesLeft = 0;


	//Uses a trick with ASCII. The int value of char can be gotten
	//from subtracting the int value of '0' from the char you want
	//an int value from	
	for(int x = 0; x < static_cast<int>(pizzasLeft.length()); x += 2){
		slicesLeft += (static_cast<int>(pizzasLeft[x]) - static_cast<int>('0'));
	}

	return slicesLeft;
}
/*
//Returns the number of pizzas left by counting
//The values of the characters in the pizzasLeft string
int PizzaStore::getPizzasLeft(){
	int pizzaWithSlice = maxPizzas;

	for(int x = 0; x < pizzasLeft.length(); x += 2){
		
		//The ASCII of '0' is 48
		if(static_cast<int>(pizzasLeft[x]) == 48){
			pizzaWithSlice--;
		}
	}

	return pizzaWithSlice;
}
*/

//This function has been rendered largely redundant due to
//some design choices I made. I incorporated a built in
//pizzasLeft string which would hold all my slices
void PizzaStore::showStatus(){
	cout << setw(20) << name << ": " << pizzasLeft << endl;	
		
}

//Bakes and adds pizzas
int PizzaStore::tickUpdate(){
	usleep(50000);

	//How many pizzas added each tick
	int pizzasAdded = 0;


	for(int x = 0; x < static_cast<int>(pizzasLeft.length()); x += 2){
		
		if(pizzasAdded == productionPerTick){
			cout << pizzasAdded << " pizza(s) were added at " << name << endl;
			return 0;
		}

		//The ASCII of '0' is 48
		if(static_cast<int>(pizzasLeft[x]) == 48){
			//Checks if pizza is dropped or not
			//before adding a pizza
		
			double isDropped = ((rand() % 100) + 1) / 100;
			//if successrate is higher, pizza
			//IS NOT dropped
			if(isDropped < successRate){
				pizzasLeft[x] = '8';
				pizzasAdded++;
				slices += 8;
			} 
	
		}

	}

	cout << pizzasAdded << " pizza(s) were added at " << name << endl;
	return 0;
	
}

void PizzaStore::reset(){
	for(int x = 0; x < static_cast<int>(pizzasLeft.length()); x+= 2){
		pizzasLeft[x] = '8';
		slices += 8;
	}
}
