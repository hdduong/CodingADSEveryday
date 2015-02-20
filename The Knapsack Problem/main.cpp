#include <iostream>

using namespace std;


struct Item {
	int value; 
	int weight;
};

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

void KnapsackRe(Item item[], int size, int currWeightLeft, int curValue, int & maxValue, int thisIndex, int & step) {
	step++;

	if (thisIndex == size) return;

	for (int i = thisIndex; i < size;i++) {
		
		if (item[i].weight < currWeightLeft) {
			

			currWeightLeft = currWeightLeft - item[i].weight;
			curValue = curValue + item[i].value;
			if (curValue > maxValue) maxValue = curValue;
			
			KnapsackRe(item, size, currWeightLeft, curValue, maxValue, thisIndex + 1, step);
			
			currWeightLeft = currWeightLeft + item[i].weight;
			curValue = curValue - item[i].value;
		}
	}
	
}

void KnapsackDP(Item item[], const int & size, const int & totalW, int & step) {
	int ** arr = create2DArray(size + 1, totalW + 1); // values init to 0 already

	for (int i = 1; i < size  + 1; i++) { // item
		for (int j =  1; j < totalW  + 1;j++) {
			step++;			
			if (item[i-1].weight <= j)
				arr[i][j] = max(arr[i-1][j], arr[i-1][j- item[i-1].weight] + item[i-1].value); 
			else
				arr[i][j] = arr[i-1][j];
		}
	}
	print2DArray(arr,size  + 1,totalW + 1);
	free2DArray(arr,size + 1);

	cout << "No. step: " << step << endl;
}



void printArr(Item item[], int size) {
	for (int i = 0; i < size; i++) {
		cout << item[i].value << "	" << item[i].weight << endl;
	}
	cout << endl;
}

int main() {

	int totalW = 6;
	Item item[] = {{3,4},{2,3},{4,2},{4,3}};
	int size = sizeof(item)/sizeof(Item);

	//printArr(item,size);
	int step = 0;
	KnapsackDP(item,size,totalW,step);

	int stepRe = 0;
	int maxValue = INT_MIN;
	int curValue = 0;
	
	KnapsackRe(item, size, totalW, curValue, maxValue, 0, stepRe);

	cout << "Max value is: " <<  maxValue << endl;
	cout << "Recur Step: " << stepRe <<  endl;

	return 0;
}