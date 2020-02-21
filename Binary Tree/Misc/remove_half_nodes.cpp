#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *nextRight;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->nextRight = NULL;
	return n;
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

Node* RemoveHalfNodes(Node* root){
	if(!root)
		return NULL;

	root->left = RemoveHalfNodes(root->left);
	root->right = RemoveHalfNodes(root->right);

	if(root->left == NULL && root->right == NULL)
		return root;

	if(root->left == NULL){
		Node* tmp1 = root->right;
		free(root);
		return tmp1;
	}

	if(root->right == NULL){
		Node* tmp2 = root->left;
		free(root);
		return tmp2;
	}
	return root;
}

int main(){

    struct Node *root = newNode(2); 
    root->left        = newNode(7); 
    root->right       = newNode(5); 
    root->left->right = newNode(6); 
    root->left->right->left=newNode(1); 
    root->left->right->right=newNode(11); 
    root->right->right=newNode(9); 
    root->right->right->left=newNode(4);

    Node* nroot = NULL;

    nroot = RemoveHalfNodes(root);
    inOrder(nroot);
    return 0;
}

//Complexity:O(n)