#include <iostream> 

using namespace std;

int binarySearch(int * arr, int first, int last, int k) {
	
	while (first <= last) {
		try {
			int middle = first + (last - first) /2;

			if (arr[middle] == k) {
				return middle;
			}
			else if (arr[middle] > k) {
				last = middle - 1;

			} else if (arr[middle] < k) {
				first = middle + 1;

			}
		} catch (exception e) { //exception with middle
			last = first + (last - first) /2 - 1;
		}
	}

	return - 1;
}

int findIndex(int * arr, int k) {
	int first = 0;
	int last = 1;

	bool exceptionOccur = false;

	if (arr[first] == k) return first;
	if (arr[last] == k) return last;
	if (arr[last] > k) return -1;

	while(!exceptionOccur) {
		
		try {
			while (arr[last] < k) {
				first = last;
				last = last * 2;
			}
		} 
		catch (exception e) {
			exceptionOccur = true;
		}

		break;
	}

	//if (!exceptionOccur)  { // arr[last] > k
		return binarySearch(arr,first, last, k);
	//}

	return -1;

}

int main() {
	int arr[] = {2,3,3,5,7,7,7,8,9};
	int index = findIndex(arr, 7);
	cout << index << endl;
}