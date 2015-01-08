#include <iostream>

using namespace std;

int searchFirst(int arr[], int size, int k) {
	int lastMiddle = -1;
	int start = 0;
	int last = size -1;
	
	while (start <= last) {
		int middle = start + (last - start) / 2;

		if (arr[middle] == k) {
			lastMiddle = middle;
			
			if ( (middle > 0) && (arr[middle-1] < k) ) break;
			
			last = middle - 1;

		} else if (arr[middle] < k) {
			start = middle + 1;

		} else if (arr[middle] > k) {
			last = middle - 1;
		}
	}
	return lastMiddle;
}

int main() {
	
	//int arr[] = {-14,-10,2,108,108,243,285,285,285,401};
	int arr[] = {1,1,1,1};
	int size = sizeof (arr) / sizeof(int);


	int firstIndex = searchFirst(arr,size,1);
	cout << firstIndex << endl;
	return 0;
}