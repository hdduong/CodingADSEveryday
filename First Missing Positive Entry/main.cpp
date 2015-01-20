#include <iostream> 

using namespace std;

int findFirstPositive(int * arr, int size) {
	
	int * count = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		if ( (arr[i] > 0) && (arr[i] <= size-1)) {
			count[arr[i]] = 1;
		}
	}

	for (int i = 1; i < size; i++) {
		if (count[i] == 0) 
			return i;
	}
	free (count);

	return size;
}

int main() {
	//int arr[] = {1,2,0};
	 int arr[] = {3,4,-1,1};

	int size = sizeof(arr)/ sizeof (int);
	
	int number  = findFirstPositive(arr,size);
	cout << number << endl;

	return 0;
}