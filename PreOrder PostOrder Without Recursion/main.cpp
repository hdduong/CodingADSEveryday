#include <iostream>
#include <stack>

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


void dellocateTree(Node * root) {
	if (root == NULL)
		return;

	dellocateTree(root->left);
	root->left = NULL;

	dellocateTree(root->right);
	root->right = NULL;
	
	free(root);
}

void printPreOrderNR(Node * root) {
	stack<Node *> stackNode;

	if (root == NULL) return;

	
	stackNode.emplace(root);

	while(!stackNode.empty()) {
		Node * nodeAtTop = stackNode.top();
		stackNode.pop();

		cout << nodeAtTop->data << " ";

		if (nodeAtTop->right != NULL)
			stackNode.emplace(nodeAtTop->right);

		if (nodeAtTop->left != NULL)
			stackNode.emplace(nodeAtTop->left);

	}

}



void printPreOrderR(Node * root) {
	if (root == NULL) return;
	cout << root->data << " ";

	printPreOrderR(root->left);
	printPreOrderR(root->right);
}


void printPostOrderNR(Node * root) {
	stack<Node *> stackNode;

	if (root == NULL) return;

	stackNode.emplace(root);
	Node * prevPrintNode = NULL;
	

	while(!stackNode.empty()){
		Node * aNode = stackNode.top();

		if ( (aNode->left != NULL) ||  (aNode->right != NULL) ) {
			if ( (aNode->left != prevPrintNode)  && (aNode->right != prevPrintNode)) {
				if (aNode->right != NULL) {
					stackNode.emplace(aNode->right);		
				}

				if (aNode->left != NULL) {
					stackNode.emplace(aNode->left);		
				}
			} else {
				cout << aNode->data << " ";
				stackNode.pop();
				prevPrintNode = aNode;
			}
		}
		else {
			cout << aNode->data << " ";
			stackNode.pop();
			prevPrintNode = aNode;
		}
	}
}


void printPostOrderR(Node * root) {
	if (root == NULL) return;
	
	printPostOrderR(root->left);
	printPostOrderR(root->right);

	cout << root->data << " ";
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
	Node * nodeK = newNode('K');
	Node * nodeL = newNode('L');
	Node * nodeN = newNode('N');
	Node * nodeM = newNode('M');
	Node * nodeO = newNode('O');
	Node * nodeP = newNode('P');
	
	nodeA->left = nodeB;
	nodeA->right = nodeI;
	
	nodeB->left = nodeC;
	nodeB->right = nodeF;

	nodeC->left = nodeD;
	nodeC->right = nodeE;

	nodeF->right = nodeG;
	nodeG->left = nodeH;

	nodeI->right = nodeO;
	nodeO->right = nodeP;

	nodeI->left = nodeJ;
	nodeJ->right = nodeK;

	nodeK->left = nodeL;
	nodeK->right = nodeN;

	nodeL->right = nodeM;

	printPreOrderR(nodeA);
	cout << endl;

	printPreOrderNR(nodeA);
	cout << endl;

	printPostOrderR(nodeA);
	cout << endl;

	printPostOrderNR(nodeA);
	cout << endl;

	//dellocateTree(nodeA);

	return 0;
}
