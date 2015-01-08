#include <iostream>

using namespace std;


int maxConSub(int * arr, int n, int * start, int * end) {
	int maxSum = 0;
	int tmpMax = 0;

	for (int i = 0; i < n;i++) {
		if ( (i == 0) || (*end  +1 == i ) )
			tmpMax = maxSum  + arr[i];
		else 
			tmpMax = arr[i];
		
		if (tmpMax > maxSum) {
			maxSum = tmpMax;
			*end = i;
			if (maxSum == arr[i]) {
				*start = i;
			}
		}

	}
	return maxSum;
}

void printArr(int * arr, int start, int end) {
	for (int i = start; i <= end;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {4,-9,5,6,1};
	int n = sizeof(arr)/ sizeof (int);

	int start = 0;
	int end = 0;

	int sum = maxConSub(arr, n, &start, &end);
	cout << sum << endl;
	printArr(arr,start,end);

	return 0;
}