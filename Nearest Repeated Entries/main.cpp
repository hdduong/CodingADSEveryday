#include <iostream>
#include <stdlib.h>
#include <utility> //pair
#include <unordered_map>// unordermap
using namespace std;

int findNearestEntry(char * arr[], int size, pair<int,int>& repeatIndex) {
	int minDistance = INT_MAX;

	unordered_map<char*,pair<int,int>> mapStr;

	for (int i = 0; i < size; i++) {
		unordered_map<char*,pair<int,int> >::iterator it = mapStr.find(arr[i]);
		if (it == mapStr.end()) { // not found
			pair<int,int> aPair = pair<int,int>(i,-1);
			mapStr.emplace(arr[i], aPair);

		} else {
			// found 2nd instance
			if (it->second.second == - 1) {
				it->second.second = i;
			} else { // found from 2nd instance
				if (it->second.second - it->second.first > i - it->second.second) {
					
					it->second.first = it->second.second;
					it->second.second = i;

					if (minDistance> it->second.second - it->second.first) {
						repeatIndex.first = it->second.first;
						repeatIndex.second = it->second.second;
						
						minDistance = repeatIndex.second - repeatIndex.first ;
					}

				}
			}

			
		}
	}
	return minDistance;
}

int main() {

	char * arr[] = {"All","work","and","no","play","makes","for","no","work","no","fun","and","no","results"};
	int size  = 14;
	
	pair<int,int> repeatIndex = make_pair<int,int>(INT_MAX,INT_MIN);
	
	int minDis = findNearestEntry(arr,size,repeatIndex);
	cout << minDis << endl;
	cout << repeatIndex.first << " " << repeatIndex.second << endl;



	return 0;
}