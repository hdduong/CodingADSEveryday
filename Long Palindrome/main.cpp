#include <string>
#include <iostream>

using namespace std;

int longestPalindrome(char * str) {
	int length = strlen(str);
	int maxLength = 0;

	int * arrPal = (int *)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		arrPal[i] = 0;
	}
	
	arrPal[0] = 1;
	if (str[0] == str[1]) arrPal[1] = 2;
	else arrPal[1] = 1;

	for (int i = 2; i < length; i++) {
		if (arrPal[i-1] > 1) { 
			if (str[i] == str[i-1-arrPal[i-1]]) arrPal[i] = arrPal[i-1] + 2; // ABCBA
			else if (str[i] == str[i-1]) arrPal[i] = arrPal[i-1] + 1; // ABBB
			else arrPal[i] = 1;

 		} else {
			if (str[i] == str[i-1]) arrPal[i] = arrPal[i-1] + 1;
			else if (str[i] == str[i-2]) arrPal[i] = arrPal[i-2] + 2;
			else {
				arrPal[i] = 1;
			}
		}
		maxLength = (maxLength > arrPal[i]) ? maxLength : arrPal[i];
	}
	return maxLength;
}

int main() {
	char str[] = "abcbacdeed";
	int length = strlen(str);

	int maxLength = longestPalindrome(str);
	
	cout << maxLength;
	cout << endl;
	return 0;
}