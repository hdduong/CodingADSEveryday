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

void reverseList (Node ** head) {
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

Node * sumTwoList(Node * head1, Node * head2) {
	
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	reverseList(&head1);
	reverseList(&head2);
	
	int carry = 0;
	int sum = 0;

	Node * result = NULL;

	while ( (head1 != NULL) ||  (head2 != NULL)) {
		
		int data1 = 0;
		int data2 = 0;

		if (head1 == NULL) data1 = 0;
		else data1 = head1->data;
		
		if (head2 == NULL) data2 = 0;
		else data2 = head2->data;

		Node * aNewNode = newNode(data1 + data2 + carry);
		carry = aNewNode->data / 10;
		aNewNode->data = aNewNode->data % 10;

		if (result == NULL)
			result = aNewNode;
		else {
			aNewNode->next = result;
			result = aNewNode;
		}
		if (head1 != NULL)  head1 = head1->next;
		if (head2 != NULL)  head2 = head2->next;
	}
	
	// both NULL, check carry
	if (carry != 0) {
		Node * aNewNode = newNode(carry);
		aNewNode->next = result;
		result = aNewNode;
	}

	return result;
}

// assume that head always == NULL
Node * insertTail(Node * head, int count) { 
	
	Node * tmpResult = NULL;
	while (count > 0) {
		count--;
		
		Node * aNewNode = newNode(0);
		if (tmpResult == NULL) tmpResult = aNewNode;
		else {
			aNewNode->next = tmpResult;
			tmpResult = aNewNode;
		}
	}

	return tmpResult;
}


Node * productTwoList(Node * head1, Node * head2) {
	
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	
	reverseList(&head1);
	reverseList(&head2);
	
	Node * rHead1 = head1;
	Node * rHead2 = head2;
	

	int carry = 0;
	int sum = 0;

	Node * resultList = NULL;
	Node * tmpResult = NULL;

	int countHead2 = 0;
	while  (head2 != NULL) {

		if (countHead2 != 0) {
			tmpResult = insertTail(tmpResult,countHead2);			
		}

		while (head1 != NULL) {
			int data1 = head1->data;
			int data2 = head2->data;

			int productResult = (data1 * data2) + carry;
			carry = productResult / 10;
			int saveResult = productResult % 10;

			Node * aNewNode = newNode(saveResult);

			if (tmpResult == NULL) tmpResult = aNewNode;
			else {
				aNewNode->next = tmpResult;
				tmpResult = aNewNode;
			}

			head1 = head1->next;
		}
		// here mean head1 = NULL;
		if (carry != 0) {
			Node * aNewNode = newNode(carry);
			aNewNode->next = tmpResult;
			tmpResult = aNewNode;
		}
		carry = 0;

		resultList = sumTwoList(resultList,tmpResult);

		countHead2++;
		head1 = rHead1;
		tmpResult = NULL;
		head2 = head2->next;
	}
	

	return resultList;
}


int main() {
	Node * head = newNode(2);

	Node * node1 = newNode(3);
	head->next = node1;

	Node * head2 = newNode(8);
	
	Node * node2 = newNode(9);
	head2->next = node2;

	Node* result = productTwoList(head, head2);
	printList(result);

	dellocateList(head);
	dellocateList(head2);
	dellocateList(result);
	return 0;
}