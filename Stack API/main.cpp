#include <iostream>
#include <queue>

using namespace std;

// key: stt
// data: 
struct Node {
	int key;
	int data;
};

struct NodeCompare {
	bool operator()(Node * nodeLeft, Node* nodeRight) {
		return (nodeLeft->key < nodeRight->key);
	}
};

Node * createNode(int data, int key) {
	Node * aNode = (Node*)malloc(sizeof(Node));
	aNode->key = key;
	aNode->data = data;
	return aNode;
}

int peek(priority_queue<Node *, vector<Node *>, NodeCompare> & heapAPI) {
	if (heapAPI.size() == 0) {
		throw;
	}

	Node * atTop = heapAPI.top();
	return (atTop->data);
}

void push(priority_queue<Node *, vector<Node *>, NodeCompare> & heapAPI, int data, int key) {
	Node * newNode = createNode(data,key);
	heapAPI.emplace(newNode);

}

void pop(priority_queue<Node *, vector<Node *>, NodeCompare> & heapAPI) {
	if (heapAPI.size() == 0)
		throw "Stack Empty!";
	heapAPI.pop();
}



int main() {
	priority_queue<Node *, vector<Node *>, NodeCompare> heapAPI ;
	//pop(heapAPI);

	int numElementKey = 0;

	int data1 = 3;
	int data2 = 1;
	int data3 = 5;
	int data4 = 2;

	push(heapAPI,data1,numElementKey++);
	push(heapAPI,data2,numElementKey++);
	push(heapAPI,data3,numElementKey++);

	int peekValue = peek(heapAPI);
	cout << peekValue << endl;

	pop(heapAPI);
	peekValue = peek(heapAPI);
	cout << peekValue << endl;

	push(heapAPI,data4,numElementKey++);
	peekValue = peek(heapAPI);
	cout << peekValue << endl;

	
}