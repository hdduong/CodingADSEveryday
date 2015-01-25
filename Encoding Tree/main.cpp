#include <iostream> 
#include <string>

using namespace std;

struct Node {
	char data;
	Node * left, * right;
};

Node * newNode(char data) {
	Node * aNewNode = (Node *) malloc(sizeof(char));
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

void printCoding(Node * root, string codeUntil) {
	if (root == NULL) return;

	if ( (root->left == NULL) && (root->right == NULL) ) {
		cout << root->data << ": " << codeUntil << endl;
		return;
	}

	codeUntil.push_back('0');
	printCoding(root->left,codeUntil);

	codeUntil.pop_back();

	codeUntil.push_back('1');
	printCoding(root->right,codeUntil);

}
int main() {

	Node * root = newNode('A');
	Node * nodeB = newNode('B');
	Node * nodeC = newNode('C');
	Node * nodeD = newNode('D');
	Node * nodeE = newNode('E');
	Node * nodeF = newNode('F');
	Node * nodeG = newNode('G');
	Node * nodeH = newNode('H');
	Node * nodeI = newNode('I');
	Node * nodeJ = newNode('J');
	Node * nodeK = newNode('K');
	Node * nodeL = newNode('L');
	Node * nodeM = newNode('M');
	Node * nodeN = newNode('N');
	Node * nodeO = newNode('O');
	Node * nodeP = newNode('P');
	
	root->left = nodeB;
	root->right =  nodeI;

	nodeB->left = nodeC;
	nodeB->right = nodeF;

	nodeC->left = nodeD;
	nodeC->right = nodeE;

	nodeB->right = nodeF;
	nodeF->right = nodeG;
	nodeG->left = nodeH;

	nodeI->right = nodeO;
	nodeI->left = nodeJ;
	
	nodeJ->right = nodeK;
	
	nodeK->left = nodeL;
	nodeK->right = nodeN;
	
	nodeL->right = nodeM;

	nodeO->right = nodeP;

	string codeUtil;
	codeUtil.push_back('1');
	printCoding(root, codeUtil);

	dellocateTree(root);

	return 0;
}