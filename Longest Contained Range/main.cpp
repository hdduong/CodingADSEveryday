#include <iostream>
#include <unordered_map>

using namespace std;


void findMinMax(int arr[], int size, int& maxValue, int& minvalue) {
	maxValue = INT_MIN;
	minvalue = INT_MAX;

	for (int i = 0; i < size; i++) {
		if (arr[i] > maxValue)
			maxValue = arr[i];
		if (arr[i] < minvalue)
			minvalue = arr[i];
	}
}

int findLongestRange(int arr[], int size) {
	int maxRange = 0;
	int minValue = INT_MAX;
	int maxValue = INT_MIN;
	int currLen = 0;
	int maxLen = 0;

	findMinMax(arr,size,maxValue,minValue);

	unordered_map<int, int> mArr;
	for (int i = 0; i < size;i++) {
		mArr.emplace(arr[i],i);
	}

	for (int i = minValue; i <= maxValue; i++) {
		unordered_map<int,int>::iterator itFound = mArr.find(i);
		if (itFound == mArr.end()) {
			if (currLen > maxLen) {
				maxLen = currLen;
			}
			currLen = 0;
		} else {
			currLen++;
		}

	}

	maxLen = (currLen > maxLen) ? currLen : maxLen;

	return maxLen;
}
int main() {
	
	int arr[] = {3,-2,7,9,8,1,2,0};
	int size = sizeof(arr)/sizeof(int);

	int longestRange = findLongestRange(arr,size);
	cout << longestRange << endl;

	return 0;
}