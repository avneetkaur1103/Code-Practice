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

int max_height(struct node* n){
		if (n == NULL)
			return 0;
		else{
			int lh = max_height(n->left);
			int rh = max_height(n->right);
			
			if (lh > rh)
				return (lh+1);
			else
				return (rh+1);
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
	
	cout<< "Max Height: " << max_height(root);
	
	return 0;
}

Complexity: O(n)