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


//int main() {
//
//	Node * head = newNode(0);
//	Node * node1 = newNode(1);
//	head->next = node1;
//
//	Node * node2 = newNode(2);
//	node1->next = node2;
//
//	Node * node3 = newNode(3);
//	node2->next = node3;
//	
//	Node * node4 = newNode(4);
//	node3->next = node4;
//	/*
//	Node * node5 = newNode(5);
//	node4->next = node5;
//
//	Node * node6 = newNode(6);
//	node5->next = node6;
//
//	Node * node7 = newNode(7);
//	node6->next = node7;*/
//
//	//reverseKNode(head, 3);
//	head = reverseKList(head,3);
//	printList(head);
//
//	dellocateList(head);
//	return 0;
//
//	
//}

// From here is the 2nd method: IMPROVEMENT
// reverse K node from nodeStart to nodeEnd
void reverseKNodeHelper(Node ** nodeStart, Node ** nodeEnd) {
	Node * rHead = *nodeStart;
	Node * curr_node = *nodeStart;
	Node * prev_node = (*nodeEnd)->next;

	if (curr_node->next == NULL) {
		return;
	}

	Node * next_node = curr_node->next;

	while(next_node != *nodeEnd) {
		curr_node->next = prev_node;
		prev_node = curr_node;

		curr_node = next_node;
		next_node = next_node->next;
	}
	curr_node->next = prev_node;
	next_node->next = curr_node;

	*nodeEnd = rHead;
	*nodeStart = next_node;
	
}

Node *  reverseKNode_2(Node * head, int k) {
	int count  = 0;

	if (head == NULL) return head;
	if (head->next == NULL) return head;
	
	Node * startSection = head;
	Node * endSection = head;
	Node * newHead = NULL;
	Node * connectNode = NULL;

	while(endSection != NULL) {
		count++; 
		if (count == k)  {

			if (connectNode) {
				connectNode = newHead;
				while( connectNode->next != startSection)
					connectNode = connectNode->next;
			} else {
				connectNode = head;
			}
			
			reverseKNodeHelper(&startSection, &endSection);
			
			if (!newHead) newHead = startSection;
			else connectNode->next = startSection;

			startSection = endSection->next;
			
			count = 0;
		}
		endSection = endSection->next;	
	}
	return newHead;
}




int main() {
	// 3->2->2>11->7->5->11
	Node * head = newNode(3);
	Node * node1 = newNode(2);
	head->next = node1;

	Node * node2 = newNode(2);
	node1->next = node2;

	Node * node3 = newNode(11);
	node2->next = node3;
	
	Node * node4 = newNode(7);
	node3->next = node4;
	
	Node * node5 = newNode(5);
	node4->next = node5;

	Node * node6 = newNode(11);
	node5->next = node6;

	//printList(head);
	//reverseKNodeHelper(&head, &node2);
	head = reverseKNode_2(head, 3);

	printList(head);

	dellocateList(head);
	return 0;


	return 0;
}