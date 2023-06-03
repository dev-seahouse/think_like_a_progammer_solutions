//============================================================================
// Name        : 3_check_if_sorted.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool isSorted(int[], int size);

int main() {

	int unsortedArray[] = { 4, 3, 5, 9, 3 };
	int sortedArray[] = { 1, 3, 4 };

	cout << "The array : [ ";

	for (int i = 0; i < 5; i++) {
		cout << unsortedArray[i] << ",";
	}

	cout << "] is ";

	cout << (isSorted(unsortedArray, 5) ? "sorted" : "not sorted") << endl;

	cout << "The array : [ ";

	for (int i = 0; i < 3; i++) {
		cout << sortedArray[i] << ",";
	}

	cout << "] is ";

	cout << (isSorted(sortedArray, 3) ? "sorted" : "not sorted") << endl;

}

bool isSorted(int array[], int size) {
	int prevElement = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < prevElement) {
			return false;
		}
		prevElement = array[i];
	}

	return true;
}

