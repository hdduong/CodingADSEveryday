#include <iostream> 
#include <stdlib.h> 
#include <queue>
#include <vector>
#include <functional>

using namespace std;

// pair (index, value> 
bool maxHeapCompare(pair<int, int> a, pair<int,int> b) {
	return (a.second < b.second);
}

void findKLargest(int * arr , int size, int k) {
	priority_queue<pair<int,int>, vector<pair<int,int> >, function<bool(pair<int,int>, pair<int,int>)>> max_k_heap(maxHeapCompare);

	int value = arr[0];
	max_k_heap.push(pair<int,int>(0,arr[0]) ); // index at 0 is max. Not do make_pair

	while (!max_k_heap.empty() && k > 0) {
		pair<int, int> top = max_k_heap.top();

		max_k_heap.pop();
		cout << arr[top.first] << " " ;
		k--;

		if (2 * top.first + 1 < size) {
			pair<int,int> leftChild = pair<int,int> (2 * top.first + 1, arr[2*top.first + 1] );
			max_k_heap.push(leftChild);
		}
		if (2 * top.first + 2 < size) {
			pair<int,int> rightChild = pair<int,int> (2 * top.first + 2, arr[2*top.first + 2] );
			max_k_heap.push(rightChild);
		}

	}
	

	cout << endl;
}

int main() {
	
	// max-heap
	int arr[] = {11,9,4,7,8,3,1,2,5,6};
	int size = sizeof(arr) /sizeof(int);

	int k = 5;

	findKLargest(arr,size,k);

	return 0;
}