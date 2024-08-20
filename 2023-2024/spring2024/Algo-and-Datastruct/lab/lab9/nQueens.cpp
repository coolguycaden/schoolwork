/*
 * Name: Caden Allen
 * Date Submitted: 4/15/2023
 * Lab Section: 001
 * Assignment Name: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

//This struct will be used as a simple way to keep track
//of a Queen's position on the board
struct Queen {
	int x;
	int y;
	Queen (int row, int col){
		x = row;
		y = col;
	}
};

//This will compare the sent-in queen, newQueen, to the rest of the queens already on board
//This will check if that new Queen's position is attacked along a diagonal of another queen
bool attackedDiagonally(vector<Queen> * placedQueens, Queen newQueen){
	for(int x = placedQueens->size() - 2; x >= 0; x--){
		Queen temp = (*placedQueens)[x];
		
		//Simple solution - I really loved this thought process
		//This is just the slope formula for 2 points
		double topFormula = (temp.y - newQueen.y);
		double bottomFormula (temp.x - newQueen.x);
		double slope = topFormula / bottomFormula; 

		//If the slope is 1 or -1, that means the slope is
		//y = x, which is diagonal to either Queen, meaning they are 
		//attacked
		if(slope == 1.0 || slope == -1.0){
			return true;
		}
	}

	return false;
}

//Simple function, checks sent-in queen, newQueen, if its placement along the y-axis
//is similar to queens already on the board
bool attackedVertically(vector<Queen> * placedQueens, Queen newQueen){
	for(int x = placedQueens->size() - 2; x >= 0; x--){
		Queen temp = (*placedQueens)[x];
		if(temp.y == newQueen.y){
			return true;
		}
	}

	return false;
}

//This is the main recursive function, and does recursion for every part of the grid except
//for the first queen
int findSolutions(vector<Queen> * placedQueens, int row, int column, int n){
	int solutionsFound = 0;
		

	//If row is greater than N, that implies a solution was found,
	//because row can only be greater than N if solutions were found before
	//(if a solution is NOT found, than column is incremented, NOT row)
	if(row > n){
		//solution was found 

		return 1;
	} else if(column > n){
		//Read above comment
	
		return 0;
	}

	//Pushes a temporary queen into the vector, and tests if
	//the queen is a valid insertion
	Queen newQueen(row, column); 
	(*placedQueens).push_back(newQueen);
	
	//This if checks if the inserted queen (see above) is a valid insertion
	//if not, then the column is incremented, so that the current row can be tried until
	//there are no more columns left
	if(attackedVertically(placedQueens, newQueen) || attackedDiagonally(placedQueens, newQueen)){
		
		//Queen is an invalid insertion, remove it
		(*placedQueens).pop_back();

		//Try again with a queen further along the grid
		solutionsFound += findSolutions(placedQueens, row, column + 1, n);
	} else {
		
		//This means the queen was a valid insertion, so it is kept and
		//the recursion continues
		solutionsFound += findSolutions(placedQueens, row + 1, 1, n);
		
		//This means that there is no potential queen spots to check in the previous
		//recursions
		//
		//This will remove the last queen with a valid spot, and increment the column
		//so the more spots may be tried if there is space left on the row
		int tempCol = (*placedQueens)[placedQueens->size() - 1].y;
		(*placedQueens).pop_back();

		solutionsFound += findSolutions(placedQueens, row, tempCol + 1, n);

		//This means all combinations have been checked (in respect to the starting queen's positions)
		return solutionsFound;
	}
	
	//base return 
	return solutionsFound;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
 	int solutionsFound = 0;
	static int column = 1;
	
	//"Grid" of queens
	vector<Queen> placedQueens;
	
	Queen placeholderQueen(1, column);
	placedQueens.push_back(placeholderQueen);
	
	if(column > n){
		return solutionsFound;
	} 

	solutionsFound += findSolutions(&placedQueens, 2, 1, n);
	column++;

	solutionsFound += nQueens(n);	

	//reset static member, this assumes all available positions
	//were checked
	column = 1;

	return solutionsFound; 
}

/*int main()
{
	cout << "1: " << nQueens(1) << endl;
	cout << "2: " << nQueens(2) << endl;
	cout << "3: " << nQueens(3) << endl;
	cout << "4: " << nQueens(4) << endl;
	cout << "5: " << nQueens(5) << endl;
	cout << "6: " << nQueens(6) << endl;
	cout << "7: " << nQueens(7) << endl;
	cout << "8: " << nQueens(8) << endl;
	cout << "9: " << nQueens(9) << endl;
	cout << "10: " << nQueens(10) << endl;
	cout << "11: " << nQueens(11) << endl;
	cout << "12: " << nQueens(12) << endl;
	return 0;
}*/
