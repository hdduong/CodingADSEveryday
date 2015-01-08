#include <iostream>

using namespace std;

void maxSubArray(int arr[], int size, int * startIndex, int * endIndex) {
	int sum = arr[0];
	int prev_sum = 0;

	for (int i = 1; i < size; i++) {
		prev_sum = sum;
		sum = sum + arr[i];

		if (sum > prev_sum) {
			if (sum > arr[i]) {
				if (i == *endIndex + 1) {
					*endIndex = i;
				} else {
					if (arr[i] > prev_sum) {
						*startIndex = i;
						*endIndex = i;
						sum = arr[i];
					} else sum = sum - arr[i];
				}
			} else if (sum <= arr[i]) {
				*startIndex = i;
				*endIndex = i;
				sum = arr[i];
			
			}
			
		} else if (sum <= prev_sum){

			if (prev_sum < arr[i]) {
				*startIndex = i;
				*endIndex = i;
				sum = arr[i];
			}
			else sum = sum - arr[i];
		}
	
	
	}

}

int main() {
	//int arr[] = {904,40,523,12,-335,-385,-124,4381,-51};
	//int arr[] = {904,40,523,12,-335,-385,-124,481,-51};
	//int arr[] = {-100,-200};
	//int arr[] = {-2, -1};
	//int arr[] = {-2, -1, 1};
	int arr[] = {-1, -2, 1};
	int size = sizeof(arr)/ sizeof(int);

	int startIndex = 0;
	int endIndex = 0;

	maxSubArray(arr, size, &startIndex, &endIndex);
	cout << startIndex << " " << endIndex << endl;
	return 0;
}