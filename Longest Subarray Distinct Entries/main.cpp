#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void resetMap(unordered_map<int,int>& mArr) {
	for (unordered_map<int,int>::iterator it = mArr.begin(); it != mArr.end(); it++) {
		it->second = -1;
	}
}
void findMaxDistinct(int arr[], int size, int& from, int& to) {
	unordered_map<int ,int> mArr;

	int overCountMax = 0;
	int currCountMax = 0;
	int currFrom = -1;

	int index = 0;
	while (index < size) {
		unordered_map<int,int>::iterator itFind = mArr.find(arr[index]);
		if ( (itFind != mArr.end()) && (itFind->second != -1)) {
			index = itFind->second + 1;

			if (overCountMax < currCountMax) {
				from = currFrom;
				overCountMax = currCountMax;
				
			}
			// reset
			currCountMax = 0;
			resetMap(mArr);

		} else {
			if (itFind == mArr.end())
				mArr.emplace(arr[index],index);
			else 
				itFind->second = index;
			
			if (currCountMax == 0) {
				currFrom = index;
			}
			index++;
			currCountMax++;
		}
	}

	if (currCountMax > overCountMax) {
		overCountMax = currCountMax; 
		from = currFrom;
	}
	to = from + overCountMax - 1;
}

int main() {

	//int arr[] = {5,7,5,11,13,2,11,19,2,11};
	int arr[] = {5,7,5,11,13,2,11,19,2,11,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(int);

	int from = -1; int to = -1;
	findMaxDistinct(arr, size, from, to) ;

	cout << from << " " << to << endl;

	return 0;
}