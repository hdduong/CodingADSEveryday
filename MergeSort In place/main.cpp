#include <iostream>

using namespace std;

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = *a;
}


int getLastMeaning(int arr[], int size) {
	int first_end = 0;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] <  INT_MAX)
			first_end++;
		else break;
	}
	return first_end;
}

int getFirstMeaning(int arr[], int size) {

	int first_end = 0;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] ==  INT_MAX)
			first_end++;
		else break;
	}
	return first_end;

}
void moveToBack(int arr[], int size) {
	
	int first_end = getLastMeaning(arr,size);

	int last_end= 1;
	for (int i = first_end-1; i >= 0; i--) {
		arr[size-last_end] = arr[i];
		last_end++;
	}

	for (int i = 0; i < size-first_end;i++) {
		arr[i] = INT_MAX;
	}

}


void printArr(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<  " ";
	}
}

//assume A has enough place
void mergeSortInPlace(int arrA[], int sizeA, int arrB[], int sizeB) {
	moveToBack(arrA, sizeA);

	int aIndex = getFirstMeaning(arrA,sizeA); //cout << aIndex << endl;
	int bIndex = 0;
	int cIndex = 0;

	while ( (aIndex < sizeA) && (bIndex < sizeB) ) {

		if (arrA[aIndex] <= arrB[bIndex]) {
			arrA[cIndex++] = arrA[aIndex++];
			/*
			arrA[cIndex] = arrA[aIndex];
			aIndex++;
			*/
		} else if (arrA[aIndex] > arrB[bIndex] ) {
			arrA[cIndex++] = arrB[bIndex++];
			/*
			arrA[cIndex] = arrB[bIndex];
			bIndex++;
			*/
		}
		//cIndex++;
	}

	while(bIndex < sizeB-1) {
		arrA[cIndex++] = arrB[bIndex++];
	}
}

int main() {
	
	int arrA[] = {1,3,4,6,INT_MAX, INT_MAX, INT_MAX};
	int arrB[] =  {0,4,4};

	int sizeA = sizeof(arrA) / sizeof(int);
	int sizeB = sizeof(arrB)/ sizeof(int);

	mergeSortInPlace(arrA,sizeA,arrB,sizeB);
	printArr(arrA,sizeA); cout << endl;

	/*moveToBack(arrA,sizeA);
	printArr(arrA,sizeA); cout << endl;
	*/


	// int last_meaning_index = getLastMeaning(arrA, sizeA);
	// cout << last_meaning_index << endl;

	//for (int i = 0; i < 10; i++) cout << i << " ";
	//cout << endl;

	//for (int i = 0; i < 10; ++i) cout << i << " ";
	//cout << endl;

	return 0;
	

}