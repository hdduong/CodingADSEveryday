#include <iostream>

using namespace std;

void printArr(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int deleteKey(int arr[], int size, int key) {
	int newSize = 0;
	int prev_i = 0;
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] < key) {
			prev_i++;
		} else if (arr[i] == key) {
			count++;	
		} else if (arr[i] > key) {
			arr[prev_i] = arr[i];
			prev_i++;			
		}
	}
	newSize = size  - count;

	return newSize;
}



int main() {
	int arr[] = {2,3,3,5,5,7,7,8,11};
	int size = sizeof (arr) / sizeof(int);
	
	int newSize = deleteKey(arr,size,3);
	cout << newSize << endl;
	printArr(arr,newSize);
	return 0;
}