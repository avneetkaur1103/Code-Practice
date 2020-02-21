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

bool isBST(Node* root,Node* l, Node* r){
	if(root == NULL)
		return true;

	if(l != NULL && l->data >= root->data)
		return false;

	if(r!= NULL && r->data <= root->data)
		return false;

	return (isBST(root->left,l,root) && isBST(root->right,root,r));
}

int main(){
	struct Node *root = newNode(3); 
    root->left        = newNode(1); 
    root->right       = newNode(5); 
    root->left->left  = newNode(0); 
    root->left->right = newNode(2); 
  
    if (isBST(root,NULL,NULL)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST"; 
  
    return 0; 
}

//Complexity: O(n)