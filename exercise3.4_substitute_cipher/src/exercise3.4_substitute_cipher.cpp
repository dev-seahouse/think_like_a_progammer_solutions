//============================================================================
// Name        : 4_substitute_cipher.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const char cipherChars[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
			'N', 'O', 'P', 'Q', };

	char inputChar = -1;

	cout << "Enter PLAIN TEXT consist of only upper case characters , and ."
			<< endl;

	while ((inputChar = cin.get()) != 10) {
		int cipherCharPotition = inputChar - 'A';
		char cipherChar = cipherChars[cipherCharPotition];
		if (inputChar == ',' || inputChar == '.' || inputChar == ' ') {
			cout << inputChar;
		} else {
			cout << cipherChar;
		}
	}

}
