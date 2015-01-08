#include <string>
#include <iostream>

using namespace std;


void printSubStr(char * orgStr, char * subStr, int currentSub, int currentLength, bool * visited) {
	if (currentLength == strlen(orgStr)) {
		cout << subStr << endl;		
		return;
	}

	
	for (int k = 0; k < strlen(orgStr); k++) {	
		if (!visited[k]) {
			subStr[currentSub] = orgStr[k];
			
			visited[k] = true;
			currentSub++;
			currentLength++;

			printSubStr(orgStr, subStr, currentSub,currentLength, visited);
	
			currentLength--;
			currentSub--;
			visited[k] = false;
		}
	}
}

int main() {
	char str[] = "abc";
	int length = strlen(str);

	bool * visited = (bool * )malloc(length * sizeof (bool));
	
	for (int j = 0; j < length; j++) {
		visited[j] = false;
	}

	char * subStr = (char*) malloc(sizeof(char) * (length  + 1) );
	subStr[length] = '\0';
	

	int currentLength = 0;
	int currentSub = 0;

	printSubStr(str,subStr,currentSub,currentLength, visited);

	return 0;
}