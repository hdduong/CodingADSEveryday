#include <iostream>

using namespace std;

int** createMatrix(int n) {
	int **arr = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = (int * )malloc(sizeof(int) * n);
	}

	int value = 0;
	for (int i =0 ; i < n; i++) {
		for (int j =0; j < n;j++) {
			value++;
			arr[i][j] = value;
		}
	}
	return arr;
}

void printMatrix(int ** arr, int n) {
	for (int i =0 ; i < n; i++) {
		for (int j =0; j < n;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void rotateMatrix(int **arr, int n) {
	
	for (int k = 0; k < n-1; k++) {
		int i = 0;
		int j = k;
		
		int startI = i;
		int startJ = j;

		int next_row = j;
		int next_column = n-1-i;

		int tmpValue = 0;
		int preValue = arr[startI][startJ];

		while ( !((next_row == startI) && (next_column == startJ)) ) {
			tmpValue = arr[next_row][next_column];

			arr[next_row][next_column] = preValue;
			
			preValue = tmpValue;

			i = next_row;
			j = next_column;

			next_row = j;
			next_column = n-1-i;
		}
		arr[next_row][next_column] = tmpValue;	
	}
}


int main() {
	int size = 3;
	int ** arr = createMatrix(size);
	rotateMatrix(arr,size);
	printMatrix(arr,size);

	return 0;
}