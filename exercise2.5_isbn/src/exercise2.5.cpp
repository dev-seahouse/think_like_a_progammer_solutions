//============================================================================
// Name        : 5.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : ISBN-13 check digit
//============================================================================

#include <iostream>
#include <cmath>;
using namespace std;

bool isEven(int);
int getCheckDigit(int);


int main() {
	cout << "Enter a 12 digit number \n";
	int sum = 0;
	int position = 1;
	int checkDigit = 0;
	int num = 0;
	char digitChar = INFINITY;

	while ((digitChar = cin.get()) != 10) {
		num = digitChar - '0';
		sum += isEven(position) ? num * 3 : num;
		position++;
	}

	// if user entered 12 digit
	if (position - 1 == 11) {

	checkDigit = getCheckDigit(sum);
	cout << "The check digit is " << checkDigit << ".\n";

	} else {
		checkDigit = getCheckDigit(sum - num);
		cout << "The ISBN is " << (checkDigit == num ? "valid" : "invalid")
				<< ".\n";
	}

	return 0;
}

bool isEven(int num) {
	return num % 2 == 0;
}

int getCheckDigit(int checksum) {
	int remainder = checksum % 10;
	return remainder == 0 ? remainder : 10 - remainder;
}
