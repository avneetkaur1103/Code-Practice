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

bool isleaf(Node* node){
	if((node->left && node->left->right == node) && (node->right && node->right->left == node))
		return true;
	else
		return false;
}

int heightSpecialTree(Node* root){
	if(!root)
		return 0;

	if(isleaf(root))
		return 1;

	return 1 + max(heightSpecialTree(root->left),heightSpecialTree(root->right));
}

int main(){
	 Node* root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(6); 
  
    // Given tree contains 3 leaf nodes 
    Node *L1 = root->left->left->left; 
    Node *L2 = root->left->right; 
    Node *L3 = root->right; 
  
    // create circular doubly linked list out of 
    // leaf nodes of the tree 
  
    // set next pointer of linked list 
    L1->right = L2, L2->right = L3, L3->right = L1; 
  
    // set prev pointer of linked list 
    L3->left = L2, L2->left = L1, L1->left = L3; 
    cout<<heightSpecialTree(root);
    return 0;
}

//Complexity:O(n)