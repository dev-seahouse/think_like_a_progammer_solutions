//============================================================================
// Name        : 9_higest_salary.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	float highestSalesAverage = 0;

	int sales[NUM_AGENTS][NUM_MONTHS] = { { 1856, 498, 30924, 87478, 328, 2653,
			387, 7354, 38758, -1 }, { 5865, 5456, 3983, 6464, 9557, 4785, 3875,
			3838, 4959, 1122, 7766, -1 }, { 23, 55, 67, 99, 265, 376, 232, 223,
			4546, 564, -1 } };

	for (int agent = 0; agent < NUM_AGENTS; agent++) {
		int currMonth = 0;
		int currTotal = 0;
		while (sales[agent][currMonth] >= 0 && currMonth < NUM_MONTHS) {
			currTotal += sales[agent][currMonth];
			currMonth++;
		}

		float average = currTotal / (float) (currMonth);

		if (average > highestSalesAverage) {
			highestSalesAverage = average;
		}
		currTotal = 0;
		currMonth = 0;
	}

	cout << "Highest sales average is " << highestSalesAverage;

	return 0;
}
