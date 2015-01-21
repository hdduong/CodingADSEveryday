#include <iostream>

using namespace std;

char * generateLookSay(char * start, int n) {

	int currentNum = 1;
	int newLength = strlen(start) * 2; 
	
	char * strCheck = strdup(start);
	char * resultN = (char*)malloc(sizeof(char) * newLength + 1);
	
	int currLength = 0;
	int currIndex = 0;
	int freq = 0; 

	while ( currentNum < n) {
		currIndex = 0;

		char currChar = strCheck[currIndex];

		while(strCheck[currIndex] != '\0') {
			if (strCheck[currIndex] == currChar) {
				freq++;
				
			} else { // finish current freq
				resultN[currLength] =  freq + '0';
				resultN[currLength + 1] = currChar;

				currChar = strCheck[currIndex];
				
				currLength += 2;
				freq = 1;
			}
			currIndex++;
		}
		
		if (strCheck[currIndex] == '\0') {	
			resultN[currLength] = (freq = (freq==0) ? 1 : freq) + '0'; + '0';
			resultN[currLength + 1] = currChar;
			resultN[currLength+2] = '\0';
		}

		free(strCheck);
		strCheck = strdup(resultN);

		newLength = strlen(resultN) * 2; 
		
		free(resultN);
		resultN = (char*)malloc(sizeof(char) * newLength + 1);

		currentNum++;
		currIndex = 0;
		freq = 0;
		currLength = 0;
	}
	return strCheck;
}

int main() {

	char * start = "1"; //const, no free plz
	
	for (int i = 2; i <= 8; i++) {
		char * result = generateLookSay(start, i);
		cout << result << endl;
		free(result);
	}
	

	
	return 0;
}