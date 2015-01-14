#include <iostream> 
#include <stack>
using namespace std;

int countLongestParens(char * str, int size) {
	int countMax = INT_MIN;
	int currCount = 0;
	stack<pair<char,int>> stPr; // index and paren

	for (int i = 0; i < size - 1; i++) {
		if (str[i] == '(') {
			stPr.push(make_pair('(',i));
		}
		else if (str[i] == ')') {
			if (!stPr.empty()) { 
				char p = stPr.top().first;

				if (p == '(') {
					stPr.pop();	 // calculate count based on different in index
				
					if (!stPr.empty()) currCount = i - stPr.top().second;
					else currCount = i + 1;

					if (currCount > countMax) {
						countMax = currCount;
						currCount = 0;
					}
				
				}
			} else { // has no valid (
				currCount = 0;
			}

			
		}
	}

	
	return countMax;
}

int main() {
	
	char arr[] = "((())()()())";
	//char arr[] = "((())()(())";
	//char arr[] = "(())()(()(";
	//char arr[] = "(())())"; //6
	//char arr[] = "()()"; // 4

	int size = sizeof (arr) /sizeof(char);

	int longestSeq = countLongestParens(arr,size);
	cout << longestSeq << endl;


	return 0;
}