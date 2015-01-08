#include <iostream>

using namespace std;

void printBrackets(char * str, int totalBracket, int numOpen, int numClose) {
	
	if ( (numOpen < 0) ||  (numClose < 0) ) return;

	else if ((numOpen == 0) && (numClose == 0)) {
		str[totalBracket] = '\0';
		cout << str << endl;
		return;
	}
	
	else if (numOpen <= numClose) {

		int pos = totalBracket - (numOpen + numClose);
		str[pos] = '{';
			
		printBrackets(str,totalBracket,numOpen-1,numClose);
	
		str[pos] = '}';
			
		printBrackets(str,totalBracket,numOpen,numClose-1);
		
	}
}

int main() {
	int number_of_brackets = 1;
	int num_open_bracket = number_of_brackets;
	int num_close_bracket = number_of_brackets;

	int total_bracket = number_of_brackets * 2;
	int string_length = total_bracket + 1;
	char * str = (char * )malloc(sizeof(char) * string_length);
	
	printBrackets(str,total_bracket,num_open_bracket,num_close_bracket);
	
	cout << endl;
	return 0;
}