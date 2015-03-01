#include <iostream>
#include <time.h>

using namespace std;

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// left all elements < arr[k]
// right all elements > arr[k]
// correct position of arr[k]
int randomize_parition(int arr[], int startIndex, int endIndex, int k) {

	int i = startIndex-1; // i last element < k
	int j = startIndex;  // j between > and smaller

	swap(&arr[endIndex], &arr[k]);
	int pivot = arr[endIndex];

	while (j < endIndex) {
		 if (arr[j] < pivot) {
			i++;
			swap(&arr[i],&arr[j]);
		 }
		 j++;
	 }
	swap(&arr[++i], &arr[endIndex]);

	 return i;
}

void printArr(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<  " ";
	}
}

// note that first largest mean element at pos (n-1)
// second largest at (n-2)
// last largest at 0
int find_k_largest(int arr[], int startIndex, int endIndex, int kAtPos) {
	
	if (startIndex == endIndex) return arr[startIndex];

	int size = (endIndex - startIndex + 1);
	
	int randPos = rand() % size;
	randPos = startIndex + randPos;

	//cout << "randPos: "<< randPos << endl;

	int correctRandPos = randomize_parition(arr,startIndex,endIndex,randPos);

	if (kAtPos == correctRandPos)
		return arr[kAtPos];

	if (correctRandPos < kAtPos) {
		return find_k_largest(arr,correctRandPos + 1, endIndex, kAtPos); // 0 based

	} else if (correctRandPos > kAtPos) {
		return find_k_largest(arr,startIndex, correctRandPos-1,kAtPos );
	}

}
int main() {
	srand(time(NULL));

	int arr[] = {3,2,1,5,4};
	int size = sizeof(arr)/sizeof(int);
	
	//int k = 0;
	//int k = 1;
	//int k = 3;
	//int k = 4;
	//int kAtPos = randomize_parition(arr,0,size-1,3);
	//cout << kAtPos << ":" << arr[kAtPos] << endl;

	int kLargest = 4;
	int kAtPos = size - kLargest;
	int kLargestValue = find_k_largest(arr,0, size-1,kAtPos);

	cout << kLargestValue << endl;

	printArr(arr,size);

	cout << endl;
}