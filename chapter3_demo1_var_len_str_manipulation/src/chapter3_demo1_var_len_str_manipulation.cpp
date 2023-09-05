//============================================================================
// Name        : chapter3_demo1_var_len_str_manipulation.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef char *arrayString;

int length(arrayString s);
char charAt(arrayString s, int position);
void append(arrayString &s, char c);
void concatenate(arrayString &s, arrayString s2);

void appendTester();
void concatenateTester();
void concatenateTester2();

int main() {
//	appendTester();
//	concatenateTester();
	concatenateTester2();
}

char charAt(arrayString s, int position) {
	return s[position];
}

void append(arrayString &s, char c) {
	int oldLength = length(s);

	arrayString newStr = new char[oldLength + 2]; // space for +1 char and null (0)
	for (int i = 0; i < oldLength; i++) {
		newStr[i] = s[i];
	}
	newStr[oldLength] = c;
	newStr[oldLength + 1] = 0;
	delete[] s; // special syntax for deleting dynamic allocated array
	s = newStr;
}

void concatenate(arrayString &s, arrayString s2) {
	int s1OldLength = length(s);
	int s2OldLength = length(s2);
	int s1NewLength = s1OldLength + s2OldLength;

	arrayString newS = new char[s1NewLength + 1]; // +1 for null(0) sentinel

	for (int i = 0; i < s1OldLength; i++) {
		newS[i] = s[i];
	}

	for (int j = 0; j < s2OldLength; j++) {
		newS[s1OldLength + j] = s2[j];
	}

	newS[s1NewLength] = 0; // e.g newS = new char[8], char[7] (length= lastIndex + 1 since index start from 0 but length start from 1)
	delete[] s;
	s = newS;
}

int length(arrayString s) {
	int count = 0;
	while (s[count] != 0) {
		count++;
	}
	return count;
}

void appendTester() {
	arrayString a = new char[5];
	a[0] = 't';
	a[1] = 'e';
	a[2] = 's';
	a[3] = 't';
	a[4] = 0; // 0 represents null in ascII and other char code systems  and used as end of line in c and c++;
	append(a, '!');
	cout << a << "\n";
}

void concatenateTester() {
	arrayString a = new char[5];
	a[0] = 't';
	a[1] = 'e';
	a[2] = 's';
	a[3] = 't';
	a[4] = 0;

	arrayString b = new char[4];
	b[0] = 'b';
	b[1] = 'e';
	b[2] = 'd';
	b[3] = 0;
	concatenate(a, b);
	cout << a << endl;
}

void concatenateTester2() {
	arrayString a = new char[5];
	a[0] = 't';
	a[1] = 'e';
	a[2] = 's';
	a[3] = 't';
	a[4] = 0;

	arrayString c = new char[1];
	c[0] = 0;

	concatenate(c, a);

	cout << a << "\n" << c << "\n";
	cout << (void*) a << "\n" << (void*) c << "\n";
}
