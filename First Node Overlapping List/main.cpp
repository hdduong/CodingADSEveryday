#include <iostream>

using namespace std;

// Test overlapping list - List might have cycle
struct Node {
	int data;
	Node * next;
};


Node * testCycle (Node *root);
void dellocateListHelper(Node * head);



Node * newNode(int data) {
	Node * aNode = (Node*)malloc(sizeof(Node) );
	aNode->data = data;
	aNode->next = NULL;

	return aNode;
}


void dellocateList(Node * head) {
	if (head == NULL) return;

	Node * cycleNode = testCycle(head);
	if (cycleNode == NULL) { 
		dellocateListHelper(head);
		return;
	}
	else {
		while (head->next != cycleNode) {
			head = head->next;
		}
		head->next = NULL;
		dellocateListHelper(head);
		return;
	}
}

void dellocateListHelper(Node* head) {
	
	if (head == NULL) return;
	
	dellocateListHelper(head->next);

	free(head);

}
// Test if cycle happen.
// Retun NULL if no cycle
Node * testCycle (Node *root) {
	if (root == NULL) return NULL;

	if (root->next == NULL) return NULL;

	Node * slow = root;
	Node * fast = root;

	

	// if cycle will break with fast = NULL
	while ( (fast != NULL) ) {
		fast = fast->next;

		if (fast == slow) break;
		slow = slow->next;

		if (fast != NULL) {
			fast = fast->next;
			if (fast == slow) break;
		}
	}

	if (fast != NULL) return fast;

	return NULL;
}


int getCycleLength(Node *root, Node * cycle) {
	
	if (root == NULL) return 0;

	int lengthCycle = 1;
	Node * tmpNode = cycle->next;
	while(tmpNode != cycle) {
		tmpNode = tmpNode->next;
		lengthCycle++;
	}

	return lengthCycle;
}


// set both pointers back to head
// do advance fast
// meet again -> startNode
Node * getStartCycleNode(Node * root, int cycleLength) {
	if (root == NULL) return NULL;

	Node * fast = root;
	Node * slow = root;

	int advanceFastCount = 0;
	while(advanceFastCount != cycleLength) {
		fast = fast->next;
		advanceFastCount++;
	}

	while(1) {
		if (fast == slow) break;
		fast = fast->next;		
		slow = slow->next;
	}
	
	return fast;
}

Node * testCycleOverLappingList(Node * root1, Node * root2) {
	Node * cycle1 = testCycle(root1);
	Node * cycle2 = testCycle(root2);

	// one cycle, one not => no overlap
	// both cycle then have to meet
	if (cycle1 && cycle2) {
		int cycleLength1= getCycleLength(root1,cycle1);
		Node * startNode1 = getStartCycleNode(root1,cycleLength1);

		int cycleLength2= getCycleLength(root2,cycle2);
		Node * startNode2 = getStartCycleNode(root2,cycleLength2);
		
		Node * nodeTmp = startNode1->next;
		while(nodeTmp != startNode1) {
			if (nodeTmp == startNode2) break;
			nodeTmp = nodeTmp->next;
		}
		if (nodeTmp == startNode2) return  nodeTmp;

	}
	else {

		return NULL;
	}

	return NULL;
}
int main() {
	//EPI figure P 21.1

	// cycle at root;
	Node * node1 = newNode(1);
	Node * node2 = newNode(2);
	Node * node3 = newNode(3);
	Node * node4 = newNode(4);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node1;

	// cycle at root;
	Node * node7 = newNode(7);
	Node * node8 = newNode(8);
	
	node8->next = node2;
	

	Node * cycle = testCycleOverLappingList(node1,node2);
	if (cycle == NULL) cout << "NULL" << endl; 
	else { 
		cout << cycle->data << endl;
		
	}

	dellocateList(node1);
	// cycle not at root

	return 0;
}