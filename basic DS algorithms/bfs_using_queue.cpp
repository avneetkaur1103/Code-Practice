#include <iostream>
#include <queue>
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

void print_tree(node* n){
	if (n == NULL)
		return;
	
	queue <node *> q;
	q.push(n);
	
	while (q.empty() == false){
		node *node1 = q.front();
		cout<< node1->data << " ";
		q.pop();
		
		if (node1->left != NULL)
			q.push(node1->left);
		
		if(node1->right != NULL)
			q.push(node1->right);
	}
}

int main() {
	
	struct node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	
	print_tree(root);
	
	return 0;
}

Complexity: O(n)