#include <iostream>
#include <stack>
#include <vector>


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


bool findWay(Node * root, vector<Node *> &way, Node * nodeFound) {
	if (root == NULL) return false;

	if (root == nodeFound) {
		way.push_back(root);
		return true;
	}

	way.push_back(root);
	if (findWay(root->left, way, nodeFound) )
		return true;
	else 
		way.pop_back();

	way.push_back(root);
	if (findWay(root->right, way, nodeFound) )
		return true;
	else 
		way.pop_back();

	return false;
}

Node * findLCS(Node * root, Node * node1, Node * node2) {
	if ( (node1 == NULL) &&  (node2 == NULL)) return NULL;

	vector<Node * > way1;
	vector<Node * > way2;

	if (!findWay(root,way1,node1)) {
		return NULL;
	}
	
	if (!findWay(root,way2,node2)) {
		return NULL;
	}
	
	// here means both vector contains nodes from root
	vector<Node *>::iterator it1;
	vector<Node *>::iterator it2;
	
	Node * result = NULL;
	for (it1 = way1.begin(), it2 = way2.begin(); 
		it1 != way1.end(), it2 != way2.end(); it1++, it2++) {
			if (*it1 == *it2) {
				result = *it1;
			}
			else break;
	}

	return result;
}



int main() {
	Node * root = newNode(1);
	Node * node2 = newNode(2);
	Node * node3 = newNode(3);
	Node * node4 = newNode(4);
	Node * node5 = newNode(5);
	Node * node6 = newNode(6);
	Node * node7 = newNode(7);
	
	root->left = node2;
	root->right = node5;

	node2->left = node3;
	node2->right = node4;

	node5->left = node6;
	node6->left = node7;

	//findLCS(root, node3, node7);
	Node * result = findLCS(root, node3, node4);
	cout << result->data;
	cout << endl;

	dellocateTree(root);
	return 0;
}