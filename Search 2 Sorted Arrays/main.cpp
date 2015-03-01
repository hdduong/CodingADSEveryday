#include <iostream>
#include <stdlib.h>

using namespace std;

void printArr(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<  " ";
	}
}

// get index that arr[index] <= pivot
int getLowerIndex(int * arr, int startArr, int endArr, int pivot) {
	int mainMiddle = -1;

	if ( (arr[startArr] > pivot) || (arr[endArr] < pivot) ) return -1;

	while (startArr <= endArr) {
		int middle = (startArr + endArr) /2;


		if (arr[middle] <= pivot) {
			if (mainMiddle <= middle) mainMiddle = middle;
			startArr = middle + 1;
		}else if (arr[middle] > pivot ) {
			endArr = middle - 1;
		}
	}	

	return mainMiddle;
}



int getNumberK(int * firstArr, int startFirst, int endFirst, int * secondArr, int startSecond, int endSecond, int& k) {

	if (k == 1) {
		return (firstArr[startFirst] <= secondArr[startSecond] ) ? firstArr[startFirst] : secondArr[startSecond];
	}

	int actualStartFirst = 0;
	int actualStartSecond = 0;
	int actualEndFirst = 0;
	int actualEndSecond = 0;

	if (endFirst - startFirst + 1 < k) {
		actualStartFirst = startFirst;
		actualEndFirst = endFirst;
	} else {
		actualStartFirst = startFirst;
		actualEndFirst = actualStartFirst + k-1;
	}

	if (endSecond - startSecond + 1 < k) {
		actualStartSecond = startSecond;
		actualEndSecond = endSecond;
	} else {
		actualStartSecond = startSecond;
		actualEndSecond = actualStartSecond + k-1;
	}

	// Run array to get Pivot element
	int startLookupArray = 0;
	int endLookupArray = 0;
	int startRunArray = 0;
	int endRunArray = 0;
	int isRunFirst = false; 

	if (firstArr[actualEndFirst] < secondArr[actualEndSecond] ) {
		isRunFirst = true;
		startRunArray = actualStartFirst;
		endRunArray = actualEndFirst;
		startLookupArray = actualStartSecond;
		endLookupArray = actualEndSecond;
	} else {
		isRunFirst = false;
		startRunArray = actualStartSecond;
		endRunArray = actualEndSecond;
		startLookupArray = actualStartFirst;
		endLookupArray = actualEndFirst;
	}

	int pivotElement = INT_MIN;
	int pivotIndex = (startRunArray + endRunArray)/2;
	if (isRunFirst) {
		pivotElement = firstArr[pivotIndex];
		 int upperIndex = getLowerIndex(secondArr,startLookupArray, endLookupArray,pivotElement);
		 if (upperIndex == -1) {
			 if (pivotElement > secondArr[endLookupArray]) {
				 if (k <= (endLookupArray - startLookupArray + 1) ) {
					return secondArr[startLookupArray + k-1];
				 }
				 else {
					 return firstArr[startRunArray + k - (endLookupArray - startLookupArray  +1)];
				 }
			 } else if (pivotElement < secondArr[startLookupArray]) {
				 if (k < (endRunArray - startRunArray + 1) ) {
					 return firstArr[startRunArray + k-1];
				 }
				 else {
					 return secondArr[startLookupArray + k - (endRunArray - startRunArray  +1)];
				 }
			 }
		 } else {
			 if (pivotIndex - startRunArray + 1 + upperIndex - startLookupArray + 1 > k) {
				 k = pivotIndex - startRunArray + 1 + upperIndex - startLookupArray + 1 - k;
				 return getNumberK(firstArr,startRunArray + 1,pivotIndex,secondArr,startLookupArray + 1,upperIndex,k);
			 } else if (pivotIndex - startRunArray + 1 + upperIndex - startLookupArray + 1 == k) {
				 return (firstArr[pivotIndex] >= secondArr[upperIndex]) ? firstArr[pivotIndex] : secondArr[upperIndex];
			 } else if (pivotIndex - startRunArray + 1 + upperIndex - startLookupArray + 1 < k) {
				 k = k - (pivotIndex - startRunArray + 1 + upperIndex - startLookupArray + 1);
				 return getNumberK(firstArr,pivotIndex + 1,endRunArray,secondArr,upperIndex + 1,endLookupArray, k );
			 }
		 }


	} else {
		pivotElement = secondArr[pivotIndex];

		int upperIndex = getLowerIndex(firstArr,startLookupArray, endLookupArray,pivotElement);
		 if (upperIndex == -1) {
			 if (pivotElement > firstArr[endLookupArray]) {
				 if (k <= (endLookupArray - startLookupArray + 1) ) {
					 return firstArr[startLookupArray + k-1];
				 }
				 else {
					 return secondArr[startRunArray + k - (endLookupArray - startLookupArray  +1)];
				 }
			 } else if (pivotElement < firstArr[startLookupArray]) {
				 if (k < (endRunArray - startRunArray + 1) ) {
					 return secondArr[startRunArray  + k-1];
				 }
				 else {
					 return firstArr[startLookupArray + k - (endRunArray - startRunArray  +1)];
				 }
			 }
		 } else {
			 if (pivotIndex -startRunArray + 1 + upperIndex - startLookupArray + 1 > k) {
				 k = pivotIndex -startRunArray + 1 + upperIndex - startLookupArray - k;
				 return getNumberK(secondArr,startRunArray + 1,pivotIndex,firstArr,startLookupArray + 1,upperIndex,k);
			 } else if (pivotIndex -startRunArray + 1 + upperIndex - startLookupArray == k) {
				 return (secondArr[pivotIndex] >= firstArr[upperIndex]) ? secondArr[pivotIndex] : firstArr[upperIndex];
			 } else if (pivotIndex -startRunArray + 1 + upperIndex - startLookupArray + 1 < k) {
				 k = k - (pivotIndex -startRunArray + 1 + upperIndex - startLookupArray + 1);
				 return getNumberK(secondArr,pivotIndex + 1,endRunArray,firstArr,upperIndex+1, endLookupArray, k );
			 }
		 }

	}

	return -1;

}

int main() {
	
	int firstArr[] = {2,3,4,9,14,20,24,28};
	//int secondArr[] = {1,3,7};
	int secondArr[] = {1,3,30};
	//int k = 6;
	int k = 5;

	int firstSize = sizeof(firstArr)/sizeof(int);
	int secondSize = sizeof(secondArr)/ sizeof(int);

	int start = 0;
	int value = getNumberK(firstArr,start,firstSize - 1, secondArr,start,secondSize -1,k);
	cout << value << endl;

	return 0;

}