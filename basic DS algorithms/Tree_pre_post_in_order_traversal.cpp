#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
	node(int data){
		this->data = data;
		left = right = NULL;
	}
};

void InOrder(struct node *node){
	if (node == NULL)
		return;
	
	InOrder(node->left);
	printf("%d\t", node->data);
	InOrder(node->right);
}

void PreOrder(struct node *node){
	if (node == NULL)
		return;
		
	printf("%d\t", node->data);
	PreOrder(node->left);
	PreOrder(node->right);
}

void PostOrder(struct node *node){
	if (node == NULL)
		return;
	
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d\t", node->data);
	
}

int main() {
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	InOrder(root);
	printf("\n");
	PreOrder(root);
	printf("\n");
	PostOrder(root);
	return 0;
}

Time complexity: O(n)