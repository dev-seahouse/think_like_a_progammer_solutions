//============================================================================
// Name        : 7_dec_to_hex_no_string.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// works in any number base

// 345_10 = 159_16

// 345 / 10^2 = 3   % 10 = 3
// 345 / 10^1 = 34  % 10 = 4
// 345 / 10^0 = 345 % 10 = 5

// 345 / 16^2 = 1   % 16 = 1
// 345 / 16^1 = 12  % 16 = 5
// 345 / 16^0 = 345 % 16 = 9


#include <iostream>
#include <cmath>
using namespace std;

char intToChar(int);
int readInt();
int getNumDigitsInBase(int, int);
char getLetterDigit(int);


int main() {
	cout << "Enter a decimal number" << endl; // prints !!!Hello World!!!
	int decimalNum = readInt();

	const int BASE = 16;
	int totalDigitsInHex = getNumDigitsInBase(decimalNum, BASE);
	for (int power = totalDigitsInHex - 1; power >= 0; power--) {
		int numPosition = pow(BASE, power);
		int digit = decimalNum / numPosition % BASE;
		cout << getLetterDigit(digit);
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



char intToChar(int num) {
	return num + '0';
}



int getNumDigitsInBase(int num, int base) {
	if (num == 0)
		return 0;
	return getNumDigitsInBase(num / base, base) + 1;
}

char getLetterDigit(int num) {
	if (num <= 10)
		return intToChar(num);
	return num + ('A' - 10);

}













