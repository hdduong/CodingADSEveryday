#include <iostream> 

using namespace std;


void printArr(char * arr, int size) {
	for (int i = 0 ; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printAllSubSetHelper(char * arr, int size, int requiredLength, char * result, int fillAt, bool * visited);

void printAllSubSet(char * arr, int size) {

	char *result = (char*) malloc(sizeof(char) * size);
	for ( int i = 0; i < size; i++) {
		result[i] = '\0';
	}

	bool * visited = (bool*) malloc(sizeof(bool) * size);
	for ( int i = 0; i < size; i++) {
		visited[i] = false;
	}

	for (int length = 1; length < size; length++) {
		
		for (int i = 0; i < size; i++) {
			result[0] = arr[i];
			visited[i] = true;
			
			int fillAt = 1;
			printAllSubSetHelper(arr,size,length,result,fillAt,visited);
		}
		for ( int i = 0; i < size; i++) {
			visited[i] = false;
		}
		for ( int i = 0; i < size; i++) {
			result[i] = '\0';
		}

	}

}

void printAllSubSetHelper(char * arr, int size, int requiredLength, char * result, int fillAt, bool * visited) {
	if (requiredLength == fillAt) {
		printArr(result, requiredLength);
		return;
	}

	for (int i = 0 ; i < size; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[fillAt] = arr[i];

			printAllSubSetHelper(arr,size,requiredLength,result, fillAt + 1, visited);

			visited[i] = false;
		}
	}
}

int main() {
	char str[] = "ABC";
	int size = strlen(str);

	printAllSubSet(str,size);

	return 0;
}