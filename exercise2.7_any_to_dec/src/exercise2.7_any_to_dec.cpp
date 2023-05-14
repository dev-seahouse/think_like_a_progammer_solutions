//============================================================================
// Name        : 7_any_to_dec.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int toDecimalConverter(int);

int main() {
	cout << toDecimalConverter(2);
}

int toDecimalConverter(int baseX) {
	int digitSize = 64 / baseX;
	char ch = '0';
	int dec = 0;
	int digit = 0;
	int digitCount = 0;

	// convert baseN to base 10
	while (ch != 10 && digitCount <= digitSize) {
		ch = cin.get();
		if (ch == ' ' || ch == 10)
			continue;
		digit = ch < 'A' ? ch - '0' : ch - 'A' + 10;
		dec = dec * baseX + digit;
		digitCount++;
	}

	cout << dec;
}
