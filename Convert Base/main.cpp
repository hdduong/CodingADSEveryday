#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int convertToBase10(string number, int base, unordered_map<char,int> & respresentTo10) {
	
	string result;
	int prevNum = 0;

	for (string::iterator itAt = number.begin(); itAt != number.end(); itAt++) {
		unordered_map<char,int>::iterator itF = respresentTo10.find(*itAt);
		
		int numberAt = 0;
		
		if (itF == respresentTo10.end()) {
			numberAt = *itAt - '0';
		} else  {
			numberAt = itF->second;
		}

		if (itAt != number.end() - 1)
			prevNum = (prevNum + numberAt) * base;
		else 
			prevNum = (prevNum + numberAt);
		
	}
	return prevNum;
}


string convert10ToBase(int number, int toBase, unordered_map<int,string> & represent10To) {
	
	string result;

	int quotient = number;
	int prevQuo = quotient;

	while (quotient > 0) {
		quotient = quotient / toBase;

		int resultAt = prevQuo - (quotient * toBase);
		prevQuo = quotient;

		unordered_map<int,string>::iterator itF = represent10To.find(resultAt);	
		
		if (itF == represent10To.end()) {
			result.append(to_string(resultAt));
		} else {
			result.append(itF->second);
		}
	}

	reverse(result.begin(), result.end());

	return result;
}


int main() {
	
	unordered_map<int, string> represent10To;
	represent10To.emplace(10, "A");
	represent10To.emplace(11, "B");
	represent10To.emplace(12, "C");
	represent10To.emplace(13, "D");
	represent10To.emplace(14, "E");
	represent10To.emplace(15, "F");
	
	unordered_map<char, int> representTo10;
	representTo10.emplace('A', 10);
	representTo10.emplace('B', 11);
	representTo10.emplace('C', 12);
	representTo10.emplace('D', 13);
	representTo10.emplace('E', 14);
	representTo10.emplace('F', 15);
	
	int to10 = convertToBase10("615",7,representTo10);
	//int to10 = convertToBase10("6A",15,representTo10);
	cout << to10 << endl;

	string from10 = convert10ToBase(306,13,represent10To);
	cout << from10 << endl;

	return 0;
}