/*	CADEN ALLEN
 *	CPSC 1070
 *	Project 4
 *	December 4, 2023
 *
 *
 * OUTSIDE SOURCES USED
 *
 * 	https://www.tutorialspoint.com/c_standard_library/stdio_h.htm
 * 		I used this page to understand how to read from and output to files
 *		as well as how to use the various functions of the stdio.h library
 */

#include "PhoneNum.h" // This includes stdlib.h and stdio.h
#include <string.h> // Used for checking arguments ( strcmp() )
#include <stdbool.h> // Used for bools for arguments 


//This function was made to split off part of the main to make it more readable
//This functionw will check for missing arguments (if there are any), and the main
//will prompt that those arguments are missing, otherwise, this function will set
//necessary variables to the arguments passed in
int main(int argc, char * argv []) {
		
	/*          !!!      POSSIBLE COMMANDS      !!!
	 *  
	 * <inputFile> takes in T9 presses to turn into words stored in <outputFile>
	 * 	must be before output  // see -L
	 * 
	 * <outputFile> outputs swapped words of inputFile   
	 * 
	 * < -L > flips <inputFile> to be translated into T9 presses
	 * 	this command can be anywhere
	 * 
	 * < -h > bring up short help menu
	 */ 

	

	//textonymFind("CALL");
	textonymFind("SHOP");
	/*textonymFind("HOT");
	//textonymFind("SWIM");
	//textonymFind("HOUSE");
	//textonymFind("SPACE");
	//textonymFind("OUTLET");
	textonymFind("FILE");
	textonymFind("TYPE");
	textonymFind("SOON");
	*///textonymFind("TEST");
	textonymFind("COLD");
	//This determine if the -L flag was used
	bool lFlag = false;
	
	//Determines if the -h flag was passed in
	bool helpFlag = false;

	//This will make sure an input and output
	//file were passed in
	//This will be 1 if 1 file was passed in
	//and 2 if 2 files were passed in
	//0 if none
	int fileValues = 0;
	
	//These will hold the names of the files
	char const * inputFileName;
	char const * outputFileName; 
	
	//this will be used as the counter for
	//the for loop
	int count;

	//This loop will find which arguments were passed
	//count initialized to 1 skips the calling of the
	//program
	for(count = 1; count < argc; count++){
		if(strcmp(argv[count], "-h") == 0){
			puts("PhoneNum T9 Conversion Tool. Usage:\n"
					"PhoneNum.exe <input file> <output file> [-L]\n"
					"-L Sets input type as letters instead of digits \n"
					"-h To get help");
					
					helpFlag = true;
		} 

		//This checks if certain arguments are present
		else if(strcmp(argv[count], "-L") == 0 ){
			lFlag = true;

		} else {
			//This assumes the user has passed in a file, otherwise
			//the program will fail later
			//As well as sets the file names to variables
			if(fileValues == 0){
				inputFileName = argv[count];	
			} else {
				outputFileName = argv[count]; 
			}
			fileValues++;
		}

	}

	//This will run the argument checker, either assigning
	//arguments to values or finding missing arguments
	//checkMissingArguments(argv, inputFileName, outputFileName, helpFlag, lFlag, fileValues);

	//This if will tell user if they are missing arguments
	if(fileValues < 2 && !helpFlag){
		puts("No output file given");
		if(fileValues < 1){
			puts("No input file given");
		}
		puts("Use -h to get help\n\n\n");
	} else if(!helpFlag) {
		
		//This else statement will run the main program


		//This will open the file using the name passed in, 
		//using "r" to set fopen to reading the file
		FILE * inputFile = fopen(inputFileName, "r");
		
		//This will create a file, if one does not exist,
		//to append the results of the program to it using "a"
		FILE * outputFile = fopen(outputFileName, "a");
		
		if(!lFlag){
			conversionT9(inputFile, outputFile, 'd');
		} else {
			conversionT9(inputFile, outputFile, 'l');
		}
		
		//Closes the files
		fclose(inputFile);
		fclose(outputFile);

	}	

}
