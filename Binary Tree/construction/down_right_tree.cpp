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

void convertTree(struct Node* root){
	if(!root)
		return;

	convertTree(root->left);
	convertTree(root->right);

	if(root->left == NULL)
		root->left = root->right;
	else
		root->left->right = root->right;

	root->right = NULL;
}

void printDownRight(struct Node* root){
	if(root != NULL){
		cout<<root->data<<" ";
		printDownRight(root->right);
		printDownRight(root->left);
	}
}


int main(){
	struct Node* root = newNode(1);
	root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(8);

    convertTree(root);
    printDownRight(root);
    return 0;
}

//Complexity: O(n)