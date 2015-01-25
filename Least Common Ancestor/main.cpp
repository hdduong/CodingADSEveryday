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

	dellocateTree(root->left);

	dellocateTree(root->right);

	// Not sure why VS always throw error here
	cout << "freeing " << root->data << endl;
	free(root);
}

Node * findWay2(Node * root, Node * nodeFound, vector<Node *> &way) {
	if (root == NULL) return NULL;

	if (root == nodeFound) {
		way.push_back(root);
		return root;
	}

	
	Node * onLeft = findWay2(root->left, nodeFound, way);
	if (onLeft != NULL) {
		way.push_back(root);
		return root;	
	} else {
		Node * onRight = findWay2(root->right, nodeFound, way);
		if (onRight != NULL) {
			way.push_back(root);
			return root;
		}
	}
	return NULL;
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
	Node * node8 = newNode(8);
	
	root->left = node2;
	root->right = node5;

	node2->left = node3;
	node2->right = node4;

	node5->left = node6;
	node6->left = node7;
	
	node5->right = node8;
	// test findWay 2

	vector<Node *> way;
	Node * aWay = findWay2(root, node8, way);

	for (vector<Node *>::iterator it = way.begin(); it != way.end(); it++) {
		cout << (*it)->data << " ";
	}
	cout << endl;
	//findLCS(root, node3, node7);
	/*Node * result = findLCS(root, node3, node4);
	cout << result->data;
	cout << endl;
*/
	dellocateTree(root);
	return 0;
}