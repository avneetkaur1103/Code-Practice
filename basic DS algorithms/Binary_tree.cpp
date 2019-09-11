#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create_node(int k){
	struct node *n = (struct node*) malloc(sizeof(struct node));
	n->data = k;
	n->left = NULL;
	n->right = NULL;
	return(n);
}

int main(){
	struct node *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	return 0;
}