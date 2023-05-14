//============================================================================
// Name        : decodeMessage.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

/**
 * when we directly assign type char a to int b, b will store
 * ascII code, but what we want is the actual number digit
 * that the ascII is representing
 */

int convertCharToInteger(char c) {
	int out = c - '0';
	return out;
}

int main() {
	enum modeType {
		UPPERCASE, LOWERCASE, PUNCUATION
	};

	modeType mode = UPPERCASE;
	char digitChar = INFINITY;
	char outputChar;
	cout << "enter the encoded message separated by comma : \n";
	int number;
	while (digitChar != 10) {
		number = convertCharToInteger(cin.get());
		digitChar = cin.get();
		while (digitChar != ',' && digitChar != 10) {
			number = number * 10 + convertCharToInteger(digitChar);
			digitChar = cin.get();
		}

		switch (mode) {
		case UPPERCASE:
			number = number % 27;
			outputChar = number + 'A' - 1;
			if (number == 0) {
				mode = LOWERCASE;
				continue;
			}
			break;
		case LOWERCASE:
			number = number % 27;
			outputChar = number + 'a' - 1;
			if (number == 0) {
				mode = PUNCUATION;
				continue;
			}
			break;
		case PUNCUATION:
			number = number % 9;
			switch (number) {
			case 1:
				outputChar = '!';
			break;
			case 2:
				outputChar = '?';
				break;
			case 3:
				outputChar = ',';
				break;
			case 4:
				outputChar = '.';
				break;
			case 5:
				outputChar = ' ';
				break;
			case 6:
				outputChar = ';';
				break;
			case 7:
				outputChar = '"';
				break;
			case 8:
				outputChar = '\'';
				break;
			}
			if (number == 0) {
				mode = UPPERCASE;
				continue;
			}
			break;
		}

		cout << outputChar;
	}
	return 0;
}

//int main() {
//	cout << "Enter a number with as many digits as you like: ";
//	char digitChar = cin.get();
//	int number = digitChar - '0';
//	digitChar = cin.get();
//	while (digitChar != 10) {
//		number = number * 10 + (digitChar - '0');
//		digitChar = cin.get();
//	}
//	cout << "Number entered: " << number << "\n";
//}

void program1() {
	cout << "Enter a three-digit or four-digit number: ";
	char digitChar = cin.get();
	int number = (digitChar - '0') * 100;
	digitChar = cin.get();

	number += (digitChar - '0') * 10;
	digitChar + cin.get();
	number += digitChar - '0';
	digitChar = cin.get();

	if (digitChar == 10) {
		cout << "Number entered " << number << "\n";
	} else {
		number += (digitChar - '0');
		cout << "Number entered" << number << "\n";
	}
}






