#include <iostream>

using namespace std;

bool isAlphanumeric(char c) {
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
		return true;
	
	return false;
}

bool isStarChar(char c) {
	return (c == '*');
}

bool isDotChar(char c) {
	return (c == '.');
}


bool isStrictlyMatch(char * s, int startS, int endS, char * t, int startT, int endT) {
	//base case
	if ( (endS == startS) && (endT == startT) ) {
		if (s[startS] == t[startT]) {
			return true;
		}
		else return false;
	}

	if ( (endS == startS) && isDotChar(s[startS]) ) {
		if (abs(startT - endT) <= 1)
			return true;

		return false;
	}

	if ( (endS == startS) && isStarChar(s[startS]) ) {
		if (abs(startT - endT) <= 1)
				return true;
		char anchorChar = t[startT];
		bool isSameChar = true;
		int countChar = 1;

		while (isSameChar && (startT + countChar <= endT) ) {
			if (anchorChar != t[startT + countChar])
				isSameChar = false;
		}
		
		return isSameChar;
	}


	if ( isAlphanumeric(s[startS]) && (!isStarChar(s[startS + 1])) )  {
		if (s[startS] == t[startT]) {
			return isStrictlyMatch(s,startS+1,endS, t, startT+1, endT);
		}
		else return false;
	}
	
	if (isAlphanumeric(s[startS]) && isStarChar(s[startS+1]) ) {
		bool isMatch = false;
		bool anchorChar = t[startT];
		int countChar = 1;
		
		if (s[startS] != t[startT]) return false;
		
		//s[startS] != t[startT]
		isMatch = isStrictlyMatch(s, startS+2,endS,t,startT,endT); // * match 0 character
		if (isMatch) return true;
		else {
			while ((startT + countChar <= endT) && t[startT] == t[startT + countChar] ) {
				
				isMatch  = isStrictlyMatch(s,startS + 2, endS, t, startT+countChar, endT);
				
				if (isMatch) return true;
				
				countChar += 1;
			}
			// here mean no match with same char

			return isStrictlyMatch(s,startS + 2, endS, t, startT + countChar, endT);
		}
	}

	if ( isDotChar(s[startS])  && (!isStarChar(s[startS + 1])) ) {
		return isStrictlyMatch(s,startS +1, endS, t, startT+ 1, endT);
	}

	if ( isDotChar(s[startS]) && (isStarChar(s[startS + 1])) ) {
		bool isMatch = false;
		int countChar = 0;

		while (!isMatch && (startT + countChar <= endT)) {
			
			isMatch  = isStrictlyMatch(s,startS + 2, endS, t, startT+countChar, endT);
			if (isMatch) return true;
			countChar += 1;
		}
		return false;
	}

	return false;
}

void printString(char * s, int startS, int endS) {
	for (int i = startS; i <= endS; i++) {
		cout << s[i];
	}
	cout << endl;
}


bool isExtendMatch(char * s, int startS, int endS, char * t, int startT, int endT) {
	if (s[startS] == '^' && s[endS] == '$') {
		return isStrictlyMatch(s,startS+1,endS-1, t, startT, endT);
	} else if (s[startS] == '^' && s[endS] != '$') {
		int countChar = 0;
		bool isMatch = false;
		while((!isMatch) && (startT + countChar <= endT) ) {
			 isMatch = isStrictlyMatch(s,startS+1,endS, t, startT+countChar, endT);
			 countChar++;
		}
		return isMatch;

	} else if (s[startS] != '^' && s[endS] == '$') {
		int countChar = 0;
		bool isMatch = false;
		while((!isMatch) && (endT - countChar >= startT) ) {
			isMatch = isStrictlyMatch(s,startS,endS-1, t, endT - countChar, endT);
			countChar++;
		}
		return isMatch;
	} else if (s[startS] != '^' && s[endS] != '$') {
		bool isMatch = false;
		for (int i = startT; i < endT -1; i++) {
			for (int j = i; j  < endT; j++) {
				isMatch = isStrictlyMatch(s,startS,endS, t, i,j);
				if (isMatch) { 
					printString(t,i,j);
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	
	//bool isAlpha = isAlphanumeric('*');
	//cout << isAlpha << endl;

	//char  s[] = "aw9";
	//char t[] = "aw9";

	//char  s[] = "a.9";
	//char t[] = "a89";

	/*char  s[] = "a.*9";
	char t[] = "aw89";
	*/
	
	//char  s[] = "aw*9";
	//char t[] = "aww9";

	//bool isMatch = isStrictlyMatch(s,0, strlen(s)-1, t,0, strlen(t)-1);
	//cout << isMatch << endl;


	/*char  s[] = "^aw9";
	char t[] = "aw9";
*/

	// char  s[] = "aw9$";
	// char t[] = "aw9";//"aw91";

	//char  s[] = "^aw9$";
	//char t[] = "aw91";//"aw9";

	char  s[] = "a.9";
	char t[] = "xya9123" ; //"xyaW9123";//"aw91";

	bool isMatch = isExtendMatch(s,0, strlen(s)-1, t,0, strlen(t)-1);
	cout << isMatch << endl;

	
	return 0;
}