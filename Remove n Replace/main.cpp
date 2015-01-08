#include <iostream> 
using namespace std;

// from = current index checked + 1;
// when replace
void goDown(char * str, int from) {
	int k = from;

	while(str[k] != '\0') {
		k++;
	}

	// k point to last
	str[k+1] = '\0';
	while (k > from) {
		str[k] = str[k-1];
		k--;
	}
}


// at = current index checked;
// when delete
void goUp(char * str, int at) {
	int k = at;

	while(str[k] != '\0') {
		str[k] = str[k+1];
		k++;
	}

}


void replaceRemove(char * str) {
	int i = 0;

	while (str[i] != '\0') {
		
		if (str[i] == 'a')  {
			goDown(str,i + 1);
			str[i] = 'd';
			str[i+1] = 'd';
			i++;
		}

		if (str[i] == 'b') {
			goUp(str,i);
			i--;
		}
		i++;
	}
}


int main() {
	const int MAX_STR_LEN = 20;

	char * str = (char* )malloc(sizeof (char) * MAX_STR_LEN);

	//str[0] = 'a';
	//str[1] = 'b';
	//str[2] = 'c';
	//str[3] = 'd';
	//str[4] = 'a';
	//str[5] = '\0'; // end of string;


	//str[0] = 'a';
	//str[1] = '\0'; // end of string;
	
	str[0] = 'b';
	str[1] = '\0';
	

	cout << str << endl;

	replaceRemove(str);

	cout << str << endl;

	return 0;
}