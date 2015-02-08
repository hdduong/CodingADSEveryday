#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> vVisit) {
	for (vector<string>::iterator it = vVisit.begin(); it != vVisit.end(); it++) {
		cout << *it << " ";
	}
}

vector<string>  getBalancedParens(int k) {
	if (k == 1) {
		
		vector<string> prev;
		prev.push_back("()");
		
		return prev;
	}

	vector<string> result;
	vector<string> prev = getBalancedParens(k-1);

	for (vector<string>::iterator it = prev.begin(); it != prev.end(); it++) {
		if (it != prev.end() - 1) {
			result.push_back("(" + *it + ")");
			result.push_back(*it + "()");
			result.push_back("()" + *it);
		} else {
			result.push_back("(" + *it + ")");
			result.push_back(*it + "()");
		}
	}
	return result;
}

int main () {

	int k = 4;
	vector<string> result  =   getBalancedParens(k);

	printVector(result);
	cout << endl;
	return 0;
}