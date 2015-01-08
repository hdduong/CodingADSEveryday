#include <string>
#include <iostream>

using namespace std;

//complicated think with visited, keep length, check no "cb" 
// simply think that 2 loops: s(0,0), s(0,1), s(0,2) 
//					 s(1,1), s(1,2).. 
void printSubStr(char * orgStr, char * subStr, int startPos, int currentLength, int reqLength, bool * visited, int prevPos) {
	if (currentLength == reqLength) {
		cout << subStr << endl;
		prevPos = 0;
		return;
	}

	for (int i = startPos; i < strlen(orgStr); i++) {
		if ( (!visited[i]) && (prevPos <= i) ) {
			subStr[startPos] = orgStr[i];
			prevPos = i;

			visited[i] = true;
			startPos++;
			currentLength++;

			printSubStr(orgStr, subStr, startPos, currentLength, reqLength, visited, prevPos);

			startPos--;
			currentLength--;
			visited[i] = false;
		}

	}
}

int main() {
	char str[] = "abc";
	int length = strlen(str);

	bool * visited = (bool * )malloc(length * sizeof (bool));
	
	for (int i = 1; i <= length; i++) {
		for (int j = 0; j < length; j++) {
			visited[j] = false;
		}

		char * subStr = (char*) malloc(sizeof(char) * (i  + 1) );
		subStr[i] = '\0';
		
		int startPos = 0;
		int currentLength = 0;
		int prevPos = 0;

		printSubStr(str,subStr,startPos,currentLength, i, visited,prevPos);
	}

	return 0;
}