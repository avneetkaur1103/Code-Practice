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

void convertTree(struct Node *root){
	if(!root)
		return;
	convertTree(root->left);
	convertTree(root->right);

	if(root->left && root->right){
		root->data = root->left->data & root->right->data;
	}
}

void Inorder(struct Node* root){
	if (!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	struct Node *root=newNode(0); 
    root->left=newNode(1); 
    root->right=newNode(0); 
    root->left->left=newNode(0); 
    root->left->right=newNode(1); 
    root->right->left=newNode(1); 
    root->right->right=newNode(1);
    convertTree(root);
    Inorder(root);
    return 0;
}

//Complexity: O(n)