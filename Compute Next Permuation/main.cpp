#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> vVisit) {
	for (vector<int>::iterator it = vVisit.begin(); it != vVisit.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}



void computeNextPermutation(vector<int> & v) {
	
	int iItem = v.size()-1;
	int jItem = v.size()-1;
	
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		if ( (it + 1 != v.rend()) && (*it) > (*(it + 1) ) ) {
			iItem--;
			break;
		}
		else iItem--;
	}

	if (iItem < 0) { 
		cout << "No more Next Permutation" << endl;
		return;
	}

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		if ( (*it) > (v.at(iItem) ) ) {
			break;
		} else 	jItem--;
	}

	swap(v.at(iItem),v.at(jItem) );

	sort(v.begin() + jItem, v.end());
}

int main() {

	//int arr[]  =  {1,0,3,2};
	//int arr[]  =  {4,3,2,1};
	//int arr[]  =  {3,4,2,1};
	int arr[]  =  {1,2,3,4};

	int size = sizeof(arr)/sizeof(int);

	vector<int> v (arr,arr + size);

	computeNextPermutation(v);

	printVector(v);

	return 0;

}