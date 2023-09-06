//============================================================================
// Name        : 6_cipher_random.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cmath>
#include<ctime>
#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	const int NUM_CIPHER_CHARS = 26;
	const int USED_CHAR = -1;

	char cipherCharSet[NUM_CIPHER_CHARS] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
			'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z' };

	char cipherChars[NUM_CIPHER_CHARS];

	srand(time(NULL));

	for (int i = 0; i < NUM_CIPHER_CHARS; i++) {
		int randomIdx = rand() % NUM_CIPHER_CHARS;

		while (randomIdx == i || cipherCharSet[randomIdx] == USED_CHAR) {
			randomIdx = rand() % NUM_CIPHER_CHARS;
		}

		cipherChars[i] = cipherCharSet[randomIdx];
		cipherCharSet[randomIdx] = USED_CHAR;
	}

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

