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

Node * copyN1List(Node * head) {
	if (head == NULL) return NULL;

	if (head->next == NULL) return NULL;

	Node * aNewNode = newNode(head->data);
	aNewNode->next = copyN1List(head->next);
	return aNewNode;
}

void reserveList (Node ** head) {
	Node * prevCurrent = NULL;
	Node * current = *head;
	Node * nextCurrent = NULL;

	if (*head == NULL) return;
	if ( (*head)->next == NULL) return;

	//reach here mean head->next != NULL
	nextCurrent = current->next;

	while(current!= NULL) {
		current->next = prevCurrent;
		prevCurrent = current;
		current = nextCurrent;
		if (nextCurrent != NULL)
			nextCurrent = current->next;
	}
	*head = prevCurrent;
}

Node * appendList(Node *head1, Node * head2) {
	Node * prevHead1 = NULL;
	Node * newHead1 = head1;

	while(newHead1 != NULL) {
		prevHead1 = newHead1;
		newHead1 = newHead1->next;	
	}
	prevHead1 ->next = head2;

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

	Node * newList = copyN1List(head);
	
	reserveList(&newList);
	head = appendList(head,newList);

	printList(head);
	printList(newList);

	dellocateList(head);
	//dellocateList(newList);
	return 0;

	
}