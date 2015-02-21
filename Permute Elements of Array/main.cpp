#include <iostream>

using namespace std;



void printArr(char * A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void getPermutation(char * arr, int * encode, int size) {
	int nextPos = 0;

	for (int i = 0; i < size; i++) {
		if (encode[i] != 0) {
			nextPos++;
		} else break;
	}
	
	//cout << nextPos << endl;

	char tmp = arr[encode[nextPos]];
	
	arr[encode[nextPos]] =  arr[nextPos];
	nextPos = encode[encode[nextPos]];

	int numInPosition = 1;

	while(numInPosition < size) {
		char tmp2 = arr[nextPos];
		arr[nextPos] = tmp;
		tmp = tmp2;
		nextPos = encode[nextPos];

		numInPosition++;

	}
}

int main() {
	
	char arr[] = {'a','b','c','d'};
	//int encode[] = {2,3,1,0};
	int encode[] = {2,0,1,3};
	int size = sizeof(arr)/sizeof(char);

	getPermutation(arr,encode,size);

	printArr(arr,size); cout << endl;

}