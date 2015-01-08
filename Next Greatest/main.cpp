#include <iostream>

using namespace std;

int max(int i, int j) {
	return (i > j) ? i: j;
}

void printArr(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<  " ";
	}
}
int* replaceNextGreatest(int arr[], int n) {
	int * newArr = (int*)malloc(sizeof(int) * n);

	newArr[n-1] = INT_MIN;
	int current_max = arr[n-1];

	for (int i = n-2; i >=0 ;i--)  {
		newArr[i] = current_max;
		current_max = max(arr[i],current_max);
	}
	return newArr;

}

int main() {
	int arr[] = {0,2,8,1,3,5,4};
	int n = sizeof (arr)/sizeof(int);

	int * newArr = replaceNextGreatest(arr,n);
	printArr(newArr,n);

	cout << endl;
	return 0;
}