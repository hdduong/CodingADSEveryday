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


Node *  convertToDLL(Node * root) {
	if (root == NULL) return NULL;

	Node * left = convertToDLL(root->left);
	if (left != NULL) {
		left->right = root;
	}

	Node * right = convertToDLL(root->right);

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

	
	cout << endl;

	dellocateTree(root);
	return 0;
}