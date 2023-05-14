//============================================================================
// Name        : 6_dec_to_bin.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
using namespace std;

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


int main() {
	cout << "Enter a decimal number:";
	int decimalNum = readInt();
	int quotient = decimalNum;
	int remainder;
	string binaryStr = "";
	while (quotient != 0) {
		remainder = quotient % 2;
		quotient = quotient / 2;
		char remainderChar = remainder + '0';
		binaryStr = remainderChar + binaryStr;
	}
	cout << "The decimal " << decimalNum << " is " << binaryStr
			<< " in binary.";

	return 0;
}
