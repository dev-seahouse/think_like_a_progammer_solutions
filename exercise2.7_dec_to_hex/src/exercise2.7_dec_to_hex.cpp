//============================================================================
// Name        : 7_dec_to_hex.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char intToChar(int);
int readInt();


int main() {
	cout << "enter a decimal number";
	int decimalNum = readInt();
	int quotient = decimalNum;
	int remainder;
	while (quotient != 0) {
		remainder = quotient % 16;
	}
	return 0;
}

int readInt() {
	char digitChar;
	int digitNum;
	int decimal = 0;
	while ((digitChar = cin.get()) != 10) {
		digitNum = intToChar(digitChar);
		decimal = decimal * 10 + digitNum;
	}
	return decimal;
}

char intToChar(int num) {
	return num + '0';
}
