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

bool isMirror(struct Node *n1,struct Node *n2){
	if (n1 == NULL && n2 == NULL)
		return true;

	if(n1 && n2 && n1->data == n2->data)
		return (isMirror(n1->left,n2->right) && isMirror(n1->right, n2->left));

	return false;
}

bool isSymmetric(struct Node *root){
	if (root == NULL)
		return true;
	return isMirror(root,root);
}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);
	isSymmetric(root) ? cout<<"Yes" : cout<<"No";
	return 0;
}

