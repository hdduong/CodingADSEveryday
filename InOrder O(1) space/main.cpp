#include <iostream>
#include <stdlib.h> 

using namespace std;

struct Node {
	char data;
	Node * left, * right, *parent;
};

Node * newNode(char data) {
	Node * aNewNode = (Node *) malloc(sizeof(data));
	aNewNode->data = data;
	aNewNode->left = aNewNode->right = NULL;
	aNewNode->parent = NULL;
	return aNewNode;
}


void dellocateTree(Node * root) {
	if (root == NULL)
		return;

	dellocateTree(root->left);

	dellocateTree(root->right);

	// Not sure why VS always throw error here
	cout << "freeing " << root->data << endl;
	
	root->left= NULL;
	root->right= NULL;
	root->parent = NULL;
	free(root);
}

void printInOrder(Node * root) {
	if (root == NULL) return;

	Node * parent = root;
	Node * child = NULL;
	Node * prev = NULL;

	bool goToLeft = true;
	while(parent) {
		if (goToLeft) {
			child = parent->left;
			prev = child;

			while( (child != NULL) && (parent != NULL) ) {
				parent = child;
				child = child->left;
			}

			child = parent;
			if (prev != child) {
				cout << parent->data << " ";
				parent = child->parent;
			}
			else { // there is no left tree
				parent = child;
			}
			goToLeft = false;
			
		} else {
			if ( (parent->left == child) || ( (parent->left == NULL) && (parent->right != NULL) && (parent->right != child) ) 
				|| ((parent->left == NULL) && (parent->right == NULL) )
				){


				cout << parent->data <<  " ";

				child = parent; // save parent node in case parent->right == NULL
				parent = parent->right;
				if (parent != NULL) {
				
					if  (parent->left != NULL) 
						goToLeft = true;
					else {
						
						if (parent->right != NULL) {
							cout << parent->data << " ";
							parent = parent->right;
							goToLeft= true;
						}

					}
				}
				else {
					parent = child;
					parent = parent->parent;
					//child = parent;
				}

			} else { // parent->right == child
				child = parent;
				parent = parent->parent;
			}

		}
	
	}
	cout << endl;
}


int main() {
	// EPI figure 10.4 from B
	/*
	Node * nodeB = newNode('B');
	Node * nodeC = newNode('C');
	Node * nodeD = newNode('D');
	Node * nodeE = newNode('E');
	Node * nodeF = newNode('F');
	Node * nodeG = newNode('G');
	Node * nodeH = newNode('H');

	nodeB->left = nodeC;
	nodeB->right = nodeF;

	nodeC->left = nodeD;
	nodeC->right = nodeE;

	nodeF->right = nodeG;
	nodeG->left = nodeH;
	
	nodeH->parent = nodeG;
	nodeG->parent = nodeF;
	nodeF->parent = nodeB;
	nodeD->parent = nodeC;
	nodeE->parent = nodeC;
	nodeC->parent = nodeB;

	printInOrder(nodeB); */


	Node * nodeI = newNode('I');
	Node * nodeJ = newNode('J');
	Node * nodeK = newNode('K');
	Node * nodeL = newNode('L');
	Node * nodeM = newNode('M');
	Node * nodeN = newNode('N');
	Node * nodeO = newNode('O');
	Node * nodeP = newNode('P');

	nodeI->left = nodeJ;
	nodeI->right = nodeO;

	nodeJ->right = nodeK;
	nodeK->left = nodeL;
	nodeK->right = nodeN;

	nodeL->right = nodeM;
	nodeO->right = nodeP;
		
	nodeM->parent = nodeL;
	nodeL->parent = nodeK;
	nodeN->parent = nodeK;
	nodeK->parent = nodeJ;
	nodeJ->parent = nodeI;
	nodeP->parent = nodeO;
	nodeO->parent = nodeI;

	printInOrder(nodeI);
	
	dellocateTree(nodeI);

	return 0;
}