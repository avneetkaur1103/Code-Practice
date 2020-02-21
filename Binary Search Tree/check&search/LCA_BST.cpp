/*Iterative Solution takes less space as compared to recursive approach(O(h))*/

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

Node* lca(Node* root, int n1,int n2){
	if(!root)
		return NULL;
	if(root->right && root->data < n1 && root->data < n2)
		return lca(root->right,n1,n2);

	if(root->left && root->data > n1 && root->data > n2)
		return lca(root->left,n1,n2);
	
	return root;
}

int main(){
	struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
  
  	int n1 = 10, n2 = 14; 
    struct Node *t = lca(root, n1, n2); 
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}

//complexity: O(h)