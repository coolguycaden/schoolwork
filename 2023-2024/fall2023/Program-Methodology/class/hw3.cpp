#include <iostream>
#include <string>

using namespace std;

class Point{
	private:
		int xCoord;
		int yCoord;
	
	public:
		Point(int x, int y)
		{ xCoord = x; yCoord = y; }

		void operator+(const Point Right)
		{ xCoord += Right.xCoord;
		  yCoord += Right.yCoord;
		}

		string toString(){
			string format = xCoord + " " + yCoord;
			return format;
		}
};

double recSum(double array[], int count){
	if(count == 0 || count == 1){
		return array[0];
	} else {
		return (array[count - 1] + recSum(array, count - 1)); 
	}
}

int main(){
	Point p(1, 1);
	Point s(2, 2);

	Point n(0, 0);

	double arr[4] = {5, 4, 2, 12};
	//n = p + s;

	//cout << "n is " << n.toString() << endl;

	//cout << " return is " << recSum(arr, 4) << endl;

	//int values [5]= {2, 4, 6, 8, 10};
	//cout << " v is " << values << endl;
	int f;
	cout << " f is " << &f << endl;
	int * vPTR;

	cout << "ptr is " << vPTR << endl;
	
	for(int x = 0; x < 5; x++){
		//cout << "values [" << x << "] is: " << values[x] << endl;
	}
	//vPTR = values + 4;
	//cout << " pointer is " << *vPTR << endl;
}
