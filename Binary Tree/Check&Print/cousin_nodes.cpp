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

int level(struct Node* root, Node* node, int l){
	if (!root)
		return 0;
	if(root == node)
		return l;

	int le = level(root->left,node,l+1);
	if (le)
		return le;
	else
		return level(root->right,node,l+1);
}

bool isSibling(struct Node* root, struct Node* n1, struct Node* n2){
	if(!root)
		return false;

	return ((root->left == n1 && root->right == n2) ||
		(root->right == n1 && root->left == n2) || 
		isSibling(root->left,n1,n2) || isSibling(root->right,n1,n2));
}

bool isCousin(struct Node* root, struct Node* n1, struct Node* n2){
	if((level(root,n1,1) == level(root,n2,1)) && !isSibling(root,n1,n2))
		return true;

	return false;
}

int main(){
	struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    struct Node *Node1,*Node2; 
    Node1 = root->left->left; 
    Node2 = root->right->right; 

    if(isCousin(root,Node1,Node2))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//complexity: O(n)