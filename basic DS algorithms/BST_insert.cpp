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

struct node* insert(struct node *n,int key){
	if (n == NULL)
		return new_node(key);
	if (key < n->data)
		n->left = insert(n->left, key);
	else if (key > n->data)
		n->right = insert(n->right, key);
	return n;
}

void inorder(struct node* root){
	if (root != NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main() {
	struct node *root = NULL;
	root = insert(root,7);
	insert(root, 3);
	insert(root, 8);
	insert(root, 5);
	insert(root, 10);
	insert(root, 12);
	inorder(root);

	return 0;
}

Time Complexity (Worst case): O(n)