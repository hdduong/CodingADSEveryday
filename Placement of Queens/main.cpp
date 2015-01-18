#include <iostream> 

using namespace std;

// number of queen until (0 based) 
bool passColunnCheck(int * arr, int noQueen, int columnCheck) {
	for (int i = 0; i <= noQueen; i++) {
		if (arr[i] == columnCheck) return false;
	}
	return true;
}


bool passDiagnalCheck(int * arr, int noQueen, int columnCheck) {
	for (int i = 0; i <= noQueen;i++) {
		if ( ( (arr[i] - i) == (columnCheck - (noQueen + 1) ) ) 
			|| ( (arr[i] + i) == (noQueen + 1 + columnCheck) )
			) return false;
	}
	return true;
}


void printQueens(int *arr, int size) {
	for ( int i = 0; i < size; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << "."; 
		}
		cout << "Q";
		for (int j = arr[i] + 1; j < size; j++) {
			cout << "."; 
		}

		cout << endl;
	}
	cout << endl;

}
// arr: column of queens
// size: board
// n: current queen at row
void placeQueens(int *arr, int size, int n) {
	
	// loop throug all avialable columsn
	for (int i = 0; i < size; i++) {
		if (n > 0) {
			if (passColunnCheck(arr,n-1,i) && passDiagnalCheck(arr,n-1,i)) {
				arr[n] = i;
				if (n == size-1) {
					printQueens(arr,size);
				} else {
					placeQueens(arr,size,n+1);
				}
			}
		}
		else { //n == 0, pass all check
			arr[n] = i;
			placeQueens(arr,size, n+1);
		}
	}

	
}
int main() {
	int size = 4;

	int *arr = (int*)malloc(sizeof(int) * size);
	placeQueens(arr,size,0);

	return 0;
}