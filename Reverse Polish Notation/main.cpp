// solution to use custom stack
#include <iostream>

using namespace std;

struct Node {
	char  * data;
	Node * next;
};

struct CusStack {
	Node * end;
	Node * start;
};

Node * newNode (char * _data) {
	Node * aNewNode= (Node*) malloc (sizeof(Node));

	aNewNode->data = _data;
	aNewNode->next = NULL;

	return aNewNode;
}

CusStack * newStack() {
	CusStack * aNewStack = (CusStack*) malloc (sizeof(CusStack));

	aNewStack->end = NULL;
	aNewStack->start = NULL;

	return aNewStack;
}

bool isStackEmpty(CusStack*aStack) {
	if ( (aStack->start == NULL) && (aStack->end == NULL) )
		return true;
	
	return false;
}

void stackPush(CusStack *aStack, char * _data)  {
	Node * aNewNode = newNode(_data);
	
	if (isStackEmpty(aStack)) {
		aStack->start = aStack->end = aNewNode;

		return;
	}
	
	aStack->end->next = aNewNode;
	aStack->end = aNewNode;

}

char * stackTop(CusStack *aStack) {
	if (isStackEmpty(aStack)) {
		throw("Stack Empty. No Element returned!");
		return NULL;
	}

	return aStack->end->data;
}

void stackPop(CusStack *aStack) {
	if (isStackEmpty(aStack)) {
		throw("Stack Empty. No Element Poped!");
		return;
	}

	if (aStack->start == aStack->end) {
		free(aStack->end);

		aStack->end = NULL;
		aStack->start = NULL;
		return;
	}

	Node * tmp = aStack->start;
	while (tmp->next != aStack->end) {
		tmp = tmp->next;
	}
	
	// tmp prevNode of end
	free(aStack->end);

	aStack->end = tmp;

}

void printStack(CusStack &aStack) {
	if (isStackEmpty(&aStack))  cout << "Stack Empty!" << endl;

	Node * tmp = aStack.start;
	while (tmp != aStack.end) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << aStack.end->data << " " << endl;
}



int stackActualSize(CusStack &aStack) {
	int count = 1;
	
	if (isStackEmpty(&aStack)) return 0;

	Node * tmp = aStack.start;
	while (tmp != aStack.end) {
		count++;
		tmp = tmp->next;
	}
	

	return count;
}	

// deli = ','
char ** getTokens(char * expression, int &numToken) {
	
	int tokenNum = 1;
	char ** tokens;
	
	char * rExp = (char*)malloc(sizeof(char) * strlen(expression));
	strcpy(rExp,expression);

	

    const char s[2] = ",";
    char *token;
      
    token = strtok(rExp, s);
    
	while( token != NULL ) 
	{
		tokenNum++;
		//cout << token << endl;
    
		// For each subsequent call to get more tokens out of the string, you pass NULL. 
		// This is a little weird, but strtok() remembers the string you originally passed in, and continues to strip tokens off for you.
		// original string you pass in is destroyed, as it were. If you need to preserve the string, be sure to pass a copy of it
		token = strtok(NULL, s);
	}
   
	tokens = (char**)malloc(sizeof(char *) * tokenNum);
	numToken = tokenNum-1;

	tokenNum = 0;
	token = strtok(expression, s);
    
	while( token != NULL ) 
	{
		tokens[tokenNum] = token;
		tokenNum++;
		token = strtok(NULL, s);
	}
   return tokens;
}


// For simplicity: assume that all expression is valid
int evaluateExp(char *exp, CusStack * expStack) {
	int result = 0;
	
	int numToken = 0;
	char ** tokens = getTokens(exp, numToken) ;

	for (int i = 0; i < numToken; i++) {
		if (strcmp(tokens[i], "+") == 0) {

			int fNum = atoi(stackTop(expStack));; 
			stackPop(expStack);

			int sNum = atoi(stackTop(expStack));; 
			stackPop(expStack);
			
			char buffer[33];
			char * tmpResult = itoa(fNum + sNum,buffer,10);

			stackPush(expStack,tmpResult);
		} else if (strcmp(tokens[i], "X") == 0) {
			int fNum = atoi(stackTop(expStack));; 
			stackPop(expStack);

			int sNum = atoi(stackTop(expStack));; 
			stackPop(expStack);
			
			char buffer[33];
			char * tmpResult = itoa(fNum * sNum,buffer,10);

			stackPush(expStack,tmpResult);
		} else {
			stackPush(expStack,tokens[i]);
		};
	}
	
	result = atoi(stackTop(expStack));; 
	stackPop(expStack);
	
	return result;
}


int main() {
	//char * exp = "34,43,X,1,2,+,+"; // error with char *
	char exp[] = "34,43,X,1,2,+,+";
	CusStack * RPNStack = newStack();

	int value = evaluateExp(exp,RPNStack);
	cout << value << endl;
	//int numToken = 0;
	//char ** tokens = getTokens(exp, numToken) ;

	/*
	for (int i = 0; i < numToken; i++) {
		cout << tokens[i] << endl;
	}
	*/

	/*char * arr[] = {"34","43","X","1","2","+","+"};

	CusStack * RPNStack = newStack();
	stackPush(RPNStack,"3");
	stackPush(RPNStack,"4");
	stackPush(RPNStack,"X");
	stackPush(RPNStack,"1");
	stackPush(RPNStack,"2");
	stackPush(RPNStack,"+");
	stackPush(RPNStack,"+");
	
	stackPop(RPNStack);
	char * aChar = stackTop(RPNStack); cout << aChar << endl;
	int stackSize = stackActualSize(*RPNStack); cout << stackSize << endl;

	printStack(*RPNStack);
	*/return 0;
}
