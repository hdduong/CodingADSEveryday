#include <iostream>

using namespace std;

void print2DArr(char ** arr, int n, int m) {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void dellocate2DArr(char ** arr, int n) {
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}

void multiplyBigInt(char * str1, char * str2, bool sign) {
	
	// prepare data
	int length1 = strlen(str1);
	int length2 = strlen(str2);

	int lineLen = length1 + length2 + 1; // carry over safe

	char ** arrResult = NULL;
	arrResult = (char**)malloc(sizeof(char*) * length2);
	for (int i = 0; i < length2; i++) {
		arrResult[i] = (char*) malloc(sizeof(char) * (lineLen) ); 
	}

	for (int i = 0; i < length2; i++) {
		for (int j = 0; j < lineLen; j++) {
			arrResult[i][j] = '0';
			if (j == lineLen - 1) arrResult[i][j] = '\0';
		}
	}

	
	
	int atLine = 0;

	for (int i = length2 - 1; i >= 0 ; i--) {
		int carry = 0;	
		int atPos = lineLen -1 - (length2 - 1 - i) - 1; //start from 0. Result from n-1
		int secondNum = str2[i] - '0';

		for (int j = length1 - 1; j >= 0; j--) {
			
			int firstNum = str1[j] - '0';
			int mul = firstNum * secondNum + carry;
			carry = mul / 10;
			arrResult[atLine][atPos] = (mul % 10) + '0';
			atPos--;
		}
		if (carry > 0) {
			arrResult[atLine][atPos] = carry + '0';
		}
		atLine++;
	}

	 print2DArr(arrResult, length2, lineLen);

	char * result = (char* )malloc(sizeof(char) * (lineLen));
	for (int i = 0; i < lineLen + 1; i ++) {
		result[i] = '0';
	}

	result[lineLen-1] = '\0';
	
	int carry = 0;
	int sum = 0;

	for (int j = lineLen-2; j >= 0; j --) {
		carry = 0;
		for (int i = 0; i < length2; i++) {		
			sum += (arrResult[i][j] - '0');
		}
		result[j] = (sum % 10) + '0';
		carry = sum / 10;
		sum = carry;
	}

	if (carry > 0) {
		result[0] = carry + '0';
	}
	cout << (sign ? "-" : "") << result << endl;

	dellocate2DArr(arrResult,length2);
}

int main() {
	char * str1 = "193707721";
	//char * str1 = "999";
	// char * str2 = "999";
	//char * str2 = "761838257287";
	char * str2 = "-761838257287";
	// char * str2 = "0";

	bool hasSign = false;

	if ( (str2[0] == '-') && (str1[0] == '-') ) {
		hasSign = false;
		str1 = &str1[1];
		str2 = &str2[1];
	} else if ( (str2[0] == '-') && (str1[0] != '-') ) {
		hasSign = true;
		str1 = &str1[0];
		str2 = &str2[1];
	} else if ( (str2[0] != '-') && (str1[0] == '-') ) {
		hasSign = true;
		str1 = &str1[1];
		str2 = &str2[0];
	} else if ( (str2[0] != '-') && (str1[0] != '-') ) {
		hasSign = false;
		str1 = &str1[0];
		str2 = &str2[0];
	}

	//cout << str1 << " " << strlen(str1) << " " <<endl;
	//cout << str2 << " " << strlen(str2) << " " <<endl;

	multiplyBigInt(str1,str2,hasSign);

	return 0;
}