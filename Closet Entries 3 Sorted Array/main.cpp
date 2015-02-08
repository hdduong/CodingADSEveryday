#include <iostream> 

using namespace std;

int getMinIndex(int arr[2]) {
	int minIndex = -1;

	minIndex = (arr[0] < arr[1]) ? 0 : 1;
	minIndex = (arr[2] < arr[minIndex]) ? 2 : minIndex;

	return minIndex;
}

int getMinValue (int arr[2]) {
	int minIndex = getMinIndex(arr);

	return arr[minIndex];
}


int getMaxIndex(int arr[2]) {
	int maxIndex = -1;

	maxIndex = (arr[0] > arr[1]) ? 0 : 1;
	maxIndex = (arr[2] > arr[maxIndex]) ? 2 : maxIndex;

	return maxIndex;
}

int getMaxValue (int arr[2]) {
	int maxIndex = getMaxIndex(arr);

	return arr[maxIndex];
}

int getMinOfMaxDistance(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3, 
						int &firstIndex, int &secondIndex, int &thirdIndex) {
	int i = 0;
	int j = 0;
	int k = 0;

	int min = INT_MAX;
	
	int minAtArr;
	int currMinValue;
	int currMaxValue;

	int arrMin[3];
	arrMin[0] = arr1[i];
	arrMin[1] = arr2[j];
	arrMin[2] = arr3[k];
	minAtArr = getMinIndex(arrMin);
	currMinValue = getMinValue(arrMin);
	
	int arrMax[3];
	arrMax[0] = arr1[i];
	arrMax[1] = arr2[j];
	arrMax[2] = arr3[k];
	currMaxValue = getMaxValue(arrMax);

	bool fromArr1 = true;
	bool fromArr2 = true;
	bool fromArr3 = true;

	while ( fromArr1 && fromArr2 && fromArr3 ) {
		
		// set
		if (min > abs((currMaxValue - currMinValue))) {
			min = abs(currMaxValue - currMinValue);
			firstIndex = i;
			secondIndex = j;
			thirdIndex = k;
		}			

		if (minAtArr == 0) {
			if (i == size1 - 1) fromArr1 = false;
			else i = i + 1;
			
		} else if (minAtArr == 1) {
			if (j == size2 - 1) fromArr2 = false;
			else j = j + 1;
			
		} else if (minAtArr == 2) {
			if (k == size3 - 1) fromArr3 = false;
			else k = k + 1;
		}
		
		if (!fromArr1) {
			arrMin[0] = arr1[size1-1];
			arrMax[0] = INT_MIN;
		} else {
			arrMin[0] = arr1[i];
			arrMax[0] = arr1[i];
		}

		if (!fromArr2) {
			arrMin[1] = arr2[size2-1];
			arrMax[1] = INT_MIN;
		}else {
			arrMin[1] = arr2[j];
			arrMax[1] = arr2[j];
		}

		if (!fromArr3) {
			arrMin[2] = INT_MAX;
			arrMax[2] = INT_MIN;
		} else {
			arrMin[2] = arr3[k];
			arrMax[2] = arr3[k];
		}

		currMinValue = getMinValue(arrMin);
		currMaxValue = getMaxValue(arrMax);

		minAtArr = getMinIndex(arrMin);
	
	}

	return min;
}


int main() {
	int arr1[] = {3, 4, 9};
	int arr2[] = {1,3,7,8};
	int arr3[] = {2,6};

	int size1 = sizeof(arr1) /sizeof (int);
	int size2 = sizeof(arr2) /sizeof (int);
	int size3 = sizeof(arr3) /sizeof (int);

	int firstIndex = -1;
	int secondIndex = -1;
	int thirdIndex = -1;
	
	int value = getMinOfMaxDistance(arr1,size1,arr2,size2,arr3,size3,firstIndex,secondIndex, thirdIndex);
	
	cout << value << endl;
	cout << "at index: " << firstIndex << " " << secondIndex << " " << thirdIndex << endl;
	return 0;
}