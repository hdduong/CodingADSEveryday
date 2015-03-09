#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map> 

using namespace std;


int  findNextMin(unordered_map<string,int>& mapQ, string notEqual) {
	int minAt = INT_MAX;

	for (unordered_map<string,int>::iterator it = mapQ.begin(); it != mapQ.end(); it++) {
		if (( minAt  > it->second) && (notEqual!= it->first) ) minAt = it->second;
	}

	return minAt;
}


bool  seeAllElement(unordered_map<string,int>& mapQ) {
	
	for (unordered_map<string,int>::iterator it = mapQ.begin(); it != mapQ.end(); it++) {
		if ( it->second == - 1) return false;
	}

	return true;
}


void GetMinMaxIndex(unordered_map<string,int>& mapQ, int& minIndex, int& maxIndex) {
	minIndex = INT_MAX;
	maxIndex = INT_MIN;

	for (unordered_map<string,int>::iterator it = mapQ.begin(); it != mapQ.end(); it++) {
		if (minIndex > it->second) minIndex = it->second;
		if (maxIndex < it->second) maxIndex = it->second;
	}
	
}

// Q is small array
int findSmallestSubString(vector<string>& A, vector<string>& Q) {
	unordered_map<string, int> mapQ;
	
	vector<string>::iterator left = A.end();
	vector<string>::iterator right = A.end();

	int currentCount = 0;
	
	int minLen = INT_MAX;
	

	for (vector<string>::iterator itQ = Q.begin(); itQ!=Q.end(); itQ++) {
		mapQ.emplace(*itQ,-1);
	}
	
	for (vector<string>::iterator itA = A.begin(); itA!=A.end(); itA++) {
		
		unordered_map<string, int>::iterator itMapQ = mapQ.find(*itA);
		
		if (itMapQ != mapQ.end()) { // found in A
			
			
			if (left == A.end()) left = itA;
			right = itA;
			
			if (itMapQ->second == -1) { // first time see this instance
				itMapQ->second = itA - A.begin();
				currentCount ++;

				if (currentCount == Q.size()) { // first time see all items
					if (minLen > right - left) {
						minLen = right-left;
					}
				}

			} else { // not first time see this instance and not 
				
				

				if (currentCount  < Q.size()) { 
					if (seeAllElement(mapQ)) currentCount++;
					
					if (currentCount == Q.size()) { // this elment last element form new group
						currentCount = 1;
						
						if (itMapQ->first == *left) {
							itMapQ->second = itA - A.begin();
							int nextEleIdx = findNextMin(mapQ, *left);

							if (minLen > (itA - A.begin()) - nextEleIdx )
								minLen = itA - A.begin() - nextEleIdx;
						} else {
							
						}
					} else {
						if (*itA == *left) {
							if (!seeAllElement(mapQ)) left = itA;
							else left = findNextMin(mapQ, *left) + A.begin();
							itMapQ ->second = itA - A.begin();
						} else {						
							itMapQ ->second = itA - A.begin();
						}
					}
				} else { // see again an element in full

	
					if (currentCount == Q.size())  {
						currentCount = 1;
						if (minLen > right - left) {
							minLen = right-left;
						}
	
					} else {
						currentCount++;
					}
					right = itA;

					if (itMapQ->first == *left) {
						int nextEleIdx = findNextMin(mapQ,*left);
						left = A.begin() + nextEleIdx;
						itMapQ->second = itA - A.begin();
					} else {
						itMapQ->second = itA - A.begin();
					}
				}
			}

		}
	}

	return minLen;
}

// the idea is keep track last Element.
// okie to loop to find Min and Max Index

int FindSmallestSubString2(vector<string> vA, vector<string> vQ) {
	unordered_map<string, int> mapQ;

	for (vector<string>::iterator itQ = vQ.begin(); itQ!= vQ.end(); itQ++) {
		mapQ.emplace(*itQ,-1);
	}
	
	int currMinIndex = -1;
	int currMaxIndex = -1;
	int preMaxIndex = -1;
	int preMinIndex = -1;
	int allMinIndex = -1;
	int allMaxIndex = -1;
	int atAIndex = 0;

	for (vector<string>::iterator itA = vA.begin(); itA!=vA.end(); itA++) {
			
		unordered_map<string, int>::iterator itMapQ = mapQ.find(*itA);
		
		if (itMapQ != mapQ.end()) { // found 
			
			itMapQ->second = atAIndex;
			if (!seeAllElement(mapQ)) {
				
			} else {
				preMinIndex = currMinIndex;
				preMaxIndex = currMaxIndex;
				
				// accept to loop Min Max here since user input not many
				// search words
				GetMinMaxIndex(mapQ,currMinIndex, currMaxIndex);

				if ( (currMaxIndex - currMinIndex < preMaxIndex - preMinIndex) ||
					((preMaxIndex == -1) && (preMinIndex == -1)) )
				{
					allMinIndex = currMinIndex;
					allMaxIndex = currMaxIndex;
				}
			}

		}
		atAIndex++;
	}
	if (allMaxIndex == -1 || allMinIndex == -1) return 0;

	return (allMaxIndex - allMinIndex + 1);

}


int main() {
	//string arrA[] = {"a","b"," ","c"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"," ","b","c","a"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"," ","c","a","b"};
	string arrA[] = {"a"," "," ","a","b"," ","c"," ","a","c","b"};
	string arrQ[] = {"a","b","c"};
	
	vector<string> A(std::begin(arrA), std::end(arrA));
	vector<string> Q(std::begin(arrQ), std::end(arrQ));

	int result = findSmallestSubString(A,Q);
	cout << result << endl;
	
	int result2 = FindSmallestSubString2(A,Q);
	cout << result2 << endl;
	
	
	return 0;
}