//============================================================================
// Name        : 6_linked_list_string.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : create an implementation of strings that users a linked list of characters
//				 instead of dynamically allocated arrays.
// 			     - the data payload is a single char.
//				 - charAt
//				 - append
//============================================================================

#include <iostream>
using namespace std;

struct listNode {
	char c;
	listNode *next;
};

typedef listNode *stringCollection;
char charAt(stringCollection, int);
void append(stringCollection &sc, char c);
listNode* tail(const stringCollection&);
void output(const stringCollection &sc);
void test();

int main() {
	test();
}

void append(stringCollection &sc, char c) {

	listNode *newNode = new listNode;
	newNode->c = c;
	newNode->next = NULL; // if don't do this, next will be random memory

	if (sc == NULL) {
		sc = newNode;
		return;
	}

	// find last node
	listNode *lastNode = tail(sc);
	lastNode->next = newNode;
}

listNode* tail(const stringCollection &sc) {
	listNode *ptr = sc;
	while (ptr != NULL) {
		if (ptr->next == NULL) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void output(const stringCollection &sc) {
	listNode *ptr = sc;
	while (ptr != NULL) {
		cout << ptr->c;
		ptr = ptr->next;
	}
}

void test() {
	stringCollection str = NULL;
	append(str, 't');
	append(str, 'e');
	append(str, 's');
	append(str, 't');
	append(str, 's');
	output(str);
	delete str;

	// even after delete operation, the memory is only marked as deallocated,
	// it might or might not be erased
	// it is programmer's responsibility to not accessing it and there is no protection
	// when we call append, if search finds the last node that exists in the list,
	// if we pass in the reference of the old heap , it might still find it therefore causing unexpected behvaiour
	// therefore we need to allocate a new piece of heap after removing it

	str = NULL;
	append(str, 't');
	output(str);
}

