#include <iostream>

using namespace std;

int getMaxDiff(int * arr, int size, int *i, int *j) {
	int currMaxValue = arr[0];
	int tmpMinValue = arr[0];
	
	int currMinValue = arr[0];

	int currMax = 0;
	int tmpMinI = 0;
	int currI = 0;
	int currJ = 0;

	for (int i = 1; i < size;i++) {
		if (arr[i] < tmpMinValue) {
			tmpMinValue = arr[i];	
			tmpMinI = i;
			
		} else if (arr[i] > currMaxValue) {
			
			if ( ( arr[i] - tmpMinValue) > currMax) {
				currMax = arr[i] - tmpMinValue;
				currMaxValue = arr[i];
				currMinValue = tmpMinValue;
				
				currI = tmpMinI;
				currJ = i;
			}

		}
	}
	*i = currI;
	*j = currJ;

	return currMax;
}


int main() {
	//int arr[] = {2,3,10,6, 4, 8 ,1};
	//int arr[] = {5, 2,3,10,6, 4, 8 ,1};
	//int arr[] = {2,3,10,6, 4, 8 ,1, 20};
	int arr[] = {7,9,5,6,3,2};
	
	int size = sizeof(arr) /sizeof(int);

	int i,j = 0;
	int maxDiff = getMaxDiff(arr,size, &i, &j);

	cout << maxDiff << " " << i << " "<< j << endl;

	return 0;
}