#include <iostream>

using namespace std;

struct Node {
	int data;
	Node * next;
};


void printList(Node * head) {
	if (head == NULL) return;

	Node * tmp = head;
	while( tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void dellocateList(Node * head) {
	if (head == NULL) return;
	dellocateList(head->next);

	free(head);
}

Node * newNode(int data) {
	Node * tmp = (Node *) malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;

	return tmp;
}


void removeDuplicate(Node * root) {
	if (root == NULL) return;
	if (root->next == NULL) return;

	Node * startLoop = root;
	Node * endLoop = startLoop->next;

	while (endLoop != NULL) {
		while( (endLoop != NULL) && (endLoop->data == startLoop->data) ) {
			startLoop->next = endLoop->next;
			free(endLoop);
			endLoop = startLoop->next;
		}
		startLoop = endLoop;
		if (startLoop == NULL) break;
		endLoop = startLoop->next;
	}

}


int main() {

	Node * node2a = newNode(2);
	Node * node2b = newNode(2);
	Node * node3 = newNode(3);
	Node * node5 = newNode(5);
	Node * node7 = newNode(7);
	Node * node11a = newNode(11);
	Node * node11b = newNode(11);
	
	node2a->next = node2b;
	node2b->next = node3;
	node3->next = node5;
	node5->next = node7;
	node7->next = node11a;
	node11a->next = node11b;

	printList(node2a);

	removeDuplicate(node2a);

	printList(node2a);
	return 0;
}
