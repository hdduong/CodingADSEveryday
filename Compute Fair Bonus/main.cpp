#include <iostream> 
#include <stdlib.h>
#include <queue>
#include <functional>

using namespace std;

// first: index
// second: value

class ComparePair {
public:
	bool operator() (pair<int, int> a, pair<int,int> b) {
		return (a.second > b.second);
	};
};
int * computeFair(int * arr, int size) {
	int * T = (int*)malloc(sizeof(int) * size);
	priority_queue<pair<int, int>, vector<pair<int,int> >, ComparePair> min_heap;

	for (int i = 0; i < size; i++) {
		T[i] = -1;
	}

	for (int i = 0; i < size; i++) {
		pair<int, int> p (i, arr[i]);
		min_heap.push(p);
	}

	while (!min_heap.empty()) {
		pair<int,int> topValue = min_heap.top();
		min_heap.pop();

		//cout << topValue.second << " ";
		int leftTop = topValue.first - 1;
		int rightTop = topValue.first + 1;

		leftTop = (leftTop >= 0) ? leftTop : -1;
		rightTop = (rightTop < size) ? rightTop: -1;

		if ( (leftTop != -1) && (rightTop != -1) ) { // not in border

			if ( ( T[leftTop] != -1) &&  (T[rightTop] != -1) ) { 
				int localMin = (T[leftTop] < T[rightTop]) ? T[leftTop] : T[rightTop];
			
				if (localMin != -1)
					T[topValue.first] = localMin + 1;
				else 
					T[topValue.first] = 1;
			} else {
				int neighborIndex = (T[leftTop] == -1 ? rightTop : leftTop); // rightTop = -1 means bigger element not fill in yet
				T[topValue.first] = T[neighborIndex] + 1;
			}
	
		} else if ( (leftTop == -1) && (rightTop != -1) ) { // left border
			
			if (T[rightTop] == -1) 
				T[topValue.first] = 1;
			else 
				T[topValue.first] = T[rightTop]  +1;

		} else if ( (leftTop != -1) && (rightTop == -1) ) { // right border
			
			if (T[leftTop] == -1) 
				T[topValue.first] = 1;
			else 
				T[topValue.first] = T[leftTop]  +1;

		
		} else if ( (leftTop == -1 ) && (rightTop == -1) ) { // only 1 element
			T[topValue.first] = 1;
		}
		
	}
	//cout << endl;

	return T;
}
int main() {
	
	int arr[] = {300,400,500,200};
	int size = sizeof(arr)/ sizeof(int);
	
	int * result = computeFair(arr,size);

	for (int i = 0; i < size;i++) {
		cout << result[i] << " " ;
	}
	cout << endl;
	free(result);
	return 0;
}