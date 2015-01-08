#include <iostream>

using namespace std;

int findNearestLessThan(int arr[], int i) {
	int found = -1;

	for (int k = i-1; k >= 0;k--) {
		if (arr[k] < arr[i]) {
			found = k;
			break;
		}
	}
	return found;
}

int findNearlestGreaterThan(int arr[], int i) {
	int found = -1;

	for (int k = i-1; k >= 0;k--) {
		if (arr[k] > arr[i]) {
			found = k;
			break;
		}
	}
	return found;
}

int maxBetween(int i, int j) {
	return (i > j) ? i : j;
}


int findArea(int * arr, int start, int end) {
	int height = INT_MAX;

	for (int i = start; i <= end; i++) {
		if (height > arr[i])
			height = arr[i];
	}

	return (height * abs(end -start + 1) );
}

int findMaxArea(int * arr, int n) {
	
	int longMax = arr[0];
	int shortMax = longMax;

	int currentMax = 0;

	int * tmpArea = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n;i++) 
		tmpArea[i] = 0;

	tmpArea[0] = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			int k = findNearestLessThan(arr,i-1);
			if (k == -1)  k = 0;

			int j = findNearlestGreaterThan(arr,i);
			if (j == -1) j = 0;
	
			if (j  < k)
				longMax = tmpArea[i - 1] + arr[k];
			else 
				longMax = tmpArea[i - 1] + arr[i-1];

			tmpArea[i] = maxBetween(longMax,arr[i]);
		}else if (arr[i] < arr[i-1]) {
			
			int k = findNearestLessThan(arr, i);
			if (k == -1)  k = 0;
			shortMax = findArea(arr,k,i);
			
			int j = findNearlestGreaterThan(arr,i);
			if (j == -1) j = 0;
			longMax = findArea(arr,j,i);
			
			tmpArea[i] = maxBetween(shortMax,longMax);
		}

	}

	for (int i = 0; i< n;i++) {
		currentMax = (tmpArea[i] > currentMax) ? tmpArea[i] : currentMax;
	}
	
	return currentMax;
}

int main() {
	//int arr[] = {3,5,3,1,7,4,5};
	int arr[] = {1,2,3,1,2,3};
	int num_blocks = sizeof(arr) / sizeof(int);

	int maxArea = findMaxArea(arr,num_blocks);

	cout << maxArea << endl;

	return 0;
}