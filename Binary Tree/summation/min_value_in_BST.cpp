#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int findMin(Node* root){
	//min is BST is left most leaf node
	if(!root)
		return -1;

	Node* curr = root;

	while(curr->left != NULL){
		curr = curr->left;
	}

	return curr->data;
}

int main(){
	Node* root = newnode(20);
	root->left = newnode(8);
	root->left->left = newnode(4);
	root->left->right = newnode(12);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(14);
	root->right = newnode(22);

	cout<<findMin(root);
}