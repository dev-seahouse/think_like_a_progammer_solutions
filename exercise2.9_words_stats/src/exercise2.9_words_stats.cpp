//============================================================================
// Name        : 9_words_stats.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Assumptions:
// 1. input is valid (letters and punctuation only).
// Description : write a program that reads a line of text
// 	             1. counting the number of words
//               2. identify the length of the longest word
//               3. the greatest number of vowels in a word
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const char ENTER_KEY = 10;

	char inputChar = '0';
	int wordCount = 1; // initialize to 1 to simplify loop (otherwise could introduce do while/ extra if checks)
	int longestWordCount = 0;
	int currentWordCount = 0;

	cout << "Enter a line of text: " << endl; // prints !!!Hello World!!!


	while ((inputChar = cin.get()) != ENTER_KEY) {
		if (inputChar == ' ') {
			wordCount++;
			currentWordCount = 0;
			continue;
		}

		// only count characters
		if ((inputChar >= 'A' && inputChar <= 'Z')
				|| (inputChar >= 'a' && inputChar <= 'z')) {
			
		currentWordCount++;
		longestWordCount = max(currentWordCount, longestWordCount);
		}
	}

	// user enters empty string and hits enter
	if (longestWordCount == 0)
		wordCount = 0;


	cout << "============ Statistics =========== \n";
	cout << "Total Word Count: " << wordCount << endl;
	cout << "Longest word: " << longestWordCount << endl;
	return 0;
}
