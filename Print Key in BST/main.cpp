#include <iostream>
#include <stack>

using namespace std;

struct Node  {
	int data;
	Node * left, * right;
};


Node * newNode(int _data) {
	Node * aNewNode = (Node*)malloc(sizeof(Node));
	aNewNode->data = _data;
	aNewNode->right = aNewNode->left = NULL;

	return aNewNode;
}

void dellocateTree(Node * root) {
	if (root == NULL)
		return;

	if ( (root->left == NULL) &&  (root->right == NULL) ) {
		free(root);
		return;
	}

	if (root->left != NULL) 
		dellocateTree(root->left);

	if (root->right != NULL)
		dellocateTree(root->right);

	free(root);
}

void printBSTKeys(Node * root) {
	if (root == NULL) return;
	
	stack<Node*> stNode;

	Node * tmp = root;
	while(tmp) {
		stNode.push(tmp);
		tmp=tmp->left;
	}

	while (!stNode.empty()) {
		Node * top = stNode.top();
		stNode.pop();

		cout << top->data << " ";

		tmp = top->right;
		while(tmp) {
			stNode.push(tmp);
			tmp=tmp->left;
		}
	}
	cout << endl;

}

int main() {
	// EPI figture 15.1 
	Node * node23 = newNode(23);
	Node * node37 = newNode(37);
	Node * node29 = newNode(29);
	Node * node27 = newNode(27);
	Node * node34 = newNode(34);
	Node * node32 = newNode(32);
	Node * node31 = newNode(31);
	Node * node33 = newNode(33);
	
	node23->right = node37;
	node37->left = node29;
	node29->left = node27;
	node29->right = node34;
	node34->left = node32;
	node32->left = node31;
	node32->right = node33;

	printBSTKeys(node23);

	dellocateTree(node23);
	return 0;
}