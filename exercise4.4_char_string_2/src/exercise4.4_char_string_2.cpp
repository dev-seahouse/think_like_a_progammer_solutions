//============================================================================
// Name        : 4_char_string_2.cpp
// Author      : kenan
// Version     :
// Copyright   : Your copyright notice
// Description : change implementation or arrayString such that
// 			 	 location[0] stores the size of the array rather then using sentry
//			     implement: append , concatenate and charAt.
// 				 write your own output function to loop through
//=================================================================================


#include <iostream>
using namespace std;

typedef char *arrayString;
void output(arrayString s);
int len(arrayString s);
char charAt(arrayString s, int position);
void append(arrayString &s, char c);
void concatenate(arrayString &s, arrayString s2);

void test();

int main() {
	test();
	return 0;
}

void output(arrayString s) {
	int length = len(s);
	for (int i = 0; i < length; i++) {
		cout << s[i + 1];
	}
}

int len(arrayString s) {
	if (!s[0]) return 0;
	return s[0];
}

char charAt(arrayString s, int position) {
	return s[position + 1];
}

void append(arrayString &s, char c) {
	int oldLength = len(s);
	int newLength = oldLength + 1;
	arrayString newS = new char[newLength + 1];
	for (int i = 1; i <= oldLength; i++) {
		newS[i] = s[i];
	}
	newS[newLength] = c;
	newS[0] = newLength;
	delete[] s;
	s = newS;
}

void concatenate(arrayString &s, arrayString s2) {
	int s1Len = len(s);
	int s2Len = len(s2);
	int newLen = s1Len + s2Len;
	arrayString newS = new char[newLen + 1];

	int pointer = 1;

	while (pointer < newLen + 1) {
		if (pointer <= s1Len) {
			newS[pointer] = s[pointer];
		} else {
			newS[pointer] = s2[pointer - s1Len];
		}
		pointer++;
	}

	newS[0] = newLen;
	delete[] s;
	s = newS;
}

void test() {
	arrayString test = new char[5];
	test[0] = 4;
	test[1] = 't';
	test[2] = 'e';
	test[3] = 's';
	test[4] = 't';

	arrayString test1 = new char[6];
	test1[0] = 5;
	test1[1] = 'h';
	test1[2] = 'e';
	test1[3] = 'l';
	test1[4] = 'l';
	test1[5] = 'o';

	cout << "charAt(0): " << charAt(test, 0) << endl << endl;

	cout << "append('test,'s') : " << endl;
	append(test, 's');
	output(test);
	cout << endl << endl;

	cout << "concatenate('tests','hello') : " << endl;
	concatenate(test, test1);
	output(test);
	cout << endl;

}

