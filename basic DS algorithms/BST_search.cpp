#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

struct node* new_node(int data){
	struct node* node1 = (struct node*)malloc(sizeof(struct node));
	node1->data = data;
	node1->left = NULL;
	node1->right = NULL;
	return (node1);
}

struct node* search(struct node* n, int key){
	if (n == NULL || n->data == key)
		return n;
	
	if(n->data < key)
		search(n->left, key);
	else if (n->data > key)
		search(n->right, key);
}

int main() {
	struct node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	
	search(root, 6);

	return 0;
}

Time Complexity (Worst case): O(n)