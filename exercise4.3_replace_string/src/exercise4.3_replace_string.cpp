//============================================================================
// Name        : 3_replace_string.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : takes three parameters
// 				 1. source		: 		arrayString
//			     2. target		: 		arrayString
// 				 3. replaceText :		arrayString
// 				 replace every occurrence of target in source with replaceText.
//				 example: replaceString('abcdabee, 'ab', 'xyz') // xyzcdxyzee
//============================================================================

#include <iostream>
using namespace std;

typedef char *arrayString;

void test();
int len(arrayString &source);
bool isMatched(arrayString &source, arrayString target, int start);

arrayString replaceString(arrayString &source, arrayString target,
		arrayString replaceText);

int main() {
	test();
	return 0;
}

arrayString replaceString(arrayString &source, arrayString target,
		arrayString replaceText) {

	int targetLen = len(target);
	int sourceLen = len(source);
	int replaceTextLen = len(replaceText);

	if (targetLen == 0 || sourceLen == 0 || targetLen > sourceLen) {
		return source;
	}

	int i = 0;
	while (source[i] != 0) {

		if (isMatched(source, target, i)) {

			int startPos = i;
			int endPos = i + targetLen - 1;
			int newLen = len(source) + (replaceTextLen - targetLen);
			arrayString temp = new char[newLen + 1];

			for (int k = 0; k < startPos; k++) {
				temp[k] = source[k];
			}

			for (int j = 0; j < replaceTextLen; j++) {
				temp[startPos + j] = replaceText[j];
			}

			for (int h = endPos + 1; h < len(source); h++) {
				temp[h + (replaceTextLen - targetLen)] = source[h];
			}

			temp[newLen] = 0;
			delete[] source;
			source = temp;
			temp = NULL;
		}

		i++;
	}

	return source;
}

int len(arrayString &source) {

	int count = 0;
	while (source[count] != 0) {
		count++;
	}
	return count;
}

bool isMatched(arrayString &source, arrayString target, int start) {
	int targetLen = len(target);
	int sourceLen = len(source);
	for (int i = 0; i < targetLen && start + i < sourceLen; i++) {
		if (target[i] != source[start + i]) {
			return false;
		}
	}
	return true;
}

void test() {
	// good input test
	arrayString sourceTest = new char[9];
	sourceTest[0] = 'a';
	sourceTest[1] = 'b';
	sourceTest[2] = 'c';
	sourceTest[3] = 'd';
	sourceTest[4] = 'a';
	sourceTest[5] = 'b';
	sourceTest[6] = 'e';
	sourceTest[7] = 'e';
	sourceTest[8] = 0;

	arrayString target = new char[3];
	target[0] = 'a';
	target[1] = 'b';
	target[2] = 0;

	arrayString replaceText = new char[4];
	replaceText[0] = 'x';
	replaceText[1] = 'y';
	replaceText[2] = 'z';
	replaceText[3] = 0;

	cout << "standard test(returns xyzcdxyzee)" << endl;
	cout << replaceString(sourceTest, target, replaceText) << endl << endl;

	cout << "target equal to source test(returns xyz)" << endl;
	cout << replaceString(target, target, replaceText) << endl << endl;

	cout << "target longer than source test(returns xyz)" << endl;
	// source 'ab', target:"xyz"
	cout << replaceString(target, replaceText, replaceText) << endl << endl;

	// empty source test
	cout << "empty source: (returns empty string)" << endl;
	arrayString emptyString = new char[1];
	emptyString[0] = 0;
	cout << replaceString(emptyString, target, replaceText) << endl << endl;

	// empty target test
	cout << "empty target: (returns source)" << endl;
	cout << replaceString(sourceTest, emptyString, replaceText) << endl << endl;

}


