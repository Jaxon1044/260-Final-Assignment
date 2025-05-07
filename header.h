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

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream> //For getting input/output file variables.
#include <string>
#include <cctype> //For manipulating characters. (  toupper() function for lowercase letters. ).
#include <sstream> //For istringstream variables.
#include <cctype> //for changing capitalization.

using namespace std;

//GLOBAL VARIABLES:

//FUNCTION PROTOTYPES:

void openIOFiles(ifstream& inFile, ofstream& outFile, string& inputFileName, string& outputFileName);

void selectConversionType(int& typeConversion);

void convertEnglish(ifstream& inFile, ofstream& outFile, string morseStrings[], int& charCount);

void convertMorse(ifstream& inFile, ofstream& outFile, string morseStrings[], int& charCount);

void closeIOFiles(ifstream& inFile, ofstream& outFile);





#endif
