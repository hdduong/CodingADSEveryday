#include <iostream>
#include <queue>

using namespace std;

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// left all elements < arr[k]
// right all elements > arr[k]
// correct position of arr[k]
int randomize_parition(int arr[], int startIndex, int endIndex, int k, int commonValue) {

	int i = startIndex-1; // i last element < k
	int j = startIndex;  // j between > and smaller

	swap(&arr[endIndex], &arr[k]);
	int pivot = abs(arr[endIndex] - commonValue);

	while (j < endIndex) {
		if (abs(arr[j] - commonValue) < pivot) {
			i++;
			swap(&arr[i],&arr[j]);
		 }
		 j++;
	 }
	swap(&arr[++i], &arr[endIndex]);

	 return i;
}

void printArr(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<  " ";
	}
	cout << endl;
}


void printArr(int * arr, int n, int untilK) {
	for (int i = 0; i < untilK; i++) {
		cout << arr[i] <<  " ";
	}
	cout << endl;
}


// note that first largest mean element at pos (n-1)
// second largest at (n-2)
// last largest at 0
int find_k_largest(int arr[], int startIndex, int endIndex, int kAtPos, int commonValue) {
	
	if (startIndex == endIndex) return arr[startIndex];

	int size = (endIndex - startIndex + 1);
	
	int randPos = rand() % size;
	randPos = startIndex + randPos;

	int correctRandPos = randomize_parition(arr,startIndex,endIndex,randPos,commonValue);

	if (kAtPos == correctRandPos)
		return arr[kAtPos];

	if (correctRandPos < kAtPos) {
		return find_k_largest(arr,correctRandPos + 1, endIndex, kAtPos,commonValue); // 0 based

	} else if (correctRandPos > kAtPos) {
		return find_k_largest(arr,startIndex, correctRandPos-1,kAtPos,commonValue );
	}

}

// reuse Selection Algorithm
void findKClosetSol1(int arr[], int startIndex, int endIndex, int kCloset) {
	int size = endIndex - startIndex + 1;
	int medianCommonValue = 0;
	int medianPos = size / 2;

	int medianPosValue = find_k_largest(arr,startIndex,endIndex,medianPos,medianCommonValue);
	cout << "Median Value: " << medianPosValue << endl;
	printArr(arr,size); cout << endl;
	
	int kClosetValue = find_k_largest(arr,startIndex,endIndex,medianPos,medianPosValue);
	cout << "Farthest in K-Closet:" << kClosetValue << endl;
	printArr(arr,size,kCloset);
	
}

class MyMedianCompare{
public:
	explicit MyMedianCompare(int value) : common(value) {
		//common = value;
	}
	bool operator() (int lhs, int rhs) {
		return  abs(lhs - common) < abs(rhs - common);
	}
private: 
	int common;
};

void printQueue(priority_queue<int, vector<int>, MyMedianCompare>  medianHeap) {
	while(!medianHeap.empty()) {
		cout << medianHeap.top() << " ";
		medianHeap.pop();
	}
	cout << endl;
}

// use heap
void findKClosetSol2(int arr[], int startIndex, int endIndex, int kCloset) {

	int size = endIndex - startIndex + 1;
	int medianCommonValue = 0;
	int medianPos = size / 2;
	
	int medianPosValue = find_k_largest(arr,startIndex,endIndex,medianPos,medianCommonValue);
	cout << "Median Value: " << medianPosValue << endl;
	printArr(arr,size); cout << endl;
	
	MyMedianCompare myMedianCompareObj(medianPosValue);
	priority_queue<int, vector<int>, MyMedianCompare>  medianHeap(myMedianCompareObj);

	for (int i = 0; i < kCloset; i++) {
		medianHeap.emplace(arr[i]);
	}

	printQueue(medianHeap);

	for (int i = kCloset; i <= endIndex; i++) {

		if (abs(arr[i] - medianPosValue) < abs(medianHeap.top()- medianPosValue)) {
	
			medianHeap.pop();
			medianHeap.emplace(arr[i]);
		}
	}

	printQueue(medianHeap);

}

int main() {
	
	int arr[] = {7,14,10,12,2,11,29,3,4};
	int size = sizeof(arr)/sizeof(int);

	int startIndex = 0;
	int endIndex = size - 1;

	int kCloset = 5;
	//findKClosetSol1(arr,startIndex,endIndex, kCloset);
	findKClosetSol2(arr,startIndex,endIndex, kCloset);

	return 0;
}