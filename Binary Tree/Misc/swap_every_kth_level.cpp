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

void swap(Node** a,Node** b){
	Node* tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapEveryKLevelUtil(Node* root, int level, int k){
	if(!root || !root->left || !root->right)
		return;

	if((level + 1) % k == 0)
		swap(root->left,root->right);

	swapEveryKLevelUtil(root->left,level+1,k);
	swapEveryKLevelUtil(root->right,level+1,k);
}

void swapEveryKLevel(Node* root, int k){
	swapEveryKLevelUtil(root,1,k);
}

int main(){
	struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->right = newNode(8); 
    root->right->left = newNode(7); 
  
    int k = 2; 
    swapEveryKLevel(root, k);
    inOrder(root);
    return 0;
}

//Complexity: O(n)