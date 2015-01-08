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

void printSpiralMatrix(int **arr, int n) {
	int row1= 0;
	int col1 = 0;

	int row2 = n-1;
	int col2= n-1;

	while( (row1 <= row2)  && (col1 <= col2) ) {
		// r1,c1 => r2,c2
		for (int i = col1; i <= col2;i++) {
			cout << arr[row1][i] << " ";;
		}
		row1++;

		//r1,c2 => r2,c2
		for (int i = row1; i <= row2;i++) {
			cout << arr[i][col2] << " ";
		}
		col2--;

		//r2,c2 => r2,c1
		for (int i = col2; i >= col1;i--) {
			cout << arr[row2][i] << " ";
		}
		row2--;
		
		//r2,c1 => r1,c1
		for (int i = row2; i >= row1;i--) {
			cout << arr[i][col1] << " ";;
		}
		col1++;


	}
	cout << endl;
}


int main() {
	int size = 3;
	int ** arr = createMatrix(size);
	printMatrix(arr,size);
	
	printSpiralMatrix(arr,size);
	return 0;
}