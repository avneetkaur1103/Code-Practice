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

int sum(struct Node* n){
	if(!n)
		return 0;
	else
		return n->data + sum(n->left) + sum(n->right);
}

bool check_sumTree(struct Node* root){
	if(!root || (!root->left && !root->right))
		return true;

	int rdata = 0,ldata = 0;

	ldata = sum(root->left);
	rdata = sum(root->right);

	if((root->data == ldata+rdata) && check_sumTree(root->left) && check_sumTree(root->right))
		return true;

	return false;

}

int main(){
	struct Node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3);  

    if(check_sumTree(root))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//complexity: O(n^2) (Worst case: skewed trees)