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

void inorder(Node* root){
	if(!root)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* MergeTrees(Node* r1, Node* r2){
	if(!r1)
		return r2;
	if(!r2)
		return r1;

	r1->data += r2->data;

	MergeTrees(r1->left,r2->left);
	MergeTrees(r1->right,r2->right);
	return r1;
}

int main() 
{ 
    Node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    root1->right->right = newNode(6); 

    Node *root2 = newNode(4); 
    root2->left = newNode(1); 
    root2->right = newNode(7); 
    root2->left->left = newNode(3); 
    root2->right->left = newNode(2); 
    root2->right->right = newNode(6); 
  
    Node *root3 = MergeTrees(root1, root2); 
    printf("The Merged Binary Tree is:\n"); 
    inorder(root3); 
    return 0; 
} 

//Complexity:O(n)