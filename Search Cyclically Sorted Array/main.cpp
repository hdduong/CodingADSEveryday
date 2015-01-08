#include <iostream>

using namespace std;

int findCycle(int arr[], int size) {
	
	int start = 0; int end = size-1; int res = -1;
	
	
	

	while (start <= end) {
		if (start == end) {
			res = start;
			break;
		}

		if (start == (end - 1)) {
			if (arr[start] < arr[end]) res = start;
			else res = end;
			
			break;
		}

		int middle = start + (end - start) /2 ;
		if ( (arr[middle-1] > arr[middle]) && (arr[middle] < arr[middle + 1]) ) { 
			res = middle; break; 
		}

		if ( (arr[middle-1] < arr[middle]) && (arr[middle] > arr[middle + 1]) ) { 
			res = middle + 1; break; 
		}

		if ( (arr[middle] > arr[start] ) && (arr[middle] < arr[end] ) ) {
			res = start; break;
		}

		if ( (arr[middle-1] < arr[middle]) && (arr[middle] < arr[middle + 1]) ) { 
			if (arr[middle] < arr[end]) {
				end = middle -1;
			} else {
				start = middle + 1;
			}
		}

	}
	return res;
}

int main() {
	
	//int arr[] = {378,478,550,631,103,203,220,234,279,368};
	//int arr[] = {2,3,4,5,1};
	//int arr[] = {1,2,3,4,5};
	int arr[] = {3,4,5,1,2};
	int size = sizeof(arr) /sizeof (int);

	int res = findCycle(arr,size);
	cout << res <<  " " << arr[res] << endl;
	return 0;

}