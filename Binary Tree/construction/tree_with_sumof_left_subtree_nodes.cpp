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

int updateTree(struct Node* root){
	int left_sum=0,right_sum =0;

	if(root == NULL)
		return 0;

	if(root->left == NULL && root->right == NULL)
		return root->data;

	left_sum = updateTree(root->left);
	right_sum = updateTree(root->right);

	root->data += left_sum;

	return right_sum+root->data;
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
	root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    updateTree(root);
    Inorder(root);
    return 0;
}

//Complexity: O(n)	