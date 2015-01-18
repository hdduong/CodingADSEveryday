#include <iostream>
#include <stack>
#include <vector>


using namespace std;

struct Node {
	int data;
	Node * prev, * next;
};

Node * newNode(int data) {
	Node * aNewNode = (Node *) malloc(sizeof(data));
	aNewNode->data = data;
	aNewNode->prev = aNewNode->next = NULL;
	
	return aNewNode;
}




void printInorderTree(Node *root) {
	if (root == NULL) return;
	printInorderTree(root->prev);
	cout << root->data << " ";
	printInorderTree(root->next);
}

void dellocateTree(Node * root) {
	if (root == NULL)
		return;

	if ( (root->prev == NULL) &&  (root->next == NULL) ) {
		root = NULL;
		free(root);
		return;
	}

	//if (root->left != NULL) 
	dellocateTree(root->prev);

	//if (root->right != NULL)
	dellocateTree(root->next);

	//root = NULL;
	//free(root);
}

Node * getMiddleNode(Node * head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	
	Node * prev_node = NULL;
	Node * next_node = head;
	
	while(next_node != NULL) {
		if (prev_node == NULL)
			prev_node = head;
		else 
			prev_node = prev_node->next;

		next_node = next_node->next;
		if (next_node == NULL) break;
		else next_node = next_node->next;
	}

	return prev_node;

}

Node * convertToTree(Node * head) {
	
	if (head == NULL) return NULL;
	
	Node * middleNode = getMiddleNode(head);

	if (middleNode== NULL) return NULL;

	if (middleNode->prev != NULL) {
		middleNode->prev->next = NULL;
		middleNode->prev = convertToTree(head);
	}

	if (middleNode->next != NULL) {
		middleNode->next->prev = NULL;
		middleNode->next = convertToTree(middleNode->next);
	}

	return middleNode;

}

void printList(Node * head) {
	if (head == NULL) return;

	Node * tmp = head;
	while( tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
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
	
	root->next = node2;
	root->prev = NULL;

	node2->next = node3;
	node2->prev = root;

	node3->next = node4;
	node3->prev = node2;

	node4->next = NULL;
	node4->prev = node3;
	
	//node5->prev = node4;
	//node5->next = NULL;

	
	Node * newRoot = convertToTree(root);
	printInorderTree(newRoot);
	cout << endl;

	dellocateTree(root);
	return 0;
}