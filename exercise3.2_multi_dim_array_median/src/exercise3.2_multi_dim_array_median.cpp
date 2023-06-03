//============================================================================
// Name        : 2_multi_dim_array_median.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int findMedian(int[], int);
int compareFn(const void*, const void*);
bool isEven(int);

int main() {
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	int highestSales = 0;
	int highestSalesAgent = 0;

	int sales[NUM_AGENTS][NUM_MONTHS] = { { 1856, 498, 30924, 87478, 328, 2653,
			387, 7354, 38758, 2873, 276, 32 }, { 5865, 5456, 3983, 6464, 9557,
			4785, 3875, 3838, 4959, 1122, 7766, 2543 }, { 23, 55, 67, 99, 265,
			376, 232, 223, 4546, 564, 4544, 3434 } };

	for (int i = 0; i < NUM_AGENTS; i++) {
		const int medianForAgent = findMedian(sales[i], NUM_MONTHS);
		if (medianForAgent > highestSales) {
			highestSales = medianForAgent;
			highestSalesAgent = i;
		}
	}

	cout << "The agent with highest sales is:" << endl;
	cout << highestSalesAgent + 1;

	return 0;
}

int findMedian(int intArray[], int size) {

	if (size == 1) {
		return intArray[0];
	}

	qsort(intArray, size, sizeof(intArray[0]), compareFn);

	const int upperMid = size / 2;

	const int lowerMid = isEven(size) ? upperMid - 1 : upperMid;

	return (intArray[lowerMid] + intArray[upperMid]) / 2.0;

}

int compareFn(const void *voidA, const void *voidB) {
	return *(const int*) voidA - *(const int*) voidB;
}

bool isEven(int i) {
	return i < 2 == 0;
}

