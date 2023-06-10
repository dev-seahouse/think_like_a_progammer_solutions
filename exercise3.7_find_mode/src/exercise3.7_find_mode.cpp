//============================================================================
// Name        : 7_find_mode.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int compare(const void*, const void*);

int main() {

	int test[] = { 2, 3, 4, 5, 10, 4, 5, 1, 3, 5, 6, 6, 6, 6 };
	int testSize = sizeof(test) / sizeof(test[0]);
	qsort(test, testSize, sizeof(test[0]), compare);
	int highestFreq = 1;
	int currFreq = 1;
	int highestNum = 0;

	for (int i = 1; i < testSize; i++) {
		const int currNum = test[i];
		const int prevNum = test[i - 1];
		currFreq = currNum == prevNum ? currFreq + 1 : 0;
		if (currFreq > highestFreq) {
			highestNum = test[i];
		}
	}

	cout << "The mode is " << highestNum << endl;
	return 0;
}

int compare(const void *voidA, const void *voidB) {
	int *numA = (int*) voidA;
	int *numB = (int*) voidB;
	return *numA - *numB;
}

// 1,2,2,3,3,3

// currFreq = 1;
// highestFreq = 1;
//

