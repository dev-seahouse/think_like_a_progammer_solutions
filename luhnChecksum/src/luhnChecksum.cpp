//============================================================================
// Name        : luhnChecksum.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Read an arbitary number of digits and calculates luhn check sum
// Luhn checksum is calculated by doubling every other digit and add all digits
// together
//============================================================================

#include <iostream>
using namespace std;

int isOdd(int digit) {
	return digit % 2 != 0;
}

int isEven(int digit) {
	return !isOdd(digit);
}


int doubleDigit(int digit) {
	int doubleDigit = digit * 2;
	int sum;
	if (doubleDigit >= 10)
		sum = 1 + doubleDigit % 10;
	else
		sum = doubleDigit;
	return sum;
}


int main() {
	char digit;
	int evenSum = 0;
	int oddSum = 0;
	int position = 1;
	int checkSum = 0;

	cout << "Enter any number of digits :";
	digit = cin.get();
	while (digit != 10) {
		int num = digit - '0';
		if (isEven(position)) {
			evenSum += num;
			oddSum += doubleDigit(num);
		}
		else {
			evenSum += doubleDigit(num);
			oddSum += num;
		}
		digit = cin.get();
		position++;
	}

	if (isEven(position - 1)) {
		checkSum = evenSum;
	} else {
		checkSum = oddSum;
	}

	if (checkSum % 10 == 0) {
		cout << "Checksum is divisible by 10. Valid. \n";
	} else {
		cout << "Checksum is not divisible by 10. Invalid \n";
	}
}



