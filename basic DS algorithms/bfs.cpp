#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

struct node* new_node(int data){
	struct node *node1 = (struct node*)malloc(sizeof(struct node));
	node1->data = data;
	node1->left = node1->right = NULL;
	return(node1);
}

int height(struct node *node){
	if (node == NULL)
		return 0;
	
	int lh = height(node->left);
	int rh = height(node->right);
	
	if (lh > rh)
		return (lh+1);
	else
		return (rh+1);
}

void print_level(struct node *node, int level){
	
	if (level == 0)
		return;
	
	if (level == 1)
		printf("%d\t", node->data);
	else if (level > 1){
		print_level(node->left, level-1);
		print_level(node->right, level-1);
	}
}

void find_level(struct node *node){
	if (node == NULL)
		return;
	else{
		int h = height(node);
		for (int i=0; i<=h; i++)
			print_level(node,i);
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
	
	find_level(root);
	
	return 0;
}