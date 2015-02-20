#include<iostream>

using namespace std;


bool isContigousIS(int arr[], int size, int startI, int endI, int & checkedIndex) {

	if (startI >= endI) {
		checkedIndex = startI;
		return true;
	}

	int checkUntil = (startI > checkedIndex) ? startI :  checkedIndex;

	for (int j = endI; j > checkUntil; j--) {
		if (arr[j] > arr[j-1]) continue;
		else {
			checkedIndex = j;
			return false;
		}
	}
	checkedIndex = endI;
	return true;
}

/// not brute force solutution
/// go with 
void computeLISA(int arr[], int size, int &overS, int &overE, int &overLen) {
	int curS, curE;
	curS = curE = 0;

	int curLen;
	curLen  = 1;;

	int checkedIndex = -1;

	while (curS < size) {
		
		curE = curS + curLen - 1;		
		if (curE > size - 1) break;

		if (isContigousIS(arr,size,curS,curE,checkedIndex) ) {
			curLen++;
		} else {

			if (overLen < curLen) {
				overLen = curLen - 1;
				overS = curS;
				overE = curE;
			
			}

			curS = checkedIndex;
			curLen = overLen;
		}

	}

	if (curLen > overLen) {
		overLen = curLen;
		overS = curS;
		overE = curE-1;
	}
}

int main() {
	//int arr[] = {1,2,3,3,2,4,6,7};
	int arr[] = {4,-9,5,6,1};
	int size = sizeof(arr)/sizeof(int);

	int startIndex = 0;
	int endIndex = 0;
	int length = 1;

	computeLISA(arr, size, startIndex, endIndex, length);
	cout << startIndex << " " << endIndex << endl;
	return 0;
}