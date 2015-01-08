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

void reverseListRecursiveHelper(Node ** head, Node * prev, Node *current) {
	if (current == NULL) return;

	if (current->next == NULL) {
		*head = current;
		current->next = prev;
		return;
	}
	
	Node * tmpPrev = prev;
	prev = current;
	current = current->next;
	reverseListRecursiveHelper(head, prev, current);

	current->next = prev;
	if (prev != NULL)
		prev->next = tmpPrev;
}

void reverseListRecursive(Node **head) {
	if (*head == NULL)
		return;

	Node * prev = NULL;
	Node * current = *head;

	reverseListRecursiveHelper(head, prev, current);
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


int main() {

	Node * head = newNode(0);
	Node * node1 = newNode(1);
	head->next = node1;
	Node * node2 = newNode(2);
	node1->next = node2;

	reserveList(&head);
	printList(head);
	
	cout << endl;

	reverseListRecursive(&head);

	printList(head);

	dellocateList(head);
	return 0;

	
}