#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void printTriangle(){
	for(int x = 1; x <= 7; x++){
		for(int y = 0; y < abs(7 - abs(7 - (x * 2 - 1))); y++){
			cout << "+";
		}
		cout << endl;
	}

}
// 			x
// 7 - 6     7 - 1      1
// 7 - 4     7 - 3      2
// 7 - 2     7 - 5	3
// 7 - 0     7 - 7	4
// 7 - 2     7 - 9	5
// 7 - 4     7 - 11	6
// 7 - 6     7 - 13	7

double noonTemperatureAvg(int timeAndTemp[7][24]){
	double total = 0;

	for(int x = 0; x < 7; x++){
		total += timeAndTemp[x][12];
	}
	total /= 7;

	return total; 
}

void jazzhands(){
	vector <int> x (1000, 0);
	for(int y = 0; y < x.size(); y++){
		x[y] = 1000 - y;
	}
}

class BakedGood{
private:
 string good;
public:
 BakedGood(){cout<<"BakedGood constructor!"<<endl; good = "generic"; }
 BakedGood(string name) {good = name;}
 ~BakedGood() {cout<<"\tBakedGood destroyed!"<<endl;}
 void print() {cout<<"I'm a "<<good<<endl;}
 string get() {return good;};
 
};

int main(){

	const int numRows = 7;
	const int numCols = 2;
	int total; 
	string weekend[] = {"Saturday", "Sunday"};
	int wkEndHrs[numRows][numCols] = {{8,0}, {0, 17}, {5, 6}, {8, 2}};

	for (int row = 0; row < numRows; row++){
		total = wkEndHrs[row][0] + wkEndHrs[row][1];
		cout<<(row+1)<<"\t"<<total<<endl;
	}	

	cout << "\n\nEND OF FIRST\n\n";

 	for (int col = 0; col < numCols; col++){
 		total = 0;
 		for (int row = 0; row < numRows; row++){
			total += wkEndHrs[row][col];
 		}
 		cout<<weekend[col]<<"\t"<<total<<endl;
 	}

	cout <<"\n\nEND OF 1\n\n";

	enum Department {Purchasing, Manufacturing, Warehouse, Sales};
 	Department floor1, floor2;
 	int dNum = 2;

	floor1 = Sales; //statement A   not work
	dNum = Sales; //statement B  works
 	dNum = floor1; //statement C  
 	floor2 = static_cast<Department>(dNum); //statement D work

	
	
	//Use another for loop for bottom

	printTriangle();
	
	unsigned seed;
	srand(seed); 
	
	int temp[7][24];
	for(int x = 0; x < 7; x++){
		for(int y = 0; y < 24; y++){
			int num = rand() % 80 + 1;
			temp[x][y] = num;
		}
	}

	double avg = noonTemperatureAvg(temp);
	//cout << "Avg is: " << fixed << avg << endl;

	
	jazzhands();

	
}
