#include <iostream>

using namespace std;

struct Node {
	char data;
	Node * next;
	Node * jump;
};

Node * createNewNode(char _data) {
	Node * aNewNode = (Node*)malloc(sizeof(Node));
	aNewNode->data = _data;
	aNewNode->next = NULL;
	aNewNode->jump = NULL;

	return aNewNode;
}

void deleteList(Node * head) {
	if (head == NULL) return;

	deleteList(head->next);

	free(head);
}

void printPostingList(Node * head) {
	while (head) {
		cout << head->data << " ";
		if (head->next) cout << head->next->data << " ";
		if (head->jump) cout << head->jump->data << " ";
		cout << endl;
		head = head->next;
	}
}
Node * copyList(Node* source) {
	if (source == NULL) return NULL;

	if (source->next == NULL) return source;

	Node * next = source->next;
	Node * current = source;
	Node * prev = NULL;
	Node * dest = NULL;

	while(current) {
		Node * newCopy = createNewNode(current->data);
		if (dest == NULL)	 {
			dest = newCopy;
			dest->next = next;
			dest->jump = current->jump;
			current->next = dest;
		} else {
			newCopy->next = next;
			current->next = newCopy;
			newCopy->jump = current->jump;

			//prev->next->next = newCopy;
		}
		//prev = current;
		
		if (next != NULL) {
			current = next;
			next = next->next;
		}
		else if (next == NULL) { // last node links to 2nd list
			current->next = newCopy;
			current = next;
		}
		
		
	}
	//printPostingList(dest);

	// copy jump node
	current = source;
	while (current && current->next && current->next->next) {
		current->next->jump = current->jump->next;
		
		current = current->next->next;
	}
	

	//printPostingList(dest);

	//copy next node;
	current = source;
	while (current && current->next && current->next->next) {
		next = current->next->next;
		current->next->next = next->next;
		current->next = next;

		current = current->next;
	}
	current->next = NULL; // reset last node

	//printPostingList(dest);
	return dest;
}


int main() {
	Node * nodeA = createNewNode('a');
	Node * nodeB = createNewNode('b');
	Node * nodeC = createNewNode('c');
	Node * nodeD = createNewNode('d');

	nodeA->next = nodeB;
	nodeB->next = nodeC;
	nodeC->next = nodeD;

	nodeA->jump = nodeC;
	nodeB->jump = nodeD;
	nodeD->jump = nodeD;
	nodeC->jump = nodeB;

	Node * dest = copyList(nodeA);
	printPostingList(dest);
	deleteList(nodeA);
	deleteList(dest);
	return 0;
}