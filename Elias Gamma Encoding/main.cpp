#include <iostream>
#include <cmath>

using namespace std;

int convertB2D(char * binaryStr) {

	int result = 0;

	int length = strlen(binaryStr);
	
	for (int i = 0; i < length; i++) {
		result += pow(2,length - 1 - i) * ( binaryStr[i] - '0');
	}
	return result;
}

void reverseString(char * str) {
	int n = strlen(str);
	int i = 0;
	int j = n-1;

	for (i = 0, j = n-1; i  < j; i++,j--) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}


int countDecimalLength (int number) {
	int count = 0;
	
	while(number > 0) {
		number = number / 10;
		count++;
	}
	
	return count;
}

char * convertD2B(int number) {
	
	char * ret = (char *)malloc(sizeof(char));
	ret[0] = '\0';  // empty string

	int quotient = number;
	
	while( quotient > 0) {
		int remainder = quotient % 2;
		quotient = quotient / 2;
		
		char * cRemainder = (char * ) malloc(sizeof(char) * 2); // one for number and one for '\0';
		cRemainder[0] = remainder + '0';
		cRemainder[1] = '\0';

		ret = strcat(ret, cRemainder);

		free(cRemainder);
	}
	reverseString(ret);
	return ret;
}


char * EliasEncoding(int number) {
	char * toBinary = convertD2B(number);
	int biLen = strlen(toBinary);

	char * zeroFront = (char * )malloc(sizeof(char) * biLen);
	for (int i = 0; i < biLen - 1; i++) {
		zeroFront[i] = '0';
	}
	zeroFront[biLen-1] = '\0';

	char * ret = (char *)malloc(sizeof(char));
	ret[0] = '\0';  // empty string

	strcat(ret, zeroFront);
	strcat(ret,toBinary);
	
	free(zeroFront);

	return ret;
}


char * encodeArray(int arr[], int size) {
	
	char * ret = (char *)malloc(sizeof(char));
	ret[0] = '\0';  // empty string

	for (int i = 0; i < size; i++) {
		char * encoding = EliasEncoding(arr[i]);
		strcat(ret,encoding);
	}

	return ret;
}


int * EliDecode(char * eliEncode , int & currNumber) {
	int length = strlen(eliEncode);

	int * arr = (int*) malloc(sizeof(int) * length/2); // every number is 1

	int startNumber = 0;
	int endNumber = 0;
	
	while (endNumber < length) {
		int currLength = 0;
		
		while( eliEncode[endNumber++] == '0') {
			currLength++;
			//endNumber++;
		}
		endNumber = endNumber + currLength; // next number
		if (endNumber > length) break;

		char * encodeNumber = (char *)malloc(sizeof(char) * (endNumber - startNumber + 1));
		int j = 0;
		for (int i = startNumber; i < endNumber;i++, j++) {
			encodeNumber[j] = eliEncode[i];
		}
		encodeNumber[j] = '\0';

		arr[currNumber++] = convertB2D(encodeNumber);
		free(encodeNumber);

		startNumber = endNumber;
	}

	int * ret = (int*) malloc(currNumber * sizeof(int) ); // every number is 1
	for (int i = 0; i < currNumber;i++) {
		ret[i] = arr[i];
	}
	free(arr);

	return ret;
}



void printArr(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}


int main() {
	
	/*
	char str[] = "abcd";
	reverseString(str);
	cout << str << endl;
	*/

	/*
	char * bi = convertD2B(8);
	cout << bi << endl;
	*/

	/*
	char * encoding = EliasEncoding(13);
	cout << encoding << endl;

	int decoding = convertB2D(encoding);
	cout << decoding << endl;
	return 0;
	*/

	int arr[] = {8,13,10};
	int size = sizeof(arr)/ sizeof(int);

	char * eliEncode = encodeArray(arr,size);
	cout << eliEncode << endl;

	int noNunber = 0;
	int * decodeArr = EliDecode(eliEncode,noNunber);
	printArr(decodeArr,noNunber);

}