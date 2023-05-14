//============================================================================
// Name        : 1.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printLine(int, char);

int main() {
	for (int i = 4; i > 0; i--) {
		printLine(4 - i, ' ');
		printLine(2 * i, '#');
		cout << "\n";
	}
}


void printLine(int num, char c) {
	for (int i = 0; i < num; i++) {
		cout << c;
	}
}
