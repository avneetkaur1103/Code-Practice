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

Node* firstp = NULL;
Node* secondp = NULL;

void swap(Node** a,Node** b){
	Node* tmp = *a;
	*a = *b;
	*b = tmp;
}

void pairwiseSwap(Node* root, int &count){
	if(!root)
		return;

	if(!root->left && !root->right){
		secondp = root;
		count++;
	
		if(count %2 == 0)
			swap(firstp,secondp);
		else
			firstp = secondp;
	}

	if(root->left)
		pairwiseSwap(root->left,count);
	if(root->right)
		pairwiseSwap(root->right,count);
}

int main(){
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(8); 
    root->right->left->left = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->left = newNode(9); 
    root->right->right->right = newNode(10);
    int count =0;
   	pairwiseSwap(root,count);
    inOrder(root);
    return 0;
}

//Complexity:O(n)
//Space COmplexity: O(1)