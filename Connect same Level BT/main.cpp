#include <iostream>
#include <queue>
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

// with assume that head != NULL
Node * insertNode(Node * head, Node * newNode) {
	if (head == newNode)
		return head;


	Node * rHead = head;

	while(head->right != NULL) {
		head = head->right;
	}

	head->right = newNode;

	return rHead;
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


vector<Node * > linkSameLevel(Node * root) {
	vector<Node *> result; 
	queue<Node *> qNode;
	int num_node_current_level = 1;
	int num_node_next_level = 0;

	if (root == NULL) 
		return result;

	qNode.push(root);

	Node * newListHead = NULL;

	while (!qNode.empty()) {
		Node * newNode = qNode.front();
		if (newListHead == NULL)
			newListHead = newNode;

		qNode.pop();

		if (newNode->left != NULL) {
			num_node_next_level++;
			qNode.push(newNode->left);
		}

		if (newNode->right != NULL) {
			num_node_next_level++;
			qNode.push(newNode->right);
		}
		
		newNode->left = NULL;
		newNode->right = NULL;
		
		insertNode(newListHead,newNode);

		num_node_current_level--;

		if (num_node_current_level == 0) {
			num_node_current_level = num_node_next_level;
			num_node_next_level = 0;
			result.push_back(newListHead);
			newListHead = NULL;
		}
	}

	return result;
	
}


void printList(Node * head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;
}

void printVectorList (vector<Node*> listNode) {
	for (vector<Node *>::iterator listIter = listNode.begin(); listIter != listNode.end(); listIter++) {
		printList(*listIter);
	}
	cout << endl;
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

	vector<Node *> result = linkSameLevel(root);
	printVectorList(result);
	dellocateTree(root);
	cout << endl;

	return 0;
}