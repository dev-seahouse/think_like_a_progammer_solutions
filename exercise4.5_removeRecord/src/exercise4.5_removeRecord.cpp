//============================================================================
// Name        : 5_removeRecord.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : removeRecord
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
void removeRecord(studentCollection&, int);
void output(studentCollection sc);
void test();


int main() {
	test();
	return 0;
}

void addRecord(studentCollection &sc, int stuNum, int gr) {
	listNode *newNode = new listNode;
	newNode->studentNum = stuNum;
	newNode->grade = gr;
	newNode->next = sc;
	sc = newNode;
	newNode = NULL;
}

void removeRecord(studentCollection &sc, int studNum) {
	if (sc == NULL) {
		cout << "Unable to remove, collection is empty." << endl;
	}

	listNode *currNode = sc;
	listNode *prevNode = NULL;
	int counter = 0;

	while (currNode!=NULL) {

		listNode *nextNode = currNode->next;

		if (currNode->studentNum == studNum) {
			// is head
			if (prevNode == NULL) {
				delete sc;
				sc = nextNode;
				// we break here because the next line prevNode->next will blow when prevNode is NULL
				break;
			}
			prevNode->next = nextNode;
			delete currNode;
			currNode = NULL;
		}
		prevNode = currNode;
		currNode = nextNode; // have to be nextNode instead of currNode.next because line 61 could delete currNode and currNode would be null
		counter++;
	}


}

void test() {
	studentCollection sc = NULL;
	cout << "remove empty collection: " << endl;
	removeRecord(sc, 1274);
	cout << endl;

	cout << "remove collection with one record (non-exist)" << endl;
	addRecord(sc, 1271, 94);
	removeRecord(sc, 1111);
	output(sc);
	cout << endl;

	cout << "remove collection with one record(exist)" << endl;
	removeRecord(sc, 1271);
	output(sc);
	cout << endl;

	cout << "remove collection with two records(non-exist)"<< endl;
	addRecord(sc, 1271, 94);
	addRecord(sc, 1272, 95);
	removeRecord(sc, 12555);
	output(sc);
	cout << endl;

	cout << "remove fist item of collection with two records(exist)" << endl;
	removeRecord(sc, 1272);
	output(sc);
	cout << endl;

	cout << "remove second item of collection with two records(exists)" << endl;
	addRecord(sc, 1272, 88);
	removeRecord(sc, 1271);
	output(sc);
	cout << endl;


	cout << "remove second item from collection with 3 records" << endl;
	addRecord(sc, 1271, 88);
	addRecord(sc, 1273, 88);
	removeRecord(sc, 1271);
	output(sc);

}

void output(studentCollection sc) {
	listNode *studPtr = sc;
	cout << "======================" << endl;
	if (studPtr == NULL || studPtr ==nullptr ) {
		cout << "no records" << endl;
	}
	while (studPtr) {
		cout << "student number: " << studPtr->studentNum << endl;
		studPtr = studPtr->next;
	}
	cout << "======================" << endl;
}
