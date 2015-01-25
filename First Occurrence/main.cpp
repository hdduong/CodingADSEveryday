#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int data;
	Node * left, * right;
	char pos;
};

Node * newNode(int _data, char _pos) {
	Node * aNewNode = (Node*)malloc(sizeof(Node));

	aNewNode->data = _data;
	aNewNode->left = aNewNode->right = NULL;
	aNewNode->pos = _pos;

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


Node * firstOccRec(Node * root, int data) {
	if (root == NULL) return NULL;

	Node * foundLeft = firstOccRec(root->left, data);
	if (foundLeft) return foundLeft;
	else if (root->data > data) return NULL;
	else if (root->data == data ) return root;
	else if (root->data < data ) return firstOccRec(root->right,data);

	return NULL;

}



Node * firstOccIter(Node * root, int k) {
	Node * resultNode;
	
	if (root == NULL) return NULL;

	stack<Node*> stNode;
	
	Node *top = root;
	stNode.push(top);
	
	bool getFromLeftTree = true;

	do {
		if (getFromLeftTree) {
			while(top) {
				stNode.push(top);
				top = top->left;
			}
			getFromLeftTree = false;
		}

		top = stNode.top();
		stNode.pop();

		if (!top) {
			resultNode = NULL;
			break;
		}
		
		if (top->data == k) {
			resultNode = top;
			break;
		} else if (top->data > k) {
			resultNode = NULL;
			break;
		} else if (top->data < k) {
			if (top->right != NULL) {
				stNode.push(top->right);
				getFromLeftTree = true;
			}

		}

		top = stNode.top();


	} while( !stNode.empty());
	
	return resultNode;
}

int main() {
	
	Node * nodeA = newNode(108,'A');
	Node * nodeB = newNode(108,'B');
	Node * nodeC = newNode(-10,'C');
	Node * nodeF = newNode(108,'C');

	Node * nodeD = newNode(-14,'D');
	Node * nodeE = newNode(2,'E');

	Node * nodeG = newNode(285,'G');
	Node * nodeH = newNode(243,'H');
	Node * nodeI = newNode(285,'I');

	Node * nodeJ = newNode(401,'J');

	nodeA->left = nodeB;
	nodeA->right = nodeG;

	nodeB->left = nodeC;
	nodeB->right = nodeF;

	nodeC->left = nodeD;
	nodeC->right = nodeE;

	nodeG->left = nodeH;
	nodeG->right = nodeI;

	nodeI->right = nodeJ;

	//int k = 143;
	//Node * found = firstOccRec(nodeA,k);

	//if (found) cout << found->pos << endl;
	//else cout << "null" << endl;

	int k = 285;
	Node * found = firstOccIter(nodeA,k);

	if (found) cout << found->pos << endl;
	else cout << "null" << endl;

	dellocateTree(nodeA);


	return 0;
}

