//============================================================================
// Name        : 2.2cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

void printLine(int, char);

int main() {
	for (int i = 4; i >= -4; i--) {
		if (i == 0)
			continue;
		printLine(abs(i), ' ');
		printLine((5 - (abs(i))) * 2, '#');
		cout << "\n";
	}
	return 0;
}

void printLine(int num, char c) {
	for (int i = 0; i < num; i++) {
		cout << c;
	}
}
