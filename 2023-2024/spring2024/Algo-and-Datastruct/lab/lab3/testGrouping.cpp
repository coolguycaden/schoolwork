/*
 * Name: Caden Allen
 * Date Submitted: 2/12/2024
 * Lab Section: 001
 * Assignment Name: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below


bool checkForGroups(int row, int col){
	//for(int x = 0; x < 
	
	
	//Make a temp vector 
	vector <int> temp;
	temp.push_back(row);
	
	//find all group within that vector
	//push back whole vector to inner vector
	//
	//
	//Two vectors
	//inner vector holds a vector
	return false;
}


void Grouping::findGroup(int r, int c){
	//base case
	//Either in a group already 
	if(grid[r][c] == 0){
		cout << "no group at (" << r << ", "  << c << ") " << endl;
	} else {
		vector <int> temp;
		//how to check a cell based on range limitations
		// row > 0 && row < 10   col > 0 && col < 10
		// 	check in all directions
		//
		if((r > 0 && r < 10) && (c > 0 && c < 10)){
			findGroup(r - 1, c);
			findGroup(r, c - 1);
			findGroup(r + 1, c);
			findGroup(r, c + 1);
		}
		
	}

}

Grouping::Grouping(string filename){
	fstream file(filename);
	string line;
	int row = 0;
	while(getline(file, line)){
		for(unsigned x = 0; x < line.length(); x++){
			if(line[x] == 'X'){
				grid[row][x] = 1;
			} else {
				grid[row][x] = 0;
			}
		}
		row++;
	}

	for(int x = 0; x < 10; x++){
		for(int y = 0; y < 10; y++){
			if(grid[x][y] == 1){
				cout << "(" << x << ", " << y << ") found" << endl;
				findGroup(x, y);
			} 
		}
	}

}

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
	//changed int to unsigned
    for(unsigned g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(unsigned s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}
