#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

Node* flipTree(struct Node* root){
	if(!root)
		return NULL;
	if(!root->left && !root->right)
		return root;

	Node* flippedNode = flipTree(root->left);

	root->left->left = root->right;
	root->left->right = root;
	root->left = root->right = NULL;
	return flippedNode;
}

void Inorder(struct Node* root){
	if (!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6); 
    root->right->right = newNode(7);

    root = flipTree(root);
    Inorder(root);
    return 0;
}

//Complexity: O(n)