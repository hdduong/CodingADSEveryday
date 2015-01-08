#include <iostream>

using namespace std;

// n rings from pole1 -> pole2
// pole3 is immediate (can null or only contains largest ring)

void transferRing(int n, int pole1, int pole2, int pole3) {
	
	if (n == 0) return;

	if (n == 1) {
		cout << pole1 << " " << "-->" << " " << pole2 << endl;
		return;
	}

	//if (n == 2) {
	//	cout  <<  pole1 << " " << "-->" << " " << pole2 << endl;
	//	cout  << pole1 << " " << "-->" << " " << pole3 << endl;
	//	cout  << pole2 << " " << "-->" << " " << pole1 << endl;
	//	cout  << pole3 << " " << "-->" << " " << pole2 << endl;
	//	cout  << pole1 << " " << "-->" << " " << pole2 << endl;
	//	return;
	//}

	transferRing(n-1,pole1,pole2,pole3);
	transferRing(1,pole1,pole3,pole2);
	transferRing(n-1,pole2,pole1,pole3);
	transferRing(1,pole3,pole2,pole1);
	transferRing(n-1,pole1,pole2,pole3);

}
int main() {
	
	transferRing(3,1,2,3);

	return 0;

	
	
}