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

Node * interLeaveList(Node * head1, Node * head2) {
	if (head1 == NULL)
		return head2;
	
	if (head2 == NULL)
		return head1;

	Node * prevHead1 = NULL;
	Node * tHead1 = head1;

	Node * prevHead2 = NULL;
	Node * tHead2 = head2;

	while (tHead1 != NULL && tHead2 != NULL) {
		prevHead1 = tHead1;
		tHead1 = tHead1->next;

		prevHead1->next = tHead2;
		
		prevHead2 = tHead2;
		tHead2 = tHead2->next;

		prevHead2->next = tHead1;
	
	}

	return head1;


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

	Node * node9 = newNode(9);
	node8->next = node9;

	
	
	printList(head);
	printList(head2);

	head = interLeaveList(head,head2);
	printList(head);
	dellocateList(head);
	//dellocateList(head2);
	return 0;

	
}