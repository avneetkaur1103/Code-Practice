#include <iostream>
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

int sumTree(struct Node* root){
	int sum=0;

	if(root == NULL)
		return 0;

	int old_val = root->data;

	sum = sumTree(root->left) + sumTree(root->right);

	root->data = sum;

	return old_val+root->data;
}

void Inorder(struct Node* root){
	if (!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	struct Node* root = newNode(10);
	root->left        = newNode(-2); 
    root->right       = newNode(6); 
    root->left->left  = newNode(8); 
    root->left->right = newNode(-4); 
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    sumTree(root);
    Inorder(root);
    return 0;
}

//Complexity: O(n)