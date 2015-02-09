#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;

void print2DArr(int ** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int ** create2DArray(int row, int col) {
	int ** newArr = (int **) malloc(sizeof (int) * row);

	for (int i = 0; i < row; i++) {
		newArr[i] = (int*)malloc(sizeof(int) * col);
	}
	
	newArr[0][0] = 1;
	newArr[0][1] = 2;
	newArr[0][2] = 3;

	newArr[1][0] = 3;
	newArr[1][1] = 4;
	newArr[1][2] = 5;


	newArr[2][0] = 5;
	newArr[2][1] = 6;
	newArr[2][2] = 7;

	return newArr;
}


// dynamic arr: 
// 0: means not visit
// 1: visited, good way
//-1: visited, bad way
int ** create2DDynamicArray(int row, int col) {
	int ** newArr = (int **) malloc(sizeof (int) * row);

	for (int i = 0; i < row; i++) {
		newArr[i] = (int*)malloc(sizeof(int) * col);
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			newArr[i][j] = 0;
		}
	}

	return newArr;
}

void printArr(int * s, int size) {
	for (int i  = 0 ; i < size;i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

void printListPair(list<pair<int, int> >& result) {
	for (list<pair<int, int> >::iterator it = result.begin(); it != result.end(); it++) {
		cout << "(" << (*it).first << "," << it->second << ") ";
	}
	cout << endl;
}

bool isValidNeighbor(int ** arr, int sizeR, int sizeC, int i, int j, int valueAtS) {
	if ( (i >= 0) && (i < sizeR) && (j >= 0) && (j < sizeC) ) {
		if (arr[i][j] == valueAtS)
			return true;
	}

	return false;
}

bool findSinA(int ** arr, int sizeR, int sizeC, int atRow, int atCol, int * s, int sizeS, int startAtS, list<pair<int,int> >& result) {
	if (startAtS == sizeS-1) {
		printListPair(result);
		return true;
	}

	for (int i = startAtS + 1; i < sizeS; i++) {
		// up
		if (isValidNeighbor(arr,sizeR,sizeC, atRow-1, atCol,s[i])) {
			result.push_back(make_pair(atRow-1,atCol));
			bool isFindWay = findSinA(arr,sizeR, sizeC, atRow-1,atCol,s, sizeS, i,result);
			if (!isFindWay) {
				result.pop_back();
			} else {
				result.pop_back();
				return true;
			}
		}

		// down
		if (isValidNeighbor(arr,sizeR,sizeC, atRow+1, atCol,s[i])) {
			result.push_back(make_pair(atRow+1,atCol));
			bool isFindWay = findSinA(arr,sizeR, sizeC, atRow+1,atCol,s, sizeS, i,result);
			if (!isFindWay) {
				result.pop_back();
			} else {
				result.pop_back();
				return true;
			}
		}

		//left
		if (isValidNeighbor(arr,sizeR,sizeC, atRow, atCol-1,s[i])) {
			result.push_back(make_pair(atRow,atCol-1));
			bool isFindWay = findSinA(arr,sizeR, sizeC, atRow,atCol-1,s, sizeS, i,result);
			if (!isFindWay) {
				result.pop_back();
			} else {
				result.pop_back();
				return true;
			}
		}

		//right
		if (isValidNeighbor(arr,sizeR,sizeC, atRow, atCol+1,s[i])) {
			result.push_back(make_pair(atRow,atCol+1));
			bool isFindWay = findSinA(arr,sizeR, sizeC, atRow,atCol+1,s, sizeS, i,result);
			if (!isFindWay) {
				result.pop_back();
			} else {
				result.pop_back();
				return true;
			}
		}
		return false;
	}

	return false;
}




int main() {

	int n = 3;
	int m = 3;

	int ** arr  = create2DArray(n,m);
	//int s[] = { 1,3,4,6 };
	int s[] = { 1,2,3,4 };
	size_t sSize  = sizeof(s) / sizeof(int);

	print2DArr(arr,n,m);
	cout << endl;
	
	printArr(s,sSize);
	cout << endl;
	list<pair<int, int> > result;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++){
			if (arr[i][j] = s[0]) {
				pair<int,int> newPair(i,j);
				result.push_back(newPair);
				findSinA(arr,n,m,i,j,s,sSize,0,result);
				result.pop_back();
			}
		}
	}
	
	return 0;
}