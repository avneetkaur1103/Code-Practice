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

void Inorder(struct Node* root){
	if (!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void mirrorTree(struct Node* root){
	if(!root)
		return;
	mirrorTree(root->left);
	mirrorTree(root->right);

	struct Node* tmp=NULL;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

int main(){
	struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);
    mirrorTree(root);
    Inorder(root);
    return 0;
}

//complexity: O(n)