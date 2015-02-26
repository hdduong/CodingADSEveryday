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

void doEvenOddMerge(Node * root) {
	if (root == NULL) return;
	if (root->next == NULL) return;

	Node * headEven = root;
	Node * tailEven = root;


	Node * headOdd = root->next;
	Node * tailOdd = root->next;

	
	while ( (tailEven != NULL) && (tailOdd != NULL)) {
		tailEven->next = tailOdd->next;
		if (tailEven->next != NULL) {
			tailEven = tailEven->next;
		
			tailOdd->next = tailEven->next;
			tailOdd = tailOdd->next;
		}
		else break;
	}

	if (tailEven != NULL) tailEven->next = headOdd;
	if (tailOdd != NULL) tailOdd->next = NULL;
}

int main() {

	Node * head = newNode(0);
	Node * node1 = newNode(1);
	head->next = node1;

	Node * node2 = newNode(2);
	node1->next = node2;

	Node * node3 = newNode(3);
	node2->next = node3;
	
	Node * node4 = newNode(4);
	node3->next = node4;

	Node * node5 = newNode(5);
	node4->next = node5;

	/*
	Node * node5 = newNode(5);
	node4->next = node5;

	Node * node6 = newNode(6);
	node5->next = node6;

	Node * node7 = newNode(7);
	node6->next = node7;*/

	//reverseKNode(head, 3);
	
	printList(head);

	doEvenOddMerge(head);

	printList(head);
	dellocateList(head);
	return 0;

	
}

