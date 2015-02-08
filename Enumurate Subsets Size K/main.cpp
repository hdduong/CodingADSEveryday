
#include <iostream> 
#include <vector>

using namespace std;

void printVector(vector<int> vVisit) {
	for (vector<int>::iterator it = vVisit.begin(); it != vVisit.end(); it++) {
		cout << *it << " ";
	}
}

// number of elements in subset
void getSubSetHelper(int arr[], int n, int requiredSize, int k, int currentIndex, vector<int>& result) {
	if (result.size() == requiredSize) {
		printVector(result);
		cout << endl;
		return;
	}

	for (int i = currentIndex + 1; i < n;i++) {
		result.emplace_back(arr[i]);
		getSubSetHelper(arr,n,requiredSize,k-1,i,result);
		result.pop_back();
	}


}
void getSubSet(int arr[], int n, int k) {
	vector<int> result;
	
	for (int i = 0; i < n - k + 1; i++) {
		result.push_back(arr[i]);
		getSubSetHelper(arr,n,k,k-1,i,result);
		result.pop_back();
	}
}

int main() {
	int n = 5;
	int k = 2;

	int arr[] = {1,2,3,4,5};
	getSubSet(arr,n,k);
	cout << endl;
}

