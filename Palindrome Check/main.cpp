#include <iostream>

using namespace std;

struct Node {
	char data;
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

Node * newNode(char data) {
	Node * tmp = (Node *) malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;

	return tmp;
}

bool isPalindrome(Node ** head, Node * last) {
	if (head == NULL)
		return true;

	if ((head != NULL) && (last == NULL))
		return true;

	bool palCheck = isPalindrome(head, last->next);
	if (!palCheck) return false;

	if (palCheck) {
		//if (last == NULL) return true;

		if ((*head)->data == last->data) {
			*head = (*head)->next;
			return true;
		}
		else return false;
	}

	return false;
}

int main() {

	Node * head = newNode('0');
	Node * last = head;

	Node * node1 = newNode('0');
	head->next = node1;

	Node * node2 = newNode('1');
	node1->next = node2;

	Node* tHead = head;
	bool checkPal = isPalindrome(&head,last);
	cout << ( (checkPal == 1) ? "True" : "False" ) << endl; 



	/*
	Node * node3 = newNode('3');
	node2->next = node3;
	
	Node * node4 = newNode('4');
	node3->next = node4;
	
	Node * node5 = newNode('5');
	node4->next = node5;
*/
	printList(tHead);
	dellocateList(tHead);
}