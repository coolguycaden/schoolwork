/*
  CADEN ALLEN
  CPSC 1070
  9/22/2022

  This program was made to emulate Bullseye! from The Price is Right!
  User is requried to choose one of 3 objects, and attempt to guess how many
  how of those objects equals a price between 10 and 13 dollars
  The prices and items are random within a certain limit

  For my use of pointers, I used an answer from GraphicsMuncher on StackOverflow

  GraphicsMuncher's comment was the top answer.
  https://stackoverflow.com/questions/13295011/altering-an-array-from-a-function-in-c
  
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <cmath>
#include <cstdio>

using namespace std;

//FUNCTION PROTOTYPES
//these are here only because I did not want
//to rearrange my functions
//look for specific functions for comments
int guessQuantity (string);
bool isValidBid(string, double [5]);
bool isValidGuess(string);
void printResult(bool, string, double, double);
void holdBids(double, double&, int);
void indexOfItems(int, int&, int);

//Simply changes original price of an item (index)
//to zero, which will indictate it cannot be chosen
void changeToZero(double (**priceList)[5], int index){
  (**priceList)[index] = 0.0;
}

//Prompts user to select an item, and make a bid on it
//guessQuantity() will take user input and return as int
//that int (multiple) will be used to find the result
//of the picked item's price and the multiple
//Then returns true or false if the result is between 10 and 13
bool runBid(string items[5], double itemChosenResults[5]){
  string input;
  cout << "Choose an item (1-5): ";
  cin >> input;
 
  //This will make sure the user inputs a single character
  //and that character is 1-5
  bool valid = isValidBid(input, itemChosenResults);
  
  //While the above is NOT true, this will run
  while(!valid){
    cout<<"Invalid input, please try again"<<endl;
    cout<<"\nChoose an item (1-5): "; 
    cin>> input;
    valid = isValidBid(input, itemChosenResults);
  }
  
  //Because 1-5 are the only valid numbers,
  //This takes in 1-5, and the substracts the number
  //To get the equivalent index
  //For example, input of 2, will be itemIndex of 1, which is items[1]
  int itemIndex = stoi(input) - 1;
  string selectedItem = items[itemIndex];
  
  //Will store user input of a value (multiple) which will be
  //used to multiply price by
  int multiple = guessQuantity(selectedItem);

  //This will be the result of the user's guess
  double bidResult = multiple * itemChosenResults[itemIndex];

  //Placeholder values, used to signal
  //below functions to store input values besides
  //this junk value params
  double temp = -1.0;
  int temp2 = -2;

  indexOfItems(itemIndex, temp2, 0);
  holdBids(bidResult, temp, 0);
 
  //Checks if user bid is in range of 10-13
  //Which is a win
  if(bidResult > 10 && bidResult < 13){
    printResult(true, selectedItem, itemChosenResults[itemIndex], bidResult);

    return true;
  } else {
    printResult(false, selectedItem, itemChosenResults[itemIndex], bidResult);


    return false;
  }
}

//This will hold the index of items that were not guessed correctly
//So that their prices can be changed to 0, and the options
//unable to be chosen for bidding
//incorrectIndex and returnIndex are passed junk values
//in some calls so that the value incorrectIndex can be stored or
//extracted
void indexOfItems(int incorrectIndex, int& returnIndex, int desiredIndex){
  //holds the indexes of wrong guesses
  static int incorrectIndexes [3];
  static int count = 0;

  //If incorrectIndex is not a junk value
  //(-1 is junk value, passed in for storage of values)
  //Then incorrectIndex added to the function storage
  if(incorrectIndex != -1 && incorrectIndex != -5){
    incorrectIndexes[count] = incorrectIndex;
    count++;
  }

  //incorrectIndex of -5 means to reset
  if(incorrectIndex == -5){
    count = 0;
  }
  
  //If returnIndex is not a junk value (-2)
  //then this will edit returnIndex to the index of wrong item
  if(returnIndex != -2){
    returnIndex = incorrectIndexes[desiredIndex];
  }
}
/*
void swap(double *firstDouble, double *secondDouble){
  int temp = *firstDouble;
  *firstDouble = *secondDouble;
  *secondDouble = temp;
}
void sortBids(double (*toSort)[3]){
  if((*toSort).length() == 2){
    if((*toSort)[0] > (*toSort)[1]){
      swap((*toSort)[0], (*toSort)[1];
    }
  }
  if((*toSort).length() == 3){
    
  }
}
*/

//Does the exact same as indexOfItems() but holds bid results instead
void holdBids(double bidResult, double& changedPrice, int index){
  static double allBids [3];
  static int count = 0;
  if(bidResult != 0.0 && bidResult != -5){
    allBids[count] = bidResult;
    count++;
  }

  if(bidResult == -5){
    count = 0;
  }
  
  
  if(changedPrice != -1.0){
    changedPrice = allBids[index]; 
  }
}

//Simple function for printing if user guess was correct or not
////Prints numbers in the middle of a line in a box
//This function will only be used to print numbers
//in the middle of the top and bottom lines
//of a box
void printResult(bool isCorrect, string itemName, double price, double bidResult){
  cout<<itemName<<" has a unit cost of $";
  printf("%.2f", price);
  cout<<", so the total price is $";
  printf("%.2f",bidResult);
  if(isCorrect){
    cout<<". Which is between 10 and 13!"<<endl;
    cout<<"Congrats!!!"<<endl;
  } else {
    cout<<". Which unfortunately is not between $10 and $13"<<endl;
  } 
}

//Gets a random price depending on min and max
//This is inclusive to min and max
//Generates random numbers for the dollar and cents
double getPrice (int min, int max){
  int dollar  = (rand() % (max - min)) + min;
  double cents = round(((rand() % 1000) / 1000.0) * 100.0) / 100.0;
  double result = dollar + cents;
  return result;
}

//Finds a random item in itemList (which is all the items)
//Because each category has 4 items, I combined them into one list
//Count keeps track of the "range" in which the function selects items
//For example, a count of 0 means indexes 0-3 will be selected
//That is the meat category, and each increase of count
//Will go to the next category
string getItem(string itemList[20]){
  static int count = 0;
  if(count == 5){
    count = 0;
  }
  int randomItem = (rand() % 4) + (count * 4);
  count++;
  return itemList[randomItem];
}

int guessQuantity (string itemName){
  //Prompts user to type in an amount
  cout<<itemName<< " is selected. How many?: ";

  //Holds user input
  string input;
  cin >> input;
  
  //Checks if input is valid
  //This form of isValid will NOT check string length of input
  //will ONLY check if input is negative or if input is a number
  bool valid = isValidGuess(input);

  while(!valid){
    cout <<"Invalid input, please try again"<<endl;
    cout<<"\n"<<itemName<<" is selected. How many?: ";
    cin >> input;
    valid = isValidGuess(input);
  }

  cout<<endl;
  return stoi(input);
}

//Small function for determing length of the "board"
//The board will hold the names of the 5 items
//This function will determine what inside length of
//the board boxes should be 
int getLargestItemLength(string list [5]){
  int max = list[0].length();
  string f = list[0];
  for(int x = 1; x < 5; x++){
    if(max < static_cast<int>(list[x].length())){
      max = list[x].length();
      f = list[x];
    }
  }
  return max;
}


//This function will print out items into the boxes with correcto format
//Correct format means if the item is the longest word (or equal length), it will fix the box completely
//If the item length is less than the longest, the function will print spaces AFTER the word to fill the box
void printItem(string item, double price){

  //This loop is as explained above, in function comment
  //This makes sure item has not been bid on
  //Price of 0.0 = a bid
  if(price == 0.0){
    for(int x = 0; x < 7; x++){
      cout <<" ";
    }
  } else {
    if(item.length() - 7 == 0){
      cout << item;
    } else {
      cout << item;
      for(int x = 0; x < (7 - static_cast<int>(item.length())); x++){
	cout<<" ";
      }
    }
  }
}

//This function will create a length of the board, (top side or bottom side);
//The length of the board will be calculated by the parameter length, which is the
//length of the longest word in the items chosen, plus 2 to account for box sides ( || ) 
void createBoardLength(){
  //Add 6 to timesToPrint to account for || which are box sides, 6 in 
  //total
  int timesToPrint = (7 * 5) + 6;

  for(int x = 0; x < timesToPrint; x++){
    //This will print out - in a row until the length is reached
    //Remember that length is the width of the box, plus two to account for the ||
    
    cout <<"-";
  }
  cout<<endl;
}

//Prints numbers in the middle of a line in a box
//This function will only be used to print numbers
//in the middle of the top and bottom lines
//of a box
void printNumber(){
  //Keeps track of current number to be printed
  static int count = 1;

  //length of the inside of a box
  int length = 7;

  //This is the number of spaces before and after the number
  length /= 2;

  //Prints spaces before the number
  for(int x = 0; x < length; x++){
    cout<<" ";
  }

  cout<<count;

  //Prints spaces after the number
  for(int x = 0; x<length; x++){
    cout<<" ";
  }
  
  count++;

  //Resets count after 5, back to 1
  //So each box has the same number in it twice
  if(count == 6){
    count = 1;
  }
}

//Prints numbers in the middle of a line in a box
//this function used printNumber() which will
//format the numbers with the correct
//amount of spacing on the top and bottom
//lines
void createNumberInBox(){
  for(int x = 0; x < 5; x++){
    cout <<"|";
    printNumber();
  }
  cout<<"|"<<endl;
}

//Prints a | to mark box side
//then calls printItem()
//printItem() will print item name, and pad spaces
//to the right of the item name if its length
//is less than the box
void createItemInBox(string items[5], double prices [5]){
  for(int x = 0; x < 5; x++){
    cout<<"|";
    printItem(items[x], prices[x]);
  }
  cout<<"|"<<endl;
}

//Gets previous guesses from holdBids()
//and then finds which numbers that bid is between
//index is used to retrieve bids from holdBids

void addXToRange(int index){
  //Will hold bidResult[index]
  double bidResult = 0.0;

  //Calculates number of times to move cursor right
  int movesToRight = 0;

  //Finds the 2 numbers bidResult is between
  //Then calculates spaces based off of that
  //subtract 1 from spacesToPrint if it is less than 10
  holdBids(0.0, bidResult, index);
  
  for(int x = 0; x < 20; x++){
    if(bidResult >= x && bidResult <= (x + 1)){    
      movesToRight = (3 * x); 
    }

  }  

  //If the bid is greater than $20
  if(movesToRight == 0){
    movesToRight = (3 * 20);
  }
  
  //Prints spaces
  for(int x = 0; x < movesToRight; x++){
    //so spaces do not replace the || markers  
     cout<<"\x1b[C";
    

  }

  //Prints the mark
  cout<<"X";
}
//This function will print all the numbers for 1 - 20, including the || which
//Will indicate the goal range of 10-13
void createNumberRange(double itemChosenResults [5]){
  //Checks for how many xs to print
  int howManyXs = 0;

  //Will check how many Xs need to be printed
  for(int x = 0; x < 5; x++){
    if(itemChosenResults[x] == 0.0){
      howManyXs++;
    }
  }
  
  //Prints Xs
  for(int x = 0; x < howManyXs; x++){
    cout<<"\r";
    addXToRange(x);
  }
  cout<<endl;

  for(int x = 1; x < 21; x++){
    if(x <= 9){
      cout << "  "<<x;
    } else {
      if(x == 10 || x == 13){
        //Special characters used here,
        //look for displayBoard() function comment for deciphering
        //This will move cursor up 1 and right 1, print a |
        // and then left 1, down 1 to reset the cursor to original position
        //This will be done for 10 and 13, to make the || goal posts
        cout << "\x1b[A\x1b[C|"<<"\x1b[D\x1b[B"<<x;

      } else {
	cout<<" "<<x;
      }
      
    }//end of else
    
  }//End of for lop
  
  cout<<endl;  
}

//This function will display the current 5 items for the game and the previous guesses made by user
//This function is divided into multiple other functions, make sure to read their comments too 
//The functions displayBoard() calls  will use special characters for easy text placement
// \x1b[A will move cursor UP 1
// \x1b[B will move cursor DOWN 1
// \x1b[C will move cursor RIGHT 1
// \x1b[D will move cursor LEFT 1
//I thought it easier to divide the board into three distinct lines, each with their own information
//The first line holds the number of the item (1,2,3..), Second line holds the item name
//Third line does the same as the first line
//Finally, there is the number range before the board
//so I split the board into 4 functions
void displayBoard(string items[5], double itemChosenResults[5]){

  //This will be how many - will make the board sides
  //Add 2 to this number because we need space for || which
  //are the box sides
  cout<<endl;
  //This will create the board's top side
  createBoardLength();

  //I thought it easier to divide the board into three distinct lines,
  //each with their own information
  //The first line holds the number of the item (1,2,3..)
  //Second line holds the item name
  //Third line does the same as the first line
  //So I split the board into
  //This will create a number corresponding with the item index (index + 1)
  //and put that at the top of the box
  createNumberInBox();

  //This will print out the item names in the middle of the boxes
  //As well as accounting for spacing
  createItemInBox(items, itemChosenResults);
  
  //This will do the same thing as the first call of this function
  //But will put numbers at the bottom of the box
  createNumberInBox();

  //This will create the baord's bottom side
  createBoardLength();
  
  cout<<endl;

  //This will create the number line of 1-20 and the goal range of 10-13
  createNumberRange(itemChosenResults);

  cout<<endl;
}

//This will check if input is a valid option
//for menu 
bool isValidMenu(string input){
  if(input.length() != 1){
    return false;
  }
  switch(input.at(0)){
  case '1': case '2': case '3': case '4':
    return true;
  default:
    return false;
  }
}

//This will run for the isValid() in guessQuantity()
bool isValidGuess(string input){
  
  //This will check the length of input to make sure
  //every index is a integer
  for(int x = 0; x < static_cast<int>(input.length()); x++){
    if(!(isdigit(input[x]))){
      return false;
    }
    
    //isdigit() counts '-' in middle of numbers as a digit
    //For the purpose of this program, such a thing
    //in a number makes it invalid
    if(input.at(x) == '-'){
      return false;
    }
  }

  if(stoi(input) == 0){
    return false;
  }
  return true;  
}

//Checks if input is valid for a bid
//Checks if an item has a price of 0, meaning
//it has already been bid on
bool isValidBid(string input, double prices [5]){
  if(input.length() != 1){
    return false;
  }
  
  switch(input.at(0)){
  case '1': case '2': case '3': case '4': case '5':
    //Curly braces here to prevent jump to case label
    {
      //This will get a numeric value of a char using their ASCII values
      int intValueOfInput = static_cast<int>(input.at(0))-(static_cast<int>('0')) - 1;
      if(prices[intValueOfInput] == 0.0){

	return false;
      }
      return true;
    }
  default:
    return false;
  }
  return false;
}

//This function will make the start menu, and show the user options they can choose from
//This function will be called each time the user 
char runMenu(){
  cout << "---- CPSC 1070 Bullseye Menu ----"<<endl<<endl<<endl;
  cout << "[1] Bid on an item"<<endl<<"[2] Display current board "<<endl;
  cout << "[3] Restart the game "<<endl<<"[4] Quit "<<endl;

  //Input will be everything the user puts when prompted to select a choice
  string input;

  //Will be used to determine if 'input' is a valid entry
  bool valid = false;
  
  cout<<"\nYour choice?: ";
  do{
    //Takes in user input into variable input
    cin >> input;

    //checks if input is valid, specifically if input has a length of one
    //and is in range of 1-4
    valid = (isValidMenu(input));
    if(valid){
      //This will get the value of input, and use that for getting the asked for menu options 
      return input.at(0);
     
    } else {
      cout << "Invalid input, please try again" << endl;
      cout<<"Your choice?: ";
    }
  
 
  } while (!valid);

  return input.at(0);
}

//Simple function to check if the attempts is 0
//This only works in runGame() because attempts is a
//static local variabel
bool outOfAttempts(int attempts){
  if(attempts == 0){
    return true;
  }
  return false;
}

//Sets items
void setItems(string (**items)[5], string itemList[20]){
  for(int x = 0; x < 5; x++){
    (**items)[x] = getItem(itemList);
  }
}

//Sets prices
void setPrices(double (**prices)[5]){
  //This manually assigns prices to each item
  //NOTE!!! items and prices line up on x values
  //For example, items[1] will have the price of prices[1]
  (**prices)[0] = getPrice(3, 10);
  (**prices)[1] = getPrice(1, 3);
  (**prices)[2] = getPrice(1, 2);
  (**prices)[3] = getPrice(3, 5);
  (**prices)[4] = getPrice(1, 4);
}


//Displays attempts
void displayAttempts(int attempts){
  cout<<attempts<<" attempt(s) left"<<"\n\n";
}

void reset(bool restart){
  static bool reset = false;
  if(restart){
    reset = true;
  }

  if(reset){
    //Garbage values so this functions
    //can reset their static variables
    int temp1 = -2;
    double temp2 = -1;
    
    indexOfItems(-5, temp1, 0);
    holdBids(-5, temp2, 0);
  }
}

//This function will run the game, doing various functions depending on user input (runMenu()) void runGame()
void runGame(){
  //Will track attempts
  static int attempts = 3;

  //This will hold if the user has won or not
  bool hasWon = false;

  //User is playing game
  bool playing = true;
  
  //This will create new items with new prices each time this function is run
  //(Either on program start, or replay)
  string items[5];
  double prices[5];
  
  //Will hold the user's guesses on prices
  // double priceGuesses;
  
  //Holds all items regardless of category
  //NOTE!!! Each 4 strings in the list, or "line" holds a category
  //This is important for distinguishing categories in the list,
  //especially for getting a random item
  string itemList [20] = {"Turkey", "Ham", "Chicken", "Beef",
			  "Apple","Pear", "Grape", "Orange",
			  "Water", "Soda", "Juice", "Tea",
			  "Frame", "Candle", "Pillow", "Vase",
			  "Popcorn", "Chips", "Cookies", "Granola"};

  //This will allow to be editted indiviudally
  //in order to make them unpickable for a bid
  //and set them
  string (*itemsPointer) [5] = &items;
  double (*pricesPointer) [5] = &prices;

  setItems(&itemsPointer, itemList);
  setPrices(&pricesPointer);
  //This stores the user's answer to the prompy
  char ans;

  displayBoard(items, prices);
  displayAttempts(attempts);

  ans = runMenu();
  //The meat of the game
  //This many functions, see the functions themselves
  //for expanded comments
  while(playing){

    //Checks if the user has won the game
    if(hasWon && ans == '1'){
      cout<<"You've already won, reset to play more!"<<endl;
      displayAttempts(attempts);
      ans = runMenu();
    }

    //If user has not run, or used all their attempts, they can guess
    if(ans == '1' && !hasWon){
      //checks if user is out of attempts
      if(outOfAttempts(attempts)){
	cout << "You've run out of attempts, reset to play more!"<<endl;
	displayAttempts(attempts);
	ans = runMenu();
      } else {
	//Holds the result of runBid()
	bool isCorrect = runBid(items, prices);
	
	//This whole else statement will first store the index of the
	//wrong item, then will change the price of that item to 0
	//so the item can no longer be selected
	
	//holdBids needs an index to access the desired bid
	//This variable will make sure bids are accessed as needed
	int currentBidIndex = (2 - attempts) + 1;
	int desiredIndex = -1;
	
	indexOfItems(-1, desiredIndex, currentBidIndex);
	
	//holdBids(0.0, placeholderPrice, currentBidIndex);
	changeToZero(&pricesPointer, desiredIndex);

	if(isCorrect){
	  hasWon = true;
	}
	
	attempts--;
	displayAttempts(attempts);
	ans = runMenu();
      }
    }

    //Displays board along with attempts
    if(ans == '2'){
      
      displayBoard(items, prices);
      displayAttempts(attempts);
      ans = runMenu();
    }

    //Resets the game
    if(ans == '3'){
      cout<<"Resetting..."<<endl;
      //cout<<"ANS: "<<ans<<"\n\n\n";
      attempts = 3;
      displayAttempts(attempts);
      hasWon = false;
      reset(true);
      setItems(&itemsPointer, itemList);
      setPrices(&pricesPointer);
      ans = runMenu();
    }
    
    if(ans == '4'){
      playing = false;
    }

  }
 
  cout<<"Thank you for playing!";
}

int main(){

  cout<<"Welcome to the CPSC 1070 Bullseye!" <<endl<<endl;
  cout<<"The goal is to get between $10 and $13 by picking an item and a quantity." <<endl;
  cout<<"There are five items, but you only get three tries."<<endl;

  unsigned seed = time(0);
  srand(seed);
    
  runGame();
}
