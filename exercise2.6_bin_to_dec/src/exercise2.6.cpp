//============================================================================
// Name        : 6.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Constraints:
// 1. no string
// 2. no array
// 3. no do while (because i don't like it)
//============================================================================


#include <iostream>
#include <math.h>

using namespace std;

int isOdd(int digit) {
	return digit % 2 != 0;
}

int isEven(int digit) {
	return !isOdd(digit);
}


int main() {
	char digitChar;
	int position = 1;
	int decimal = 0;

	cout << "Enter a binary number:" << endl;

	while ((digitChar = cin.get()) != 10) {
		int digitNum = digitChar - '0';
		if (position == 1) {
			decimal = digitNum;
		} else {
			decimal = decimal * 2 + digitNum;
		}
		position++;
	}

	cout << "The decimal number is" << " is " << decimal << endl;

	return 0;
}
