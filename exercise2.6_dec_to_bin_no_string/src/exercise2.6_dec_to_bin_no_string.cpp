//============================================================================
// Name        : 6_dec_to_bin_no_string.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// the usual algorithm of binary conversions involves
// continuously dividing the decimal number and get the remainder,
// the result will be in right to left order
// however we want to process in left to right order without using string
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int readInt();
int getNumBinaryDigits(int decimalNum);

int main() {
	cout << "Enter a decimal number:";
	int BASE = 2;
	int decimalNum = readInt();
	int numBinDigits = getNumBinaryDigits(decimalNum);
	int power = numBinDigits - 1;
	while (power >= 0) {
		// e.g for decimal numbers ,
		// 123 have number positions hundredth, tenth, and ones
		int numberPosition = pow(BASE, power);
		int digit = decimalNum / numberPosition % BASE;
		cout << digit;
		power--;
	}
	return 0;
}

int readInt() {
	char digitChar;
	int digitNum;
	int decimal = 0;
	while ((digitChar = cin.get()) != 10) {
		digitNum = digitChar - '0';
		decimal = decimal * 10 + digitNum;
	}
	return decimal;
}

int getNumBinaryDigits(int decimalNum) {
	int count = 0;
	while (decimalNum) {
		decimalNum = decimalNum / 2;
		count++;
	}
	return count;
}
