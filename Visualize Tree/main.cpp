#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct Node {
	int data;
	Node * left, * right;
};

Node * newNode(int data) {
	Node * aNewNode = (Node *) malloc(sizeof(data));
	aNewNode->data = data;
	aNewNode->left = aNewNode->right = NULL;
	
	return aNewNode;
}


void dellocateTree(Node * root) {
	if (root == NULL)
		return;

	dellocateTree(root->left);

	dellocateTree(root->right);

	// Not sure why VS always throw error here
	cout << "freeing " << root->data << endl;
	free(root);
}


int getTreeHeight(Node * root) {
	int height = 0;
	int lHeight = 0;
	int rHeight = 0;

	
	if (root == NULL) return 0;

	if (root->left != NULL) 
		lHeight = getTreeHeight(root->left);

	if (root->right != NULL)
		rHeight = getTreeHeight(root->right);

	height = (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);

	return height;
}

int maxWidth(Node * root) {
	// assume now is 1
	return 1;
}


void writeDash(int number_of_padding, int boxWith) {
	for (int i = 0; i < number_of_padding; i++) {
		for (int j = 0; j < boxWith; j++) {
			cout << "_";
		}
	}
}


void writeSpace(int number_of_space, int boxWith) {
	for (int i = 0; i < number_of_space; i++) {
		for (int j = 0; j < boxWith; j++) {
			cout << " ";
		}
	}
}



void printVisualTree2(Node * root) {

	if (root == NULL) return;

	int boxWith = maxWidth(root);

	int treeHeight = getTreeHeight(root);

	int nodes_current_level = 1;
	int nodes_next_current_level = 2;
	int current_level = treeHeight;

	int padding_each_level = current_level;
	int dash_each_level = current_level;
	int offset_node = 1;

	queue<Node*> nodeQueue;
	//padding dash data dash padding

	nodeQueue.push(root);

	while(!nodeQueue.empty()) {
		
		Node * current_node = nodeQueue.front();
		nodeQueue.pop();

		if (current_level == 1) {
			dash_each_level = 1;
			padding_each_level = 1;
		}
		else if (current_level >= 2) {
			dash_each_level = pow(2,current_level-1);
			padding_each_level = dash_each_level - 1;
		}
		if (current_node == NULL) {
			// left of NULL
			writeSpace(padding_each_level,boxWith);
			writeSpace(boxWith,boxWith);
			writeSpace(dash_each_level,boxWith);

			// right of NULL
			writeSpace(padding_each_level,boxWith);
			writeSpace(boxWith,boxWith);
			writeSpace(dash_each_level,boxWith);

			//writeSpace(boxWith,boxWith);

		} else if (current_node != NULL) {

			if (current_node->left != NULL) {
				writeSpace(padding_each_level,boxWith);
				writeDash(dash_each_level,boxWith);
				cout << current_node->data;
				nodeQueue.push(current_node->left);
			} else if (current_node->left == NULL) {

				if (current_level > 1) {
					if (offset_node > 1)
						writeSpace(padding_each_level + dash_each_level + boxWith, boxWith);
					else if (offset_node == 1)						
						writeSpace(padding_each_level + dash_each_level, boxWith);
				} else if (current_level == 1) {
					if ( (offset_node <= nodes_next_current_level /4 ) || 
						 ( (offset_node >  nodes_next_current_level /4 ) && ( (offset_node % 2) == 0 ) )
					   )
						writeSpace(padding_each_level, boxWith);
				}
				
				cout << current_node->data;;
				nodeQueue.push(NULL);
			}

			if (current_node->right != NULL) {
				writeDash(dash_each_level,boxWith);
				writeSpace(padding_each_level,boxWith);
				nodeQueue.push(current_node->right);
			} else if (current_node->right == NULL) {
					writeSpace(padding_each_level + dash_each_level, boxWith);
				nodeQueue.push(NULL);
			}
		}
		nodes_current_level--; 
		offset_node++;

		if (nodes_current_level == 0)  { //end of this level
			cout << endl;
			nodes_current_level = nodes_next_current_level;	
			nodes_next_current_level = nodes_next_current_level * 2;
			current_level--;
			offset_node = 1;
		}
	} 
	
}

void printVisualTree(Node * root) {
	int height = getTreeHeight(root);
	
	const int box_size = 3;
	queue<Node *> q;
	q.push(root);

	size_t current_level_nodes = 1;
	size_t next_current_level_nodes = 0;
	size_t level = 1;
	int padding = box_size * (std::pow(2, height - level) - 1);
	
	cout << std::setw(padding / 2) << "";
	
	while (level <= height)
	{
		std::cout << std::setw(box_size);
		if (q.front() != NULL)
		{
			cout << q.front()->data;
			q.push(q.front()->left);
			q.push(q.front()->right);
		}
		else
		{
			std::cout << "";
			q.push(NULL);
			q.push(NULL);
		}
		next_current_level_nodes += 2;
		std::cout << std::setw(padding) << "";
		q.pop();
		--current_level_nodes;
		if (current_level_nodes == 0)
		{
			current_level_nodes = next_current_level_nodes;
			next_current_level_nodes = 0;
			++level;
			padding = box_size * (std::pow(2, height - level) - 1);
			std::cout << "\n" << std::setw(padding / 2) << "";
		}
	}
}

int main() {
	
	Node * root = newNode(1);
	Node * node2 = newNode(2);
	Node * node3 = newNode(3);
	Node * node4 = newNode(4);
	Node * node5 = newNode(5);
	Node * node6 = newNode(6);
	Node * node7 = newNode(7);
	
	root->left = node2;
	root->right = node5;

	node2->left = node3;
	node2->right = node4;

	//node5->left = node6;
	node5->right = node7;
	/*
	node6->left = node7;
*/

    printVisualTree(root);
	printVisualTree2(root);

	dellocateTree(root);
	return 0;
}