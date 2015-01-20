#include <iostream>

using namespace std;

// calculate x/y only by + - and << >> 

// assum that x > y
int calculate(int x, int y) {
	
	int k = 0;
	int b = y;

	int left = x - b;

	int result = 0;

	while (x - y >= 0) {
		while (x - b >= 0) {
			k++; 
			b = b << 1;
		}
		

		k = k - 1;
		result += (1 << k);

		left = x - (y << k);
	
		x = left;
		b = y;
		
		k = 0;
	}
	

	return result;
	
}

int main () {
	//int cal = calculate(9,3);
	int cal = calculate(15,2);
	//int cal = calculate(7,2);
	cout << cal << endl;
	return 0;
}