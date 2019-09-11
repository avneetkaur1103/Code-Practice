#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	int vc;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->vc =0;
	return n;
}

int min(int a, int b){
	return (a<b)?a:b;
}

int vCover(struct Node *root){
	if (root == NULL)
		return 0;
		
	if(root->left == NULL || root->right == NULL)
		return 0;
		
	int size_inc =0, size_exc = 0;
	
	if(root->vc != 0)
		return root->vc;
	
	size_inc = 1 + vCover(root->left) + vCover(root->right);
	
	if(root->left)
		size_exc += 1 + vCover(root->left->left) + vCover(root->left->right);
	if(root->right)
		size_exc += 1 + vCover(root->right->left) + vCover(root->right->right);
		
	return min(size_exc, size_inc);
}


int main() {
	struct Node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25);
    
    cout<<"Size of smallest Vertex cover: " << vCover(root);
	return 0;
}

//Complexity: O(V)