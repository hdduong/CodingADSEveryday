#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class PotentialCompare {
public:
	PotentialCompare(int *arr) {
		_originArr = arr;
	}
	bool operator() (int &lhs, int &rhs) {
		return (_originArr[lhs] < _originArr[rhs]);
	}
private:
	int * _originArr;
};

int getLeftChild (int parentIndex, int size) {
	if ( parentIndex * 2 + 1 < size-1)
		return parentIndex * 2 + 1;
	return -1;
}


int getRightChild (int parentIndex, int size) {
	if ( parentIndex * 2 + 2 < size-1)
		return parentIndex * 2 + 2;
	return -1;
}


int getKLargest(int * origArr, int size, int kLargest, int *arrK, priority_queue<int,vector<int>, PotentialCompare> & potenialHeap) {
	int examined = 0;

	arrK[examined] = 0; // first is max element for sure;

	while(examined < kLargest) {
		int atParentIndex = arrK[examined];
		int leftChildIndex = getLeftChild(atParentIndex,size);
		int rightChildIndex = getRightChild(atParentIndex,size);

		// following method with time complexity at most O(log(constant * k).)
		if (leftChildIndex != -1)
			potenialHeap.emplace(leftChildIndex);

		if (rightChildIndex != -1)
			potenialHeap.emplace(rightChildIndex);

		int nextIndex = potenialHeap.top();
		potenialHeap.pop();

		arrK[++examined] = nextIndex;
	}

	return origArr[arrK[--examined]];
}


int main() {
	
	//int origArr[] = {29,9,14,7,2,10,11,3,4};
	int origArr[] = {77,11,62,10,4,48,2,7,8,1,2,3,33,-5,1};
	int size = sizeof(origArr)/sizeof(int);


	int kLargest = 3;

	int *arrK = (int *)malloc(sizeof(int) * kLargest); // store examined elements
	
	PotentialCompare pCompare(origArr);
	priority_queue<int, vector<int>, PotentialCompare> potenialHeap(pCompare); // store potential elements. Size will be constant * k
	
	int kValue = getKLargest(origArr,size,kLargest,arrK,potenialHeap);
	cout << kValue << endl;

	return 0;
}
