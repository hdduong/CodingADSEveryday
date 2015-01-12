#include <iostream> 

using namespace std;

bool isAlphanumeric(char c) {
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
		return true;
	
	return false;
}

bool isPalindrome(char * str) {
	
	int start = 0;
	int end = strlen(str) - 1;

	while(start <= end) {
		while( !isAlphanumeric(str[start])) start++;
		while( !isAlphanumeric(str[end])) end --;

		if (! (tolower(str[start]) == tolower(str[end])) )
			return false;
		start++;
		end--;
	}

	return true;
}
int main() {
	// char * s = "Ray a Ray";
	// char * s = "A man, a plan, a canal, Panama.";
	char * s = "Able was I, ere I saw Elba!";
	bool isPal = isPalindrome(s);
	
	cout << isPal << endl;

	return 0;
}