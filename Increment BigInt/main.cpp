#include <iostream>

using namespace std;

void printArr( int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int * intIncrement(int arr[], int size, bool &overflow) {
	
	int addNumber = 1;

	for (int i = size -1; i >=0; i--) { 
		int tmp = arr[i] + addNumber;
		if (tmp == 10) {
			arr[i] = 0;
			addNumber = 1;
		} else {
			arr[i]= tmp;
			addNumber = 0;
		}
	}
	
	if (addNumber == 1) { //overflow 
		overflow = true;
		int * b = (int *) malloc(sizeof(int) * (size + 1));
		for (int i = size -1 ; i > 0; i--) {
			b[i+1] = arr[i];
		}
		b[1] = 0;
		b[0] = 1;
		return b;
	}

	return arr;
}

int main() {
	
	int arr[] = {1,2,3};
	//int arr[] = {1,9,9};
	//int arr[] = {9,9,9};
	int size = sizeof(arr)/ sizeof (int);
	bool overflow = false;
	int * result = intIncrement(arr,size,overflow);
	printArr(result, (overflow) ? (size + 1) : size);
	
	if (overflow) free(result);
	
	return 0;
}