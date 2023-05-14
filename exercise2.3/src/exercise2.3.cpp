//============================================================================
// Name        : 2.3.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printLine(int, char);

int main() {
	for (int i = 4; i >= -4; i--) {
		if (i == 0)
			continue;
		printLine((5 - (abs(i))), ' ');
		printLine((5 - (abs(i))), '#');
		printLine(((abs(i) - 1) * 4), ' ');
		printLine((5 - (abs(i))), '#');
		cout << "\n";
	}
	return 0;
}

void printLine(int num, char c) {
	for (int i = 0; i < num; i++) {
		cout << c;
	}
}
