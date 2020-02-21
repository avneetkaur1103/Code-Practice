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

int minDepth(Node* root){
	if(!root)
		return 0;

	int ldepth = minDepth(root->left);
	int rdepth = minDepth(root->right);

	if(ldepth>rdepth)
		return rdepth+1;
	else
		return ldepth+1;
}

int main()  
{  
    Node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    cout<<minDepth(root);
    return 0;
}

//Complexity:O(n)