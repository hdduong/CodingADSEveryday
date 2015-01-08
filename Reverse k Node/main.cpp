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


void swapNode(Node * start, int i, int j) {
	if (i == j) return;
	Node * nodeI = start;
	Node * nodeJ = start;
	int k = 0;
	while( k < i) {
		nodeI = nodeI->next;
		nodeJ = nodeJ->next;
		k++;
	}

	while (k < j) {
		nodeJ = nodeJ->next;
		k++;
	}
	
	int tmp = nodeI->data;
	nodeI->data = nodeJ->data;
	nodeJ->data = tmp;
}

// 0(nk) complexity
void reverseKNode(Node * head, int k) {
	if (head == NULL) return;

	int startCount = 0;
	int endCount = 1;
	Node * nodeStart = head;
	Node * nodeEnd = head;	
	
	while(nodeStart != NULL) {
		while ( (endCount < k) && (nodeEnd->next != NULL) ) {
			endCount++;
			nodeEnd = nodeEnd->next;
		}
		endCount--;
		while (endCount > startCount) {
			swapNode(nodeStart,startCount++,endCount--);
		}
		nodeStart = nodeEnd->next;
		nodeEnd = nodeEnd->next;
		startCount = 0;
		endCount = 1;
	}

}

Node *  reverseKList (Node * head, int k) {
	Node * rHead = head;
	Node * prevCurrent = NULL;
	Node * current = head;
	Node * nextCurrent = NULL;

	int numberNode = 0;

	if (head == NULL) return NULL;
	if ( (head)->next == NULL) return head;

	//reach here mean head->next != NULL
	nextCurrent = current->next;

	while( (current!= NULL) && (numberNode < k) ) {
		numberNode++;
		current->next = prevCurrent;
		prevCurrent = current;
		current = nextCurrent;
		if (nextCurrent != NULL)
			nextCurrent = current->next;
	}

	rHead->next = reverseKList(current,k);

	return prevCurrent;
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
	/*
	Node * node5 = newNode(5);
	node4->next = node5;

	Node * node6 = newNode(6);
	node5->next = node6;

	Node * node7 = newNode(7);
	node6->next = node7;*/

	//reverseKNode(head, 3);
	head = reverseKList(head,3);
	printList(head);

	dellocateList(head);
	return 0;

	
}