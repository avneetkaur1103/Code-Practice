#include <iostream>
#include <stack>

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

void printBoundaryRight(struct Node* n){
	if(!n)
		return;

	if(n->right){
		printBoundaryRight(n->right);
		cout<<n->data<<" ";
	}
	else if(n->left){
		printBoundaryRight(n->left);
		cout<<n->data<<" ";
	}
}

void printBoundaryLeft(struct Node* n){
	if(!n)
		return;

	if(n->left){
		cout<<n->data<<" ";
		printBoundaryLeft(n->left);
	}
	else if(n->right){
		cout<<n->data<<" ";
		printBoundaryLeft(n->right);
	}
}

void printLeaf(struct Node* n){
	if(!n)
		return;
	printLeaf(n->left);

	if(!n->left && !n->right)
		cout<<n->data<<" ";

	printLeaf(n->right);
}

void boundary_traversal(struct Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	printBoundaryLeft(root->left);
	printLeaf(root->left);
	printLeaf(root->right);
	printBoundaryRight(root->right);
}

int main() 
{ 
    
    struct Node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
  
    boundary_traversal(root); 
  
    return 0; 
}

//Complexity: O(n)