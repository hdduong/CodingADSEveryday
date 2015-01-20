#include <iostream>

using namespace std;

int findMaxProduct(int * arr, int size) {
	int result = 1;
	int sign = 1;

	int currMaxSign = -1; // assume that Max has negative value
	int currMaxPos = -1; // remember Position has Max

	for (int i = 0; i < size; i++) {
		if (arr[i] < 0)
			sign *= -1;
	}

	for (int i = 1; i < size; i++) {
		int signPreProd  = (sign * arr[i-1] >= 0) ? 1 : -1;
		int signCurrProd = (sign * arr[i] >= 0) ? 1: -1;

		if (signPreProd * signCurrProd < 0) {
			
			if (signPreProd > 0) {
				
				if (currMaxPos == -1) currMaxPos = i-1;
				else { // exist before
					if (currMaxSign > 0) { //both P(i-1) and P(currMaxSign) > 0
						if (sign * arr[i-1] <= sign * arr[currMaxPos]) {
							currMaxPos = i-1;
						}
					} else {
						currMaxSign = signPreProd;
						currMaxPos = i-1;
					}
				}
			} else if (signCurrProd > 0) {

				if (currMaxPos == -1) currMaxPos = i;
				else { // exist before
					if (currMaxSign > 0) { //both P(i) and P(currMaxSign) > 0
						if (sign * arr[i] <= sign * arr[currMaxPos]) {
							currMaxPos = i;
						}
					} else {
						currMaxSign = signCurrProd;
						currMaxPos = i;
					}
				}
				
			}
		} else if (signPreProd * signCurrProd >= 0) {
			if (signPreProd > 0) { // both P(i) and P(i-1) > 0
				
				int tmpMaxSign = -1;
				int tmpMaxPos = -1;
				// compare P(i) and P(i-1)
				if (arr[i-1] <= arr[i]) {
					tmpMaxSign = signPreProd;
					tmpMaxPos = i-1;
				} else {
					tmpMaxSign = signCurrProd;
					tmpMaxPos = i;
				}
				
				if (currMaxPos == -1) {
					currMaxPos = tmpMaxPos;
					currMaxSign = tmpMaxSign;
				} else {
					if (currMaxSign< 0) {
						currMaxPos = tmpMaxPos;
						currMaxSign = tmpMaxSign;
					} else {
						if (arr[tmpMaxPos] <= arr[currMaxPos]) {
							currMaxPos = tmpMaxPos;
							currMaxSign = tmpMaxSign;
						}
					}
				}

			} else if (signPreProd < 0) { //both P(i) and P(i-1) < 0
				int tmpMaxSign = -1;
				int tmpMaxPos = -1;
				// compare P(i) and P(i-1)
				if (arr[i-1] <= arr[i]) {
					tmpMaxSign = signPreProd;
					tmpMaxPos = i-1;
				} else {
					tmpMaxSign = signCurrProd;
					tmpMaxPos = i;
				}
				
				if (currMaxPos == -1) {
					currMaxPos = tmpMaxPos;
					currMaxSign = tmpMaxSign;
				} else {
					if (currMaxSign >= 0) {
						currMaxPos = tmpMaxPos;
						currMaxSign = tmpMaxSign;
					} else {
						if (arr[tmpMaxPos] <= arr[currMaxPos]) {
							currMaxPos = tmpMaxPos;
							currMaxSign = tmpMaxSign;
						}
					}
				}
			}
		}
	}

	return currMaxPos;
}


int main() {

	//int arr[] = {2,3,4,5};
	//int arr[] = {5,3,4,2};
	//int arr[] = {5,3,4,-2};
	//int arr[] = {-5,3,4,-2};
	//int arr[] = {-5,-3,4,-2};
	//int arr[] = {-5,-3,-4,-2};
	//int arr[] = {1,2};
	//int arr[] = {-1,-2};
	int arr[] = {0,0,2};
	int size=  sizeof(arr) / sizeof(int);

	int result = findMaxProduct(arr,size);
	cout << result << endl;

	return 0;

}