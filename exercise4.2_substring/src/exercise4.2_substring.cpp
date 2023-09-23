//============================================================================
// Name        : 2_substring.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : takes three parameters
// 				 arrayString char*
// 				 startingPos int
//               length      int
//
//				 return a string that contains the characters in the original
// 				 string, starting at the specified position for the specified
//				 length.
//				 the original string is unaffacted by the operation.
// 				 e.g substring('abcdefg', 3, 4) // cdef
//============================================================================

#include <iostream>
using namespace std;

typedef char *arrayString;

arrayString substring(arrayString &s, int, int);

int main() {
	arrayString s = new char[6];
	s[0] = 'a';
	s[1] = 'b';
	s[2] = 'c';
	s[3] = 'd';
	s[4] = 'e';
	s[5] = 'f';

	cout << substring(s, 0, 0) << endl;
	cout << substring(s, 0, 1) << endl;
	cout << substring(s, 1, 0) << endl;
	cout << substring(s, 1, 1) << endl;
	cout << substring(s, 3, 4) << endl;
	cout << substring(s, 4, 3) << endl;
	cout << substring(s, 4, 4) << endl;


}

arrayString substring(arrayString &s, int startingPos, int length) {
	arrayString newS = new char[length + 1];
	newS[length] = 0; // terminate char

	if (length == 0 || s == NULL || startingPos == 0) {
		newS[0] = 0;
		return newS;
	}
	if (length == 1) {
		newS[0] = s[startingPos - 1];
		return newS;
	};

	for (int i = 0; i < length; i++) {
		newS[i] = s[startingPos + i - 1];
	}

	return newS;

}
