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

// Include definition and header file for doctest:
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "header.h"

//MAIN FUNCTION:

//int main(void) {
int main( int argc, char *argv[] ) {

	// ========== Adjust Testing Configs ==========
	
	doctest::Context context;

	context.setOption("success", true);     // Report successful tests

	context.applyCommandLine(argc, argv);

	int testResults = context.run();              // run test cases unless with --no-run

	// ============================================

	ifstream inFile;
	ofstream outFile;
	
	string inputFileName = "";    //For user's choice of input file.
	string outputFileName = "";   //For user's choice of output file.
	string morseStrings[91] = {"", "", "", "", "", "", "", "", "", "",  // 0 - 9    REMEMBER: it starts at 0!
							   "", "", "", "", "", "", "", "", "", "",	// 10 - 19
							   "", "", "", "", "", "", "", "", "", "",	// 20 - 29
							   "", "", "/", "", "", "", "", "", "", "",	// 30 - 39
							   "", "", "", "", "", "", "", 				// 40 - 46
							   "", 			// 47: SPACE!
							   "-----", 		// 48: 0
							   ".----",			// 49: 1
							   "..---", 		// 50: 2
							   "...--", 		// 51: 3
							   "....-", 		// 52: 4
							   ".....", 		// 53: 5
							   "-....", 		// 54: 6
							   "--...", 		// 55: 7
							   "---..", 		// 56: 8
							   "----.", 		// 57: 9
							   "", "", "", "", "", "", "",				// 58 - 64
							   ".-",             // 65: A
							   "-...",			 // 66: B
							   "-.-.",			 // 67: C
							   "-..",			 // 68: D
							   ".",				 // 69: E
							   "..-.",			 // 70: F
							   "--.",			 // 71: G
							   "....",			 // 72: H
							   "..",			 // 73: I
							   ".---",			 // 74: J
							   "-.-",			 // 75: K
							   ".-..",			 // 76: L
							   "--",			 // 77: M
							   "-.",			 // 78: N
							   "---",			 // 79: O
							   ".--.",			 // 80: P
							   "--.-",			 // 81: Q
							   ".-.",			 // 82: R
							   "...",			 // 83: S
							   "-",				 // 84: T
							   "..-",			 // 85: U
							   "...-",			 // 86: V
							   ".--",			 // 87: W
							   "-..-",			 // 88: X
							   "-.--",			 // 89: Y
							   "--.."};			 // 90: Z
	
	int typeConversion = 0;  //Indicates what form of conversion the user has chosen.
	int charCount = 0;
	
	//bool test = false;


	cout << "Welcome to Encrypty! The best encrypter and decoder worldwide!" << endl;

	selectConversionType(typeConversion);

	openIOFiles(inFile, outFile, inputFileName, outputFileName);
	
	cout << "Files Verified. Please Wait. This will just take a second!" << endl
		 << "Converting " << inputFileName << "..." << endl;
	
	
	//Convert morse/english text:
	
	if (typeConversion == 1) {   //English-to-Morse
	
		convertEnglish(inFile, outFile, morseStrings, charCount);
		
		//cout << "Total characters converted successfully (including newlines and W.space): " << charCount << endl;
		outFile << "Total characters converted successfully (including newlines and W.space): " << charCount << endl;
		
		closeIOFiles(inFile, outFile);
	}
	
	if (typeConversion == 2) {	 //Morse-to-English
	
		convertMorse(inFile, outFile, morseStrings, charCount);
		
		//cout << "Total characters converted successfully (including newlines and W.space): " << charCount << endl;
		outFile << "Total characters converted successfully (including newlines and W.space): " << charCount << endl;
		
		closeIOFiles(inFile, outFile);
	}

	
	cout << "Done! Your source file has been converted! Thank you for stopping by!" << endl; //Program is finished.

	//return context.run();
	return testResults;
}

TEST_CASE("First_Test") {

	cout << "Running tests...";
	
	string morseStrings[91] = {"", "", "", "", "", "", "", "", "", "",  // 0 - 9    REMEMBER: it starts at 0!
		"", "", "", "", "", "", "", "", "", "",	// 10 - 19
		"", "", "", "", "", "", "", "", "", "",	// 20 - 29
		"", "", "/", "", "", "", "", "", "", "",	// 30 - 39
		"", "", "", "", "", "", "", 				// 40 - 46
		"", 			// 47: SPACE!
		"-----", 		// 48: 0
		".----",			// 49: 1
		"..---", 		// 50: 2
		"...--", 		// 51: 3
		"....-", 		// 52: 4
		".....", 		// 53: 5
		"-....", 		// 54: 6
		"--...", 		// 55: 7
		"---..", 		// 56: 8
		"----.", 		// 57: 9
		"", "", "", "", "", "", "",				// 58 - 64
		".-",             // 65: A
		"-...",			 // 66: B
		"-.-.",			 // 67: C
		"-..",			 // 68: D
		".",				 // 69: E
		"..-.",			 // 70: F
		"--.",			 // 71: G
		"....",			 // 72: H
		"..",			 // 73: I
		".---",			 // 74: J
		"-.-",			 // 75: K
		".-..",			 // 76: L
		"--",			 // 77: M
		"-.",			 // 78: N
		"---",			 // 79: O
		".--.",			 // 80: P
		"--.-",			 // 81: Q
		".-.",			 // 82: R
		"...",			 // 83: S
		"-",				 // 84: T
		"..-",			 // 85: U
		"...-",			 // 86: V
		".--",			 // 87: W
		"-..-",			 // 88: X
		"-.--",			 // 89: Y
		"--.."};			 // 90: Z

	int typeConversion = 0;  //Indicates what form of conversion the user has chosen.
	int charCount = 0;

	ifstream inFile;
	ofstream outFile;

	SUBCASE( "First basic test") {
		CHECK( "bob" == "bob" );
	}
	
	
	// Testing calling functions from another file.
	/*
	SUBCASE( "Check files opened" ) {
		helloWhat();

		string inputName = "/testFiles/test1.txt";
		string outputName = "output.txt";

		openIOFiles( inFile, outFile, inputName, outputName );
		MESSAGE("Hello testing subcase! Here's the input file: ", inFile );
	}
	*/

	// Testing comparing files:
	SUBCASE( "Comparison test 1" ) {
		CHECK( compareFiles( "english.txt", "english.txt" ) );
	}

	SUBCASE( "Comparison test 2") {
		REQUIRE_FALSE( compareFiles( "english.txt", "morse.txt" ) );
	}

	SUBCASE( "Convert and compare" ) {

		// Open the files
		inFile.open("english.txt");
		outFile.open("output.txt");

		// Convert the text to morse.
		convertEnglish( inFile, outFile, morseStrings, charCount );

		closeIOFiles( inFile, outFile );

		// Once the file is converted, compare the outputted file to a template solution:
		CHECK( compareFiles( "output.txt", "morse.txt" ) );
	}
}


