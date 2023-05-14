//============================================================================
// Name        : sidewaytriangle.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	for (int row = 0; row <= 7; row++) {
		for (int hashRow = 1; hashRow < 4 - abs(4 - row); hashRow++) {
			cout << "#";
		}
		cout << "\n";
	}
	return 0;
}
