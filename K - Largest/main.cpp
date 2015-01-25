#include <iostream> 

using namespace std;

struct Node {
	int data;
	Node * left, * right;
};

Node * newNode (int data) {
	Node * aNewNode = (Node*)malloc(sizeof(Node));
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


void findKLargest(Node * root, int * k) {
	if (root == NULL) return;
	
	if (*k <= 0) return;

	if (root->right != NULL) {
		findKLargest(root->right,k);
	}
	
	if (*k <= 0) return;

	cout << root->data << " ";
	*k = *k-1;

	if (*k <= 0) return;

	if (root->left != NULL) {
		findKLargest(root->left, k);
	}
}

int main() {
	// Figure 15.1
	Node * node19 = newNode(19); // root;
	Node * node7 = newNode(7);
	Node * node43 = newNode(43);
	Node * node3 = newNode(3);
	Node * node2 = newNode(2);
	Node * node5 = newNode(5);
	Node * node11 = newNode(11);
	Node * node17 = newNode(17);
	Node * node13 = newNode(13);
	Node * node47 = newNode(47);
	Node * node53 = newNode(53);
	Node * node23 = newNode(23);
	Node * node37 = newNode(37);
	Node * node29 = newNode(29);
	Node * node41 = newNode(41);
	Node * node31 = newNode(31);

	node19->left = node7;
	node19->right = node43;

	node7->left = node3;
	node7->right = node11;

	node3->left = node2;
	node3->right = node5;

	node11->right = node17;

	node17->left = node13;

	node43->left = node23;
	node43->right = node47;

	node23->right = node37;
	
	node37->left = node29;
	node37->right = node41;

	node29->right = node31;

	node47->right = node53;
	
	Node * node46= newNode(46);
	node47->left = node46;

	int k = 3;
	findKLargest(node19, &k);
	cout << endl;

	dellocateTree(node19);

	return 0;
}