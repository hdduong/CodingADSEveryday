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


void printInorderTree(Node *root) {
	if (root == NULL) return;
	printInorderTree(root->left);
	cout << root->data << " ";
	printInorderTree(root->right);
}

bool isExistNode(Node * root, int dataFound) {
	if (root == NULL) 
		return false;

	if (root->data == dataFound)
		return true;

	if (root->data < dataFound) {
		return isExistNode(root->right,dataFound);
	}

	if (root->data > dataFound) {
		return isExistNode(root->left,dataFound);
	}

}

// assume that only positive numbers
// if contains negative number then do findPrev and findSucceed
bool findSum(Node * newRoot, Node * originalRoot, int k) {
	
	if (newRoot == NULL) return false;

	if (newRoot->data < k /2) {
		return findSum(newRoot->right, originalRoot, k);
	}

	if (newRoot->data > 2 * k) {
		return findSum(newRoot->left,originalRoot,k);
	}

	int current_data = newRoot->data;
	int left_data = k - current_data;

	if (left_data != current_data) {
		if (!isExistNode(originalRoot,left_data)) {
			bool findLeft = findSum(newRoot->left,originalRoot,k);
			if (!findLeft) {
				bool findRight = findSum(newRoot->right,originalRoot,k);
				return findRight;
			}
			return findLeft;
		}
	} else {
			bool findLeft = findSum(newRoot->left,originalRoot,k);
			if (!findLeft) {
				bool findRight = findSum(newRoot->right,originalRoot,k);
				return findRight;
			}
			return findLeft;
	}

	return true;

}

int main() {
	Node * node1 = newNode(1);
	Node * node2 = newNode(2);
	Node * node3 = newNode(3);
	Node * node4 = newNode(4);
	Node * node5 = newNode(5);
	Node * node6 = newNode(6);
	Node * node7 = newNode(7);
	Node * node8 = newNode(8);
	Node * node9 = newNode(9);
	
	node5->left = node2;
	node5->right = node8;

	node2->left = node1;
	node2->right = node3;

	node3->right = node4;

	node8->left = node7;
	node8->right = node9;

	node7->left = node6;

	printInorderTree(node5);

	cout << endl;

	bool isExist = findSum(node5, node5, 18);
	cout << isExist << endl;

	dellocateTree(node5);
	return 0;
}