/*
	Name: Jaxon Froderberg
	Class: CPSC 122, Spring 2023
	Date: January 31st, 2023
	Programming Assignment: PA1
	Description: This program reads in user-entered input/output files, 
				 which it then uses to Convert English text to morse code, and vice versa depending on user input.
	
	Notes/Sources: I referenced both cplusplus and Professor Sprint's video notes provided in the class modules on blackboard
					in order to better understand and implement the stringstream commands and other functions such as toupper/lower.
					
					I used the "/" character to better visualize spaces, and the program has been designed with this in mind.
					
					I also had additional assistance from Professor Sprint and Sarah Hagins in debugging and understanding concepts.
					No code was directly copied.
					
					I have attempted the 3-file bonus formatting.
*/

#include "doctest.h"
#include "header.h"


//FUNCTION DEFINITIONS:

/*
	Function: openIOFiles()
	Purpose: Prompts the user to choose their source (input) and destination (output) files for reading and printing
			 morse or english characters. Checks both to ensure proper files exsist and open correctly.
	Inputs: ifstream& inFile, ofstream& outFile, string& inputFileName, string& outputFileName
	Outputs: N/A (void) (opens input/output files.)
*/

void openIOFiles(ifstream& inFile, ofstream& outFile, string& inputFileName, string& outputFileName) {

	cout << "Please enter your source (input) file: ";
	cin >> inputFileName;
	
	cout << "Please enter your destination (output) file: ";
	cin >> outputFileName;
	
	//Open input file:
	inFile.open(inputFileName);
	
	if (inFile.fail()) {
		cout << "ERROR: Input file not found." << endl;
		exit(-1);
	}
	
	//Open output file:
	outFile.open(outputFileName);
	
	if (outFile.fail()) {
		cout << "ERROR: Output file not found." << endl;
		exit(-1);
	}

	return; //Both files have been found.
}


/*
	F.D.
*/

void selectConversionType(int& typeConversion) {

	string type = "";  //gets user input.
	bool typeChosen = false;   //checks to see if the user has put in a valid input.

	cout << "Please choose your preferred conversion: " << endl
		 << "(Type -m to convert your source file to morse-code.)" << endl
		 << "(Type -t to convert your source file to english text.)" << endl;
		 
	while (!typeChosen) {
		 
		cin >> type;
		
		if (type == "-m") {
			cout << "English-to-Morse selected." << endl;
			typeConversion = 1;
			return;
		}
		else if (type == "-t") {
			cout << "Morse-to-English selected." << endl;
			typeConversion = 2;
			return;
		}
		else {
			cout << "Invalid user input. Please try again." << endl;
		}
	}


	return;   //catch-all.
}


/*
	Function: convertEnglish()
	Purpose: Converts an input file written in English text into Morse code.
	Inputs: ifstream& inFile, ofstream& outFile, string morseStrings[], int& charCount
	Outputs: N/A (void) (Prints the translated morse code to the output file.)
*/

void convertEnglish(ifstream& inFile, ofstream& outFile, string morseStrings[], int& charCount) {

	string line = "";
	string word = "";
	char letter = ' ';
	char upperLetter = ' ';
	int ASCII = 0;
	
	istringstream iss;

	
	while (!inFile.eof()) {
	
	getline(inFile, line);
	
		for (int i = 0; i < line.length(); i++) {
			
			
			letter = line.at(i);
			upperLetter = toupper(letter);
			
			
			ASCII = static_cast<int>(upperLetter);
			
			//cout << morseStrings[ASCII];
			outFile << morseStrings[ASCII];
			charCount += 1;   //Adds a charater to the total talley for each letter and space.
			
			
			
			if (i != (line.length() - 1)) {
				//cout << " ";   //NOTE: this causes the double spacing, as it was reading in "" for ASCII space value (32),
							   //      and adding another space after it.
				outFile << " ";
			}
				
		}
	
		if (!inFile.eof()) {
			
			//cout << endl;
			outFile << endl;
			
			charCount += 1; //Adds a point for each newline.
		}
		
	}
	
	/*
	while (!inFile.eof()) {    
	
		getline(inFile, line); //Get each line.
		
		if (inFile.good()) {
		
			iss.clear(); 
			iss.str(line);
			
			while (iss.good()) { //Get each word.
			
				iss >> word;
				
				for (char letter : word) { //Get each letter.
					
					upperLetter = toupper(letter); //Changes lowercase letters into uppercase letters.
					
					ASCII = static_cast<int>(upperLetter); //Converts the characters to their ASCII values.
					
					cout << morseStrings[ASCII]; //Outputs the morse located at [ASCII] index. //FIXME: switch to output file print.
					outFile << morseStrings[ASCII];   //outputFile
					
					//CHARACTER COUNT:
					
					charCount += 1;   //Adds a charater to the total talley for each letter.
					
					
					//cout << " "; //TESSSST!  ADDS A SPACE AFTER EVERY CHARACTER.  <---- MAIN ERROR.  <------------------------
					//outFile << " ";  //outfile
					
					
					if (!iss.good()) {
						cout << "";  
					}
					else {
						cout << " ";   //Seperates morse characters for more readibility.    //TESTIIIINNNNNGGGGGG DO NOT DELETE!!!!!
					}
					
				}
			
				if (iss.good()) {
					cout << "/ "; //space.
					outFile << "/ ";   //outfile
					
					charCount += 1;   //Adds a charater to the total talley for each space.
				}
			}
		
		cout << endl;    //FIXME: Add character tally for newlines excluding eof.
		outFile << endl;   //outfile
		
		charCount += 1;
		}
	}
	*/

	charCount -= 1; //NOTE: removes one point from tally to remove last newline.


	return;
}


/*
	Function: convertMorse()
	Purpose: Converts an input file written in morse code into english text.
	Inputs: ifstream& inFile, ofstream& outFile, string morseStrings[], int& charCount
	Outputs: N/A (void) (Prints the translated enlish text to the output file.)
*/

void convertMorse(ifstream& inFile, ofstream& outFile, string morseStrings[], int& charCount) {

	string line = "";
	string word = "";
	char letter = ' ';
	char lowerLetter = ' ';
	
	//bool morseMatch = false;
	int ASCII = 0;
	int i = 0;
	int j = 0;
	
	string morse = "";
	
	istringstream iss;

/*
	while (!inFile.eof()) {    

		getline(inFile, line); //Get each line.

		for (i = 0; i < line.length(); i++) {
		
			if (line.at(i) == '.' || line.at(i) == '-') {
				
				morse += line.at(i);
			}
			
			if (line.at(i) == '/') {
			
				cout << "SPACE";
			}
			
			if (line.at(i) == ' ') {
			
				for (j = 0; j < 92; j++) {
					
					if (morse == morseStrings[j]) {
						
						letter = static_cast<char>(j); //Converts the ASCII index to it's character.
						
						cout << letter;
					}
					//else {
					//	cout << "ERROR";
					//}
					
				}
				
			morse = "";
			
			}
				
		}
		
	}
*/

	while (!inFile.eof()) {    
	
		getline(inFile, line); //Get each line.
		
		if (inFile.good()) {
		
			iss.clear(); 
			iss.str(line);
			
			while (iss.good()) { //Get each word.
			
				iss >> word;
				
				
				for (i = 0; i < 92; i++) {
					
					if (word == morseStrings[i]) {
					
						letter = static_cast<char>(i); //Converts the ASCII index to it's character.
						
						if (letter == '/') {
						
							//cout << " ";    //If the morse code contains a "/", it will be converted to a space in the output.
											//FIXME: switch to output file print.
							outFile << " "; //outfile
											
							charCount += 1;   //Adds a charater to the total talley for each space.
						}

						else {
		
							lowerLetter = tolower(letter);
								
							//cout << lowerLetter; //FIXME: switch to output file print.
							outFile << lowerLetter;  //outfile
								
							charCount += 1;   //Adds a charater to the total talley for each letter.
							
							
						}
					
					}
				
				}
				
			}
		
		//cout << endl;  //FIXME: Add character tally for newlines excluding eof.
		outFile << endl;  //outfile
		
		charCount += 1;
		
		}
	}

	
	charCount -= 1; //NOTE: removes one point from tally to remove last newline.

	return;
}

/*
	Function: closeIOFiles()
	Purpose: Closes all user input and output files at the end of the main function.
	Inputs: ifstream& inFile, ofstream& outFile
	outputs: N/A (void)
*/

void closeIOFiles(ifstream& inFile, ofstream& outFile) {

	inFile.close();
	outFile.close();

	return;
}

// Test function

bool compareFiles( string file1, string file2 ) {

	// Open the files being compared:
	ifstream inFile1;
	ifstream inFile2;
	inFile1.open( file1 );
	inFile2.open( file2 );

	char string1[256], string2[256];
	int j = 0;
	while(!inFile1.eof())
	{
		inFile1.getline(string1,256);
		inFile2.getline(string2,256);
		j++;
		if(strcmp(string1,string2) != 0)
		{
			cout << j << "-the strings are not equal" << "\n";
			cout << "   " << string1 << "\n";
			cout << "   " << string2 << "\n";
			return false;
		}
	}
	
	return true;
}











