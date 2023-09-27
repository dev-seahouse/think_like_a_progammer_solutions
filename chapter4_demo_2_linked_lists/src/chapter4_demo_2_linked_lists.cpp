//============================================================================
// Name         : chapter3_demo_2_linked_lists.cpp
// Author       :
// Version      :
// Copyright    : Your copyright notice
// Description  :
// addRecord    : takes a pointer to a collection of
// 				  student records, a student number, a grade
// 				  and it adds a new record with this data to the collection.
//
// averageRecord: takes a pointer to a collection of student records
// 				  and returns the simple average of student grades in the
// 				  collection as a double.
//
//
//============================================================================

#include <iostream>
using namespace std;

struct listNode {
	int studentNum;
	int grade;
	listNode *next;
};

typedef listNode *studentCollection;

void addRecord(studentCollection&, int, int);
double averageRecord(studentCollection);

int main() {
	studentCollection sc = NULL;
	addRecord(sc, 1274, 81);

	double res = averageRecord(sc);
	cout << res;
}

void addRecord(studentCollection &sc, int stuNum, int gr) {
	listNode *newNode = new listNode;
	newNode->studentNum = stuNum;
	newNode->grade = gr;
	newNode->next = sc;
	sc = newNode;
}

double averageRecord(studentCollection sc) {
	int count = 0;
	double sum = 0;
	listNode *loopPtr = sc;

	while (loopPtr != NULL) {
		sum += loopPtr->grade;
		count++;
		loopPtr = loopPtr->next;
	}

	double average = sum / count;
	return average;

}

