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

void increment(struct Node* root, int diff){
	if(root->left!= NULL){
		root->left->data += diff;
		increment(root->left,diff);
	}
	else if (root->right != NULL){
		root->right->data += diff;
		increment(root->right, diff);
	}
}

void childrenSumPropertyTree(struct Node* root){
	int right_data=0, left_data = 0, diff = 0;

	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;

	childrenSumPropertyTree(root->left);
	childrenSumPropertyTree(root->right);

	if(root->left != NULL)
		left_data = root->left->data;

	if(root->right != NULL)
		right_data = root->right->data;

	diff = (left_data + right_data) - root->data;

	if(diff > 0){
		root->data += diff;
	}
	else if (diff < 0)
		increment(root, -diff);
}

void Inorder(struct Node* root){
	if (!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	struct Node* root = newNode(50);
	root->left        = newNode(7); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(1);
    root->right->right = newNode(30);
    childrenSumPropertyTree(root);
    Inorder(root);
    return 0;
}

//Complexity: O(n^2)