//============================================================================
// Name        : 8_find_quartile.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct student {
	int grade; // assume that grades does not have decimal
	int studentID;
	string name;
};

bool isDivisibleBy(int, int);
float getAverage(int, int);
bool shouldTakeAverage(float);
float getStudentQuartile(float, int, int);

int compare(const void *voidA, const void *voidB) {

	student *studentA = (student*) voidA;
	student *studentB = (student*) voidB;

	return studentA->grade - studentB->grade;
}

int main() {

	const int ARRAY_SIZE = 10;

	student studentArray[ARRAY_SIZE] = { { 87, 1001, "Fred" },
			{ 28, 1002, "Tom" }, { 100, 2004, "Alistair" },
			{ 78, 1004, "Saha" }, { 84, 1005, "Erin" }, { 98, 1006, "Belinda" },
			{ 75, 1007, "Leslie" }, { 70, 1008, "Candy" },
			{ 81, 1009, "Aretha" }, { 68, 10010, "Veronica" } };

	qsort(studentArray, ARRAY_SIZE, sizeof(student), compare);

//	cout << "Student grades: { ";
//	for (student s : studentArray) {
//		cout << s.grade << ",";
//	}
//	cout << "}" << endl;

	float q1Position = (ARRAY_SIZE + 1) / 4.0;
	float q1 = getStudentQuartile(q1Position,
			studentArray[(int) (q1Position)].grade,
			studentArray[(int) (q1Position - 1)].grade);
	cout << "Q1 (25% ) is " << q1 << endl;

	float q2Position = (ARRAY_SIZE + 1) / 2.0;

	float q2 = getStudentQuartile(q2Position,
			studentArray[(int) (q2Position)].grade,
			studentArray[(int) (q2Position - 1)].grade);
	cout << "Q2 (50%) is " << q2 << endl;

	float q3Position = ((ARRAY_SIZE + 1) / 4.0) * 3;
	float q3 = getStudentQuartile(q3Position,
			studentArray[(int) (q3Position)].grade,
			studentArray[(int) (q3Position - 1)].grade);
	cout << "Q3 (75%) is " << q3 << endl;

	return 0;
}

float getStudentQuartile(float position, int gradeAtIndex,
		int gradeAtIndexMinusOne) {
	float res =
			shouldTakeAverage(position) ?
					getAverage(gradeAtIndex, gradeAtIndexMinusOne) :
					gradeAtIndexMinusOne;
	return res;
}

bool isDivisibleBy(int divisor, int dividend) {
	return dividend % divisor == 0 ? true : false;
}

float getAverage(int num1, int num2) {
	return (num1 + num2) / 2.0;
}

bool shouldTakeAverage(float numA) {
	return (int) (numA) != numA;
}

