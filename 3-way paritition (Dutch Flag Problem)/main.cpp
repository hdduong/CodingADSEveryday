#include <iostream>

using namespace std;

void swapElement(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// smallerIndex points to last
// equalIndex points to first
// biggerIndex points to first

void threeWayPartition(int * arr, int size, int j) {
	int k = arr[j];
	int smallerIndex = -1;
	int equalIndex = -1;
	int biggerIndex = -1;

	for (int i = 0; i < size; i++) {
		if (arr[i] < k) {
			if (smallerIndex == -1) 
				smallerIndex = i;
			
			bool beforeEqual = false;
			bool beforeBigger = false;

			int ri = -1;

			// to see with biggerIndex
			if ((biggerIndex != -1) &&  (i > biggerIndex ))  {
				ri = biggerIndex;
				smallerIndex = biggerIndex;
				swapElement(&arr[i], &arr[biggerIndex]);
			
				biggerIndex++;
				beforeBigger = true;
			}

			ri = (ri == -1) ? i : ri;

			// to see with equalIndex
			if ((equalIndex != -1) &&  (ri > equalIndex ))  {
				smallerIndex = equalIndex;
				swapElement(&arr[ri], &arr[equalIndex]);
				
				equalIndex++;
				beforeEqual = true;
			}
			if ((!beforeBigger) && (!beforeEqual)) smallerIndex++;
		} else if (arr[i] == k)  {

			if (equalIndex == -1) equalIndex = i;

			// to see with biggerIndex
			if ((biggerIndex != -1) &&  (i > biggerIndex ))  {
				equalIndex = biggerIndex;
				swapElement(&arr[i], &arr[biggerIndex]);
				biggerIndex++;
			}
		} else if (arr[i] > k) {

			if (biggerIndex == -1) biggerIndex = i;
		}
	}
}

void printArr(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr[] = {1,2,4,3,6,3,0,5,4};
	int size  = sizeof(arr)/ sizeof(int);

	printArr(arr,size);
	cout << endl;

	threeWayPartition(arr,size,2);

	printArr(arr,size);
	cout << endl;
	return 0;
}