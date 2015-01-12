#include <iostream> 

using namespace std;

void swapChar(char * c1, char * c2) {
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void reverseStr(char *s, int start, int end) {
	while (start <= end) {
		swapChar(&s[start++],&s[end--]);
	}
}

void reverseAllWord (char * str, int start, int end) {

	reverseStr(str,start,end);

	int startWord = start;
	int endWord = 1;

	while (endWord <= end + 1) {
		if  ( (str[endWord] != ' ') && (str[endWord] != '\0') )  {
			if (str[startWord] == ' ') { //new word
				startWord = endWord;
				endWord++;
			} else if (str[startWord] != ' ') { // continue previous word
				endWord++;
			}
		} else if ( (str[endWord] == ' ') || (str[endWord] == '\0') )  {
			reverseStr(str,startWord,endWord-1);
			startWord = endWord;
			endWord++;
		}
	}

}

int main() {
	
	//char str[] = "Alice likes Bob ";
	char str[] = "  Alice likes Bob ";
	
	reverseAllWord(str,0,strlen(str) - 1);
	cout << str << endl;

	return 0;
}