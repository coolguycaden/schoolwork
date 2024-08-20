#include "Date.h"
#include "PizzaStore.h"
#include "PizzaWars.h"

using namespace std;

int main() {
	unsigned int seed = time(0);
	srand(seed);
	
	PizzaWars::runSimulation();

}
