#include <iostream>


using namespace std;

int IntBits(int t) {
	return (sizeof(t) * 8);
}

//swap bit i and j. Assume that i > j
int swapBits(int k, int i, int j) {
	int result = 0;

	if (i <= j) return k;

	int ki = (1 << i) & k; // keep i bit  //ki = 0100 0000
	ki = ki >> (i -j); // cout << ki; ki = 0000 0010

	int kj = (1 << j) & k; // keep j bit //kj = 0000 0000
	kj = kj << (i - j);

	// kt = 1011 1101
	int kt = (~0) ^ (1 << i) ^ (1 << j);

	result = (kt & k) | ki | kj;

	return result;
}

int main() {
	
	//cout << ~0 << endl; // -1
	int k = 73;
	int kswap = swapBits(k, 6,1); 
	cout << kswap << endl;
	return 0;

}