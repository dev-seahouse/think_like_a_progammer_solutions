//============================================================================================================
// Name        : 6_linked_list_string.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : create an implementation of strings that users a linked list of characters
//				 instead of dynamically allocated arrays.
// 			     - the data payload is a single char.
//				 - charAt
//				 - append
//			     - concat - create a copy of each node in s2 and append them to end of s1
//					        should not simply point the next field of the last node in s1 to first node of s2
//============================================================================================================

#include <iostream>
using namespace std;

struct listNode {
	char c;
	listNode *next;
};

typedef listNode *stringCollection;
//char charAt(stringCollection, int);
void append(stringCollection &sc, char c);
bool hasNext(listNode &node);

listNode* tail(stringCollection);
void output(stringCollection &sc);
void concat(stringCollection &s1, stringCollection s2);
void test();

int main() {
	test();
}

void append(stringCollection &sc, char c) {

	listNode *newNode = new listNode;
	newNode->c = c;
	newNode->next = NULL; // if don't do this, next will be random memory

	// this requires new list to be initialized with NULL;
	if (sc == NULL) {
		sc = newNode;
		return;
	}

	// find last node
	listNode *lastNode = tail(sc);
	lastNode->next = newNode;
}


listNode* tail(stringCollection sc) {
	listNode *ptr = sc;
	while (ptr != NULL) {
		if (ptr->next == NULL) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

bool hasNext(listNode *currNode) {
	if (currNode == NULL) {
		return false;
	}

	return (currNode->next) != NULL;
}

void concat(stringCollection &s1, stringCollection s2) {

	listNode *s2Ptr = s2;
	listNode *s1Ptr = tail(s1);

	while (s2Ptr != NULL) {
		listNode *newNode = new listNode;
		newNode->c = s2Ptr->c;
		newNode->next = s2Ptr->next;

		if (s1Ptr == NULL) {
			s1Ptr = newNode;
		} else {
			s1Ptr->next = newNode;
			s1Ptr = s1Ptr->next;
		}

		s2Ptr = s2Ptr->next;
	}
}

void output(stringCollection &sc) {
	listNode *ptr = sc;
	if (ptr == NULL) {
		cout << "list is empty" << endl;
	}
	while (ptr != NULL) {
		cout << ptr->c;
		ptr = ptr->next;
	}
}

void test() {
	cout << "normal test:" << endl;
	stringCollection str1 = NULL;
	append(str1, 't');
	append(str1, 'e');
	append(str1, 's');
	append(str1, 't');
	append(str1, ' ');

	stringCollection str2 = NULL;
	append(str2, 'h');
	append(str2, 'e');
	append(str2, 'l');
	append(str2, 'l');
	append(str2, 'o');

	concat(str1, str2);
	output(str1);

	cout << endl << endl;

	cout << "first str is null" << endl;
	delete str1;
	str1 = NULL; // new node must be initialized with null
	concat(str1, str2);
	output(str1);
	cout << endl;

	cout << "second str is null:" << endl;
	delete str1;
	str1 = NULL;
	// new node must be initialized with null;
	append(str1, 't');
	append(str1, 'e');
	append(str1, 's');
	append(str1, 't');

	delete str2;
	str2 = NULL; // new node must be initialized with null
	concat(str1, str2);
	output(str1);
	cout << endl << endl;

	cout << "both list are of single char" << endl;
	delete str1;
	str1 = NULL;
	// new node must be initialized with null
	append(str1, 'h');
	delete str2;
	str2 = NULL;
	append(str2, 'i');

	concat(str1, str2);
	output(str1);
	cout << endl;

}

