#include <iostream>
#include <list>
using namespace std;

int max_depth, sum;

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

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

Node* deleteLeaves(Node* root, int n){
	if(!root)
		return NULL;

	root->left = deleteLeaves(root->left,n);
	root->right = deleteLeaves(root->right,n);

	if(root->data == n && root->left == NULL && root->right == NULL){
		delete(root);
		return NULL;
	}
	return root;
}

int main() 
{ 
    struct Node* root = newNode(10); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(3); 
    root->left->right = newNode(1); 
    root->right->right = newNode(3); 
    root->right->right->left = newNode(3); 
    root->right->right->right = newNode(3); 
    root = deleteLeaves(root, 3);
    inOrder(root);
    return 0;
}

//Complexity:O(n)
//Microsoft