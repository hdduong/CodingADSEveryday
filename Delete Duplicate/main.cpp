#include <iostream>

using namespace std;

void printArr(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int deleteDuplicate(int * arr, int size) {
	int prev_i = 0;
	
	if (size == 1) return 1;

	int i = 1;
	int remNum = INT_MAX;

	while (i < size) {
		if (arr[prev_i] != arr[i] ) {
			prev_i++;
			arr[prev_i] = arr[i]; // do assignment even with not need
			i++;
		} else if (arr[prev_i] == arr[i] ) {
			i++;
		}
	}
	return prev_i + 1;
}


int main() {
	//int arr[] = {2,3,5,5,7,11,11,11,13};
	int arr[] = {2,2};
	int size = sizeof(arr) /sizeof(int);

	int newSize= deleteDuplicate(arr,size);
	cout << newSize << endl;

	printArr(arr,newSize);

	return 0;
}