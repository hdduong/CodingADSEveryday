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

size_t listLength(Node * head) {
	int length = 0;
	while (head != NULL) {
		length++;
		head = head->next;
	}
	return length;
}

Node * findMergeNode(Node * head1, Node * head2) {
	size_t listLen1 = listLength(head1);
	size_t listLen2 = listLength(head2);

	size_t lenDiff = (listLen1 > listLen2) ? (listLen1 - listLen2) : (listLen1 - listLen2);

	Node* startNode1 = (listLen1 > listLen2) ? head1 : head2;
	Node* startNode2 = (listLen1 > listLen2) ? head2 : head1;

	while(lenDiff > 0) {
		startNode1 = startNode1->next;
		lenDiff--;
	}
	
	while( (startNode1 != NULL) && (startNode2 != NULL)) {
		if (startNode1 != startNode2) {
			startNode1 = startNode1->next;
			startNode2 = startNode2->next;
		}
		else 
			return startNode1;
	}
		
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

	Node * node6 = newNode(6);
	node5->next = node6;

	Node * head2 = newNode(7);
	Node * node8 = newNode(8);
	head2->next = node8;
	node8->next = node3;

	Node * nodeMerge = findMergeNode(head,head2);
	cout << nodeMerge->data << endl;
	//printList(head);

	dellocateList(head);
	return 0;

	
}