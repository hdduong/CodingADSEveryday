#include <iostream>
#include <stack>
#include <vector>


using namespace std;

struct Node {
	char data;
	Node * left, * right;
};

Node * newNode(char data) {
	Node * aNewNode = (Node *) malloc(sizeof(data));
	aNewNode->data = data;
	aNewNode->left = aNewNode->right = NULL;
	
	return aNewNode;
}

void printInorderTree(Node *root) {
	if (root == NULL) return;
	printInorderTree(root->left);
	cout << root->data << " ";
	printInorderTree(root->right);
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

void printLeftBorder(Node * root) {
	if (root == NULL)
		return;

	if (root != NULL)
		cout << root->data << " ";
	printLeftBorder(root->left);
}


Node * getMostLeft(Node * root) {
	if (root == NULL) return NULL;

	while (root->left != NULL)
		root = root->left;

	return root;
}

Node * getMostRight(Node * root) {
	if (root == NULL) return NULL;

	while (root->right != NULL)
		root = root->right;

	return root;
}



void printRightBorder(Node * orignalRoot, Node * root) {
	if (root == NULL)
		return;

	printRightBorder(orignalRoot, root->right);
	if ( (root != NULL) && (root!= orignalRoot) )
		cout << root->data << " ";
	
}


void printLeafNodes(Node * root, Node * mostLeft, Node * mostRight) {
	if (root == NULL) return;
	
	if ( (root->left == NULL) && (root->right == NULL)) 
		if ( (root != mostLeft) &&  (root != mostRight) )
			cout << root->data << " ";


	printLeafNodes(root->left, mostLeft, mostRight);
	
	
	printLeafNodes(root->right, mostLeft, mostRight);
}

void printBorder(Node * root) {
	Node * mostLeft = getMostLeft(root);
	Node * mostRight = getMostRight(root);

	printLeftBorder(root);
	printLeafNodes(root, mostLeft, mostRight);
	printRightBorder(root, root);

}

int main() {
	Node * nodeA = newNode('A');
	Node * nodeB = newNode('B');
	Node * nodeC = newNode('C');
	Node * nodeD = newNode('D');
	Node * nodeE = newNode('E');
	Node * nodeF = newNode('F');
	Node * nodeG = newNode('G');
	Node * nodeI = newNode('I');
	Node * nodeJ = newNode('J');
	Node * nodeH = newNode('H');
	
	nodeA->left = nodeB;
	nodeA->right = nodeC;

	nodeB->left = nodeD;
	nodeB->right = nodeE;

	nodeE->right = nodeH;
	
	nodeC->left = nodeF;
	nodeC->right = nodeG;
	
	nodeG->right = nodeJ;

	nodeF->right = nodeI;

	printInorderTree(nodeA);
	cout << endl;

	printBorder(nodeA);
	cout << endl;
	dellocateTree(nodeA);
	return 0;
}