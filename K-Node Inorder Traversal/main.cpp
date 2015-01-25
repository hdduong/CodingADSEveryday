#include <iostream>
#include <stdlib.h>  // need that for malloc in gcc

using namespace std;

struct Node {
	char data;
	int size;
	Node * left, * right;
};

Node * newNode(char data, int size) {
	Node * aNewNode = (Node *) malloc(sizeof(data));
	aNewNode->data = data;
	aNewNode->size = size;
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


Node * findKNode(Node * root, int k) {
	if (root == NULL) return NULL;

	if ( (root->left == NULL) && (root->right == NULL) )  {
		if (k ==1) return root;
	}

	if (k > root->size + 1) return NULL;



	// return code should be in else if
	if (root->left != NULL) {
		if (root->left->size + 1 == k) {
			return root->left;
		} else if (root->left->size + 2 == k) {
			return root;
		} else if (root->left->size + 2 < k) {
			return findKNode(root->right, k- root->left->size - 2);
		} else if (root->left->size + 2 >= k) {
			return findKNode(root->left, k); // remove root itself
		}

	} else if (root->left == NULL) {
		if (k == 1) return root;
		if (root->right) 
			return findKNode(root->right, k-1);
		else {
			return NULL;
		}
		
	}


	return NULL;
}

int main() {
	
	// EPI figure 10.5
	Node* nodeH = newNode('H',8);
	Node* nodeB = newNode('B',3);
	Node* nodeC = newNode('C',3);
	Node* nodeF = newNode('F',0);
	Node* nodeE = newNode('E',1);
	Node* nodeD = newNode('D',2);
	Node* nodeA = newNode('A',0);
	Node* nodeG = newNode('G',1);
	Node* nodeI = newNode('I',0);

	nodeH->left = nodeB;
	nodeB->left = nodeF;
	nodeB->right = nodeE;
	nodeE->left = nodeA;
	
	nodeH->right = nodeC;
	nodeC->right = nodeD;
	nodeD->right = nodeG;
	nodeG->left = nodeI;

	Node * found = findKNode(nodeH, 3);
	if (found != NULL) 
		cout << found->data <<  " " << endl;
	else 
		cout << "NULL" << endl;

	
	//dellocateTree(nodeH);3	return 0;
}