#include <iostream>

using namespace std;

bool isOdd(int number) {
	return (number & 1);
}

int findClosest(int number, int size) {
	int newNum = 0;
	if (number == 0) return 0;
	if (number == -1) return -1;

	if (isOdd(number) ) {
		int zeroAt = 0;
		while (number & (1 << zeroAt) ) {
			zeroAt++;
		}
		
		int onLeft = (-1) ^ ( (1 << (zeroAt  + 1) - 1) );

		int shiftOnLeft = onLeft >> 1;
		//cout << shiftOnLeft << endl;

		int onRight = 1 << zeroAt;
		//cout << onRight << endl;

		newNum = (number & shiftOnLeft) | onRight;
	} else {
		int oneAt = 0;
		while (! (number & (1 << oneAt) ) ) {
			oneAt++;
		}
		
		int onLeft = (-1) ^ ( (1 << oneAt) - 1) ;
		
		int shiftOnLeft = onLeft << 1;
	//	cout << shiftOnLeft << endl;
		
		int onRight = 1 << (oneAt-1);
//		cout << onRight << endl;

		newNum = (number & shiftOnLeft) | onRight;
	}

	return newNum;
}

int main() {
	
	int size = sizeof(int) * 8;
	int number = 26;
	// int number = 25;
	//int number = 92;

	int sameWeght = findClosest(number, size);
	cout << sameWeght << endl;

	return 0;
}