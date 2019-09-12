#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data){
	struct Node *n= (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

bool isFoldableUtil(struct Node *n1, struct Node *n2){
	if(n1 == NULL && n2 == NULL)
		return true;

	if(n1 == NULL || n2 == NULL)
		return false;

	return (isFoldableUtil(n1->left,n2->right) && isFoldableUtil(n1->right,n2->left));
}

bool isFoldable(struct Node *root){
	if(root == NULL)
		return true;

	return isFoldableUtil(root->left,root->right);
}

int main(){
	struct Node* root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(4);
	root->left->left = newNode(1);
	//root->left->right = newNode(3);
	root->right->right = newNode(5);
	isFoldable(root) ? cout<<"Yes" : cout<<"No";
	return 0;
}

//Complexity: O(n)