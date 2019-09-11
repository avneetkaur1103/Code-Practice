#include <iostream>
using namespace std;

struct Node{
	int data;
	int liss;
	struct Node *left, *right;
};

struct Node* createNode(int data){
	struct Node* new_node = new Node();
	new_node->left = new_node->right = NULL;
	new_node->data = data;
	new_node->liss =0;
	return new_node;
}

int max(int a, int b){
	return (a>b)?a:b;
}

int LISS(Node * root){
	if (root == NULL)
		return 0;
		
	if(root->liss)
		return root->liss;
		
	if (root->left == NULL &&  root->right == NULL)
		return (root->liss = 1);
	
	int size_excl_root = LISS(root->left) + LISS(root->right);
	int size_incl_root = 1;
	
	if(root->left)
		size_incl_root += LISS(root->left->left) + LISS(root->left->right);
	if(root->right)
		size_incl_root += LISS(root->right->left) + LISS(root->right->right);
		
	root->liss = max(size_incl_root,size_excl_root);
	return root->liss;
}

int main() {
	Node *root = createNode(20);
	root->left = createNode(8);
	root->left->left = createNode(4);
	root->left->right = createNode(12);
	root->left->right->left = createNode(10);
	root->left->right->right = createNode(14);
	root->right = createNode(22);
	root->right->right = createNode(25);
	
	cout<<"Size of LISS: " << LISS(root);
	return 0;
}

//Complexity:O(n)