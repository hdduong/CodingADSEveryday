#include <iostream> 

using namespace std;

void permutationHelper(int * arr, int size, int * result, int fillAt, bool * visited);

void printArr(int * arr, int size) {
	for (int i = 0 ; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void permutation(int *arr, int size) {
	
	int *result = (int*) malloc(sizeof(int) * size);
	for ( int i = 0; i < size; i++) {
		result[i] = INT_MIN;
	}

	bool * visited = (bool*) malloc(sizeof(bool) * size);
	for ( int i = 0; i < size; i++) {
		visited[i] = false;
	}


	for (int i = 0; i < size; i++) {
		result[0] = arr[i];
		visited[i] = true;
		
		int fillAt = 1;
		permutationHelper(arr,size,result,fillAt,visited);
		visited[i] = false;
	}

	
	free(result);
	free(visited);
	

}

void permutationHelper(int * arr, int size, int * result, int fillAt, bool * visited) {
	
	if (fillAt == size) {
		printArr(result, size);
		return;
	}

	//int nextToFill = getFirstNotVisited(visited, size);

	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[fillAt] = arr[i];

			permutationHelper(arr,size, result, fillAt + 1, visited);

			result[fillAt] = INT_MIN;
			visited[i] = false;
		}
	}
}



int main() {

	int arr[] = {2,3,5,7};
	int size = sizeof(arr) /sizeof(int);
	
	permutation(arr,size);


	return 0;
}