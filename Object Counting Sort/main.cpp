#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Person {
	int key;
	string name;
};

/*
struct ComparePerson {
	bool operator() (Person a, Person b) {
		if (a.key == b.key)
	}
};
*/


void swapInVector(vector<Person>& vp, int i, int j) {
	Person tmpP;

	tmpP.key = vp[i].key;
	tmpP.name = vp[i].name;

	vp[i].key  = vp[j].key;
	vp[i].name = vp[j].name;
	
	vp[j].key = tmpP.key;
	vp[j].name = tmpP.name;


}

void CountingSortObject(vector<Person>& vp) {
	// count how many objects  with each key
	unordered_map<int,int> keyCount;
	
	for (vector<Person>::iterator p1 = vp.begin(); p1 != vp.end(); p1++) {
		if (keyCount.find(p1->key) == keyCount.end()) {
			keyCount[p1->key] = 1;
		}
		else {
			keyCount[p1->key] = keyCount[p1->key] + 1;
		} 
	}
	/*
	for (unordered_map<int,int>::iterator it = keyCount.begin(); it != keyCount.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	*/
	unordered_map<int,int> keyOffset;
	int offsetKey = 0;

	for (unordered_map<int,int>::iterator it = keyCount.begin(); it != keyCount.end(); it++) {
		keyOffset[it->first] = offsetKey;
		offsetKey += it->second;
	}
	
	/*
	for (unordered_map<int,int>::iterator it = keyOffset.begin(); it != keyOffset.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	*/
	// stalblize each position. O(n) time since each of elements touch maximum 2 times
	unordered_map<int,int> noKeyInPos;
	for (unordered_map<int,int>::iterator it = keyOffset.begin(); it != keyOffset.end(); it++) {
		noKeyInPos.emplace(it->first, 0);
	}

	int i = 0;
	while( i < vp.size()) {
		unordered_map<int,int>::iterator it = keyOffset.find(vp[i].key);
		if (it != keyOffset.end()) {
			int actualPosI = keyOffset[vp[i].key];
			if (actualPosI != i) {

				swapInVector(vp,i,actualPosI);

				noKeyInPos[vp[actualPosI].key]++;
				keyOffset[vp[actualPosI].key]++;
				
				if (noKeyInPos[vp[actualPosI].key] >= keyCount[vp[actualPosI].key] ) {
					keyOffset.erase(vp[actualPosI].key);
				}
			}
			else {
				noKeyInPos[vp[i].key]++;
				keyOffset[vp[i].key]++;
				i++;
			}
		}
		else {
			i++;
		}
	}
	
}

int main() {
	Person p1;
	p1.key = 1;
	p1.name = "a";

	Person p4;
	p4.key = 3;
	p4.name = "c";

	Person p2;
	p2.key  = 2;
	p2.name  = "b1";

	Person p3;
	p3.key  = 1;
	p3.name = "a1";

	Person p5;
	p5.key = 3;
	p5.name = "c1";

	Person p6;
	p6.key = 3;
	p6.name = "c2";
	
	Person p7;
	p6.key = 2;
	p6.name = "b2";
	

	vector<Person> vP;
	vP.emplace_back(p1);
	vP.emplace_back(p4);
	vP.emplace_back(p2);
	vP.emplace_back(p3);
	vP.emplace_back(p5);
	vP.emplace_back(p6);

	
	cout << endl;

	CountingSortObject(vP);

	for (vector<Person>::iterator p1 = vP.begin(); p1 != vP.end(); p1++) {
		cout << p1->key << " " << p1->name << endl;
	}

	cout << endl;
}