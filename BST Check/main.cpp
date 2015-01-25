#include <iostream> 

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

	dellocateTree(root->left);

	dellocateTree(root->right);

	// Not sure why VS always throw error here
	cout << "freeing " << root->data << endl;
	free(root);
}

bool isBSTHelper(Node * root, int * lastVisited) {
	if (root == NULL) 
		return true;

	bool isLeftBST = isBSTHelper(root->left,lastVisited);
	if (!isLeftBST) return false;

	if ( (isLeftBST) && (*lastVisited < root->data)) {
		* lastVisited = root->data;
		
		return isBSTHelper(root->right, lastVisited);
	}

	return false;
}

bool isBST(Node* root) {
	if (root == NULL) return true;

	int lastVisted = INT_MIN;

	return isBSTHelper(root,&lastVisted);
}

int main() {
	//Node * node1 = newNode(1);
	//Node * node2 = newNode(2);
	//Node * node3 = newNode(3);
	//Node * node4 = newNode(4);
	//Node * node5 = newNode(5);

	//node2->left = node1;
	//node2->right = node4;
	//node3->left = node2;
	//node3->right = node5;

	//
	//bool bstCheck = isBST(node3);
	//cout << bstCheck << endl;

	//dellocateTree(node3);


	Node * node1 = newNode(1);
	Node * node2 = newNode(2);
	Node * node3 = newNode(3);
	Node * node4 = newNode(4);
	Node * node5 = newNode(5);

	node2->left = node1;
	node2->right = node3;
	node4->left = node2;
	node4->right = node5;

	
	bool bstCheck = isBST(node4);
	cout << bstCheck << endl;

	dellocateTree(node4);

}


