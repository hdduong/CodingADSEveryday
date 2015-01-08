#include <iostream>
#include <stack>

using namespace std;

// this one is greedy approach
bool minCoinExchange(int * arr, int number_of_coins, int sum, stack<int> &st, int atCoin) {
	if ( (sum < 0) || (atCoin < 0) )
		return false;

	if (sum == 0) {
		return true;
	}

	st.push(arr[atCoin]);

	bool result = minCoinExchange(arr,number_of_coins,sum - arr[atCoin],st,atCoin);
	if (result) return true;
	
	st.pop();
	return minCoinExchange(arr, number_of_coins,sum,st,atCoin-1);
}

//stack has no iterator
void printStack(stack<int> &st) {
	if (st.empty()) {
		cout <<  "Empty " << endl;
		return;
	}
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
	//int arr[] = {4,5,7};
	int arr[] = {1,3,4,5};
	int n = sizeof(arr)/ sizeof (int);

	int sum = 7;

	stack<int> st;
	int atCoin = n-1;

	bool result = minCoinExchange(arr,n,sum,st,atCoin);
	cout << result << endl;
	printStack(st);

	return 0;
}