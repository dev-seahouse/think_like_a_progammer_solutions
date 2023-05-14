/*
 * exercise2.4.cpp
 *
 *  Created on: 12 Feb 2023
 *      Author: k
 */

#include <iostream>
using namespace std;

void printLine(int, char);

int main() {
	for (int i = 4; i >= -4; i--) {
		if (i == 0)
			continue;
		printLine((5 - (abs(i))) * 2, ' ');
		printLine(abs(i), '#');
		printLine((5 - (abs(i))), ' ');
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






