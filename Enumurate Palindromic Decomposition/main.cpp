#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isPalindrome(string& s, int startAt, int endAt) {
	if (endAt == startAt) return true;

	if (endAt - startAt == 1) {
		if (s[startAt] == s[endAt]) return true;
		return false;
	}

	if (s[startAt] == s[endAt]) {
		return isPalindrome(s, startAt + 1, endAt - 1);
	}
	return false;
}

void printVector(vector<string> vVisit) {
	for (vector<string>::iterator it = vVisit.begin(); it != vVisit.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int countTotalSize(vector<string> vVisit) {
	int totalLength = 0;

	for (vector<string>::iterator it = vVisit.begin(); it != vVisit.end(); it++) {
		totalLength += it->size();
	}
	return totalLength;

}
void palinDeconHelper(string& input, int startIndex, vector<string>& result) {
	if (countTotalSize(result) == input.size() ) { //nothing left to insert
		printVector(result);
		return;
	}

	for (int length = 1; length <= input.size() - startIndex; length++) {
		if (length ==1) {
			string insertStr (input,startIndex,1);
			
			result.emplace_back(insertStr);
			palinDeconHelper(input, startIndex + 1, result);
			result.pop_back();

		} else if (length > 1) {
			if (isPalindrome(input, startIndex, startIndex + length - 1) ) { // index
				
				string insertStr (input, startIndex,length); // number of character
				
				result.emplace_back(insertStr);
				palinDeconHelper(input, startIndex + length, result); // next of (startIndex + length -1)
				result.pop_back();

			} 
		}
	}
}


void palinDecom(string& input) {
	int startIndex = 0;
	vector<string> result;
	palinDeconHelper(input,startIndex, result);
}

int main() {
	string input("0204451881");
	//string input("020445");

	palinDecom(input);
	
	//string input("1881");
	//bool value = isPalindrome(input, 0, 3);
	cout << endl;
	return 0;
}