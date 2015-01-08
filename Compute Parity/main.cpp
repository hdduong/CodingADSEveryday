#include <iostream>

using namespace std;

void printMatrix(int ** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " " ;
		}
		cout << endl;
	}
}

void freeMatrix(int **A, int n) {
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
}


void printArr(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}


int * createLookupTable() {
	
	int nAr = 7;
	int nAc= 4;

	int nBr = 4;
	int nBc = 4 * 4;

	int nCc = 256;


	int **A = (int **)malloc(sizeof(int) * nAr);

	for (int i = 0; i < nAr; i++) {
		A[i] = (int *) malloc(sizeof(int) * nAc);
		A[i][0] = i;
		A[i][1] = i + 1;
		A[i][2] = i + 1;
		A[i][3] = i + 2;
	}

	int **B = (int **)malloc(sizeof(int) * nBr);
	for (int i = 0; i <= nBr; i++) {
		B[i] = (int * )malloc(sizeof(int) * nBc);
		
		// start at A[i]
		for (int j = 0; j < nBc;j++) {
			int remain = j / 4;
			remain = (remain > 1) ? (remain-1) : remain;

			int row = i + remain;
			int column = j % 4;

			B[i][j] = A[row][column];
			
		}
	}
	
	int *C = (int*)malloc(sizeof(int) * nCc);
	
	for (int i = 0; i < nCc; i++) {
		int remain =  i / 64;
		remain = (remain > 1) ? (remain-1) : remain;

		int rc = i % 16;
		int column = rc;

		int row = 0;

		if ((i >= 0) && (i <= 63)) {
			row = ( i / 16);
			
		} else if ((i >= 64) && (i <= 127)) {
			row = ( i  - 64) / 16;
			
		} else if ((i >= 128) && (i <= 191)) {
			row = ( i  - 128) / 16;

		} else if ((i >= 192) && (i <= 255)) {
			row = ( i  - 192) / 16;

		}
		row = (row > 1) ? (row - 1) : row;
		row += remain;

		C[i] = B[row][column];
	}

	/*
	printMatrix(A,7,nAc);
	cout << endl;
	
	printMatrix(B,nBr,nBc);
	cout << endl;

	printArr(C,256);
	cout << endl;
	*/
	freeMatrix(A,nAr);
	freeMatrix(B,nBr);
	
	return C;

}

int countNumberOne(int n, int * C) {
	
	int count  = 0;

	while (n != 0) {
		int k = n & 0xFFFF;
		count += C[k];
		n = n >> 16;
	}
	
	return count;
}

// method 2 to check parity instead of building HashTable
int countNumberOne2(int n) {
	int count = 0;
	while (n != 0) {
		count ++;
		n = n & (n-1);
	}
	return count;
}

// solution from book https://code.google.com/p/elements-of-programming-interviews/source/browse/trunk/Parity1.h
short parity1(unsigned long x) {
  short result = 0;
  while (x) {
    result ^= (x & 1);
    x >>= 1;
  }
  return result;
}

int main() {
	int * C = createLookupTable();
	
	int n = 77;
	int count = countNumberOne(n,C);
	cout << count << endl;

	count = countNumberOne2(n);
	cout << count << endl;

	count = parity1(n);
	cout << count << endl;

	free(C);


	// cout << sizeof(int); // 4 bytes
	// cout << sizeof(long); // 4 bytes
	
	
	
	
	return 0;
}