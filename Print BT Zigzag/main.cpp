#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int data;
	Node * left, * right;
};

Node * newNode(int data) {
	Node * aNewNode = (Node *) malloc(sizeof(data));
	aNewNode->data = data;
	aNewNode->left = aNewNode->right = NULL;
	
	return aNewNode;
}


void dellocateTree(Node * root) {
	if (root == NULL)
		return;

	if ( (root->left == NULL) &&  (root->right == NULL) ) {
		root = NULL;
		free(root);
		return;
	}

	if (root->left != NULL) 
		dellocateTree(root->left);

	if (root->right != NULL)
		dellocateTree(root->right);

	root = NULL;
	free(root);
}

void printZigZigHelper(Node * root, bool isGoLeft) {
	stack<Node *> stack_1;
	stack<Node *> stack_2;

	stack_1.push(root);

	Node * currentNode = NULL;

	while ( (!stack_1.empty()) || (!stack_2.empty()) ) {
		while(! stack_1.empty() ) {
			currentNode = stack_1.top();
			stack_1.pop();

			cout << currentNode->data << " ";

			if (currentNode->right != NULL)
				stack_2.push(currentNode->right);

			if (currentNode->left != NULL) 
				stack_2.push(currentNode->left);
		}

		isGoLeft = false;
		
		while(! stack_2.empty() ) {
			currentNode = stack_2.top();
			stack_2.pop();
			
			cout << currentNode->data << " ";

			if (currentNode->left != NULL)
				stack_1.push(currentNode->left);

			if (currentNode->right != NULL) 
				stack_1.push(currentNode->right);
		}

		isGoLeft = true;

	}

}


void printZigZig(Node * root) {
	if (root == NULL) return;

	bool isGoLeft = true;
	printZigZigHelper(root, isGoLeft);
}




int main() {
	Node * root = newNode(1);
	Node * node2 = newNode(2);
	Node * node3 = newNode(3);
	Node * node4 = newNode(4);
	Node * node5 = newNode(5);
	Node * node6 = newNode(6);
	Node * node7 = newNode(7);
	
	root->left = node2;
	root->right = node5;

	node2->left = node3;
	node2->right = node4;

	node5->left = node6;
	node6->left = node7;

	printZigZig(root);
	cout << endl;

	dellocateTree(root);
	return 0;
}