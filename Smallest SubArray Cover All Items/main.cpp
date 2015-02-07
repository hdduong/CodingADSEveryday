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

int main() {
	string arrA[] = {"a","b"," ","c"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"," ","b","c","a"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"," ","c","a","b"};
	//string arrA[] = {"a"," "," ","a","b"," ","c"," ","a","c","b"};
	string arrQ[] = {"a","b","c"};
	
	vector<string> A(std::begin(arrA), std::end(arrA));
	vector<string> Q(std::begin(arrQ), std::end(arrQ));

	int result = findSmallestSubString(A,Q);
	cout << result << endl;
	return 0;
}