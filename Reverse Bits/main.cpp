#include <iostream>

using namespace std;

int reverseBit(int number, int size) {
	int newNum = 0;

	for (int i = size - 1; i >= size / 2; i--) {
		newNum = newNum | ( (number & (1 << (i-1)) ) >> (i-1) );
	}

	for (int i = 0; i <= size / 2 - 1; i++) {
		newNum = newNum | ( (number & (1 << i) ) << ( (size-1) - (i << 2)) );
	}

	return newNum;
}

int main() {
	int intSize = sizeof(int);
	int reverseInt = 25323;

	//int reverseInt = 5;

	int newNum = reverseBit(reverseInt, intSize * 8);
	cout << newNum << endl;

	return 0;
}