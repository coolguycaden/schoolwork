/*
 * Name: Caden Allen
 * Date Submitted: 3/11/24
 * Lab Section: 001
 * Assignment Name: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
    
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename);

//This will find the smallest distance between two points in a cell of the passed in grid
double findSmallestDistance(vector<point> &cell, point &currentPoint);

//The distance formula given but as a simple function
double distanceFormula(point &one, point &two);

/*
int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}
*/

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename){
	ifstream file;
	file.open(filename);
	string line;
	getline(file, line);

	//This is the value of b mentioned in the lab
	//considering that a square is side^2
	//I thought it would be good to sqrt the point amount
	//that would relatively match the given number
	//The value is also rounded down to a whole number
	int boxWidth = sqrt(stod(line));

	double interval = (stod(line) / boxWidth) / stod(line);
	
	vector<vector<vector<point>>> grid;
	grid.resize(boxWidth);
	for(int x = 0; x < boxWidth; x++){
		grid[x].resize(boxWidth);
	}

	while(getline(file, line)){
		point p;
		int index = line.find_first_of(" ");
		p.x = stod(line.substr(0, index));
		p.y = stod(line.substr(index + 1, line.size() - 1));
		
		int xpos = p.x / interval;
		int ypos = p.y / interval;
		
		grid[xpos][ypos].push_back(p);
	}
	
	int x = 0;
	int y = 0;
	int z = 0;

	double closest = 1;
	while(x < (int) grid.size()){
		while(y < (int) grid[x].size()){
			while(z < (int) grid[x][y].size()){
				point currentPoint = grid[x][y][z];
				double distance;

				if(x + 1 < boxWidth){
					vector<point> row = grid[x + 1][y];
					distance = findSmallestDistance(row, currentPoint);
					if(distance < closest){
						closest = distance;
					}
				}


				if(y + 1 < boxWidth && x - 1 > 0){
					vector<point> row = grid[x - 1][y + 1];
					distance = findSmallestDistance(row, currentPoint);
					if(distance < closest){
						closest = distance;
					}
				}

				if(y + 1 < boxWidth && x < boxWidth){
					vector<point> row = grid[x][y + 1];
					distance = findSmallestDistance(row, currentPoint);
					if(distance < closest){
						closest = distance;
					}

				}

				if(y + 1 < boxWidth && x + 1< boxWidth){
					vector<point> row = grid[x + 1][y + 1];
					distance = findSmallestDistance(row, currentPoint);
					if(distance < closest){
						closest = distance;
					}
				}
				
				vector<point> row = grid[x][y];
				distance = findSmallestDistance(row, currentPoint);
				if(distance < closest){
					closest = distance;
				}

				z++;
			}
			y++; 
			z = 0;
		}
		x++;
		y = 0;
	}
		
	return closest;
}

//This function finds the shortest distance between a point and a set of points
//Mostly, this would look like a point being compared to an entire cell
double findSmallestDistance(vector<point> &cell, point &currentPoint){
	double lowest = 1;

	if(cell.size() == 0){
		return 1;
	}

	//This is the point being compared against
	point nextPoint;

	//This will compare the point passed in to the target cell	
	int tempPointPos = 0;
	while(tempPointPos < cell.size()){
		nextPoint = cell[tempPointPos];
		
		double distance = distanceFormula(currentPoint, nextPoint);
		
		if(distance < lowest && distance != 0){
			lowest = distance;
		}

		tempPointPos++;
	}	

	return lowest;
}

//This is the formula to get the distance between two different points
//made into its own function for easy reuse
double distanceFormula(point &one, point &two){
	//Formula is split into two parts for easy reading
	
	double xDifference = two.x - one.x;
	double yDifference = two.y - one.y;

	double insideRoot = pow(xDifference, 2) + pow(yDifference, 2);
	double root = sqrt(insideRoot);
	
	return root;
}
