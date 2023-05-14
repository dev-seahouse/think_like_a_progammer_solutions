//============================================================================
// Name        : 7_dec_hex_bin.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int getBaseFromOption(int);
int getNumDigitsInBaseN(int, int);

int main() {
	int inputBase = 10;
	int outputBase = 10;
	char digitChar = '0';
	int digitNum = 0;
	int maxDigitSize = 64 / inputBase;
	int digitCount = 0;
	int dec = 0;

	// Collect input
	cout << "Select base to convert from: \n ";
	cout << "1. Decimal \n 2. Hex \n 3. Bin \n";
	inputBase = getBaseFromOption(cin.get() - '0');
	cin.ignore(); // user press enter

	cout << "Select base to convert to: \n ";
	cout << "1. Decimal \n 2. Hex \n 3. Bin \n";
	outputBase = getBaseFromOption(cin.get() - '0');
	cin.ignore(); // user press enter

	cout << "Enter the number in base " << inputBase << ": \n";


	// convert base n to base 10
	while (((digitChar = cin.get()) != 10) && digitCount <= maxDigitSize) {

		if (digitChar > 'Z' || digitChar < '0'
				|| (digitChar > '9' && digitChar < 'A')) {
			throw std::invalid_argument("Invalid input");
		}

		digitNum =
				digitChar < 'A' ? digitChar - '0' : digitChar - ('A' - 10);

		dec = dec * inputBase + digitNum;
	}
	


	// convert base 10 to base n

	cout << "Result: ";

	int numDigits = getNumDigitsInBaseN(dec, outputBase);

	while (numDigits) {
		int numPlace = pow(outputBase, numDigits - 1);
		cout << dec / numPlace % outputBase;
		numDigits--;

	}

	return 0;
}

int getBaseFromOption(int option) {
	switch (option) {
	case 1:
		return 10;
	case 2:
		return 16;
	case 3:
		return 2;
	default:
		throw new std::invalid_argument("invalid input");
	}
}


int getNumDigitsInBaseN(int decimalNum, int base) {
	int n = 0;
	while (decimalNum) {
		decimalNum /= base;
		n++;
	}
	return n;
}



