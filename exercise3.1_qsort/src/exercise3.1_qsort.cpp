//============================================================================
// Name        : 1_qsort.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : 1. sort student struct by grade 2. sort student struct by ID
//============================================================================

#include <iostream>
using namespace std;

int compareByGradeFn(const void*, const void*);
int compareByIDFn(const void*, const void*);

struct student {
	int grade;
	int studentID;
	string name;
};

int main() {

	const int ARRAY_SIZE = 10;

	student studentArray[ARRAY_SIZE] = { { 87, 1001, "Fred" },
			{ 28, 1002, "Tom" }, { 100, 2004, "Alistair" },
			{ 78, 1004, "Saha" }, { 84, 1005, "Erin" }, { 98, 1006, "Belinda" },
			{ 75, 1007, "Leslie" }, { 70, 1008, "Candy" },
			{ 81, 1009, "Aretha" }, { 68, 10010, "Veronica" } };

	qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByIDFn);
	cout << "\nThe Students are (sorted by ids):" << endl;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%-8s\t|%d\n", studentArray[i].name.c_str(),
				studentArray[i].studentID);
	}
	cout << "\nThe top grades are:" << endl;
	qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByGradeFn);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%-8d\t|%s\n", studentArray[i].grade,
				studentArray[i].name.c_str());
	}

}

int compareByGradeFn(const void *voidA, const void *voidB) {
	student *studentA = (student*) (voidA);
	student *studentB = (student*) (voidB);
	return studentB->grade - studentA->grade;

}

int compareByIDFn(const void *voidA, const void *voidB) {
	student *studentA = (student*) (voidA);
	student *studentB = (student*) (voidB);
	return studentA->studentID - studentB->studentID;

}

