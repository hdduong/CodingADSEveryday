#include <iostream>
#include <queue>

using namespace std;

// n rows, m columns
int ** create2DArray(int n, int m) {
	int **arr = NULL;

	for (int i = 0; i < n; i++) {
		arr  = (int **)malloc(sizeof (int *) * n);		
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			arr[i] = (int * )malloc(sizeof(int) * m);
		}
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			arr[i][j] = 0;
		}
	}

	return arr;
}

void free2DArray(int ** arr,int n) {
	
	for (int i = 0; i < n;i++) {
		free(arr[i]);
	}
	free(arr);
}

void print2DArray(int ** arr,int n, int m) {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}

void printOps(int ** arr, char * str1, char * str2);
// convert str1 --> str2
void editDistance(char * str1, char * str2){
	int n = strlen(str1);
	int m = strlen(str2);
	n = n + 1;
	m = m + 1;

	queue<pair<int,int>>  * qOps = new queue<pair<int,int>>();

	int ** edit = create2DArray(n,m);

	
	edit[0][0] = 0;
	
	for (int i = 1; i < n; i++) {
		edit[i][0] = i;
	}

	for (int i = 1; i < m; i++) {
		edit[0][i] = i;
	}

	// editDistance start from (1,1)
	// edit(i,j) = min ( edit(i-1,j)  + 1  Delete
	//					edit(i, j-1) + 1  Insert
	//					edit(i-1,j-1) + 0 if (str[i] == str[j]) or + 1 if (str[i] # str[j])
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			int currMin = INT_MAX;
			pair<int,int> currPair;

			if (edit[i-1][j] <= edit[i][j-1]) {
				currMin = edit[i-1][j] + 1;
				currPair.first = i-1;
				currPair.second=  j;
			} else  {
				currMin = edit[i][j-1] + 1;
				currPair.first = i;
				currPair.second = j-1;
			}


			if (str1[i-1] == str2[j-1]) { //Since matrix start at (1,1) but str index start at [0,0]
				if (currMin > edit[i-1][j-1]) {
					currMin = edit[i-1][j-1];
					currPair.first = i-1;
					currPair.second = j-1;
				}
			}
			else {
				if (currMin > edit[i-1][j-1] + 1) {
					currMin = edit[i-1][j-1] + 1;
					currPair.first = i-1;
					currPair.second = j-1;
				}
			}
			edit[i][j] = currMin;
			qOps->push(currPair);
		}
	}

	cout << "Min transform: " << edit[n-1][m-1] << endl;
	

	print2DArray(edit,n,m);
	
	printOps(edit, str1, str2);
	free2DArray(edit,n);
	
}


void printOps(int ** arr, char * str1, char * str2) {
	int n = strlen(str1);
	int m = strlen(str2);
	
	int i = n-1;
	int j = m-1;
	
	//cout << "(" << i + 1 << "," << j + 1 << ")" << endl;

	while( ( i >=0 ) && (j >=0) ) {
		char c1 = str1[i];
		char c2 = str2[j];

		int tmpI1 = i-1;
		int tmpJ1 = j-1;

		int tmpI2 = i-1;
		int tmpJ2 = j;

		int tmpI3 = i;
		int tmpJ3 = j-1;

		if (arr[tmpI1][tmpJ1] > arr[tmpI2][tmpJ2]) {
			i = tmpI2;
			j = tmpJ2;
		} else {
			i = tmpI1;
			j = tmpJ1;
		}

		if (arr[i][j] > arr[tmpI3][tmpJ3]) {
			i = tmpI3;
			j = tmpJ3;
		}
		cout << "(" << i+1 << "," << j+1 << ")  ";

		if ( (i == tmpI1) && (j == tmpJ1) ) 
			if (c1 == c2) {
				cout << "K ";
			}
			else {
				cout << "S ";
			}
		else if  ( (i == tmpI2) && (j == tmpJ2) ) {
			cout << "D ";
		}
		else if  ( (i == tmpI3) && (j == tmpJ3) ) {
			cout << "I ";
		}
		cout << endl;
	}
	
	i = (i >= 0) ? i + 1 : i;
	j = (j >= 0) ? j + 1 :j;
	while (i > 0) { // mean j == 0
		i = i-1;
		cout << "(" << i << "," << j + 1 << ")" << " D " << endl;
	}


	while (j >= 0) { // mean j == 0
		j = j-1;		
		cout << "(" << i + 1 << "," << j << ")" << " I " << endl;

	}

}


int main() {
	
	//char * str1 = "MATHS";
	//char * str2 = "ARTS";
	char * str1 = "Carthorse";
	char * str2 = "Orchestra";

	editDistance(str1,str2);

	return 0;
}