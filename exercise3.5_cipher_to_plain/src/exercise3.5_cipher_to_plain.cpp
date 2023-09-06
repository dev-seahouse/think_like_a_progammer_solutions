//============================================================================
// Name        : 5_cipher_to_plain.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int findCharPosition(const char[], int, char);

int main() {

	char inputChar = -1;

	const char cipherChars[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
			'N', 'O', 'P', 'Q', };

	cout << "Enter CIPHER TEXT:" << endl;

	while ((inputChar = cin.get()) != 10) {

		if (inputChar == ',' || inputChar == '.' || inputChar == ' ') {
			cout << inputChar;
		} else {
			const int pos = findCharPosition(cipherChars, 26, inputChar);
			const char plainTextChar = 'A' + pos;
			cout << plainTextChar;
		}

	}

	return 0;
}

int findCharPosition(const char charArray[], int size, char character) {
	for (int i = 0; i < size; i++) {
		if (charArray[i] == character) {
			return i;
		}
	}
	return -1;
}
