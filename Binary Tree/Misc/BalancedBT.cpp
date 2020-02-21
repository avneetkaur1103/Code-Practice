#include <iostream>
#include <queue>
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

bool isBalanced(Node* root, int *height){
	if(!root){
		*height =0;
		return true;
	}

	int lh =0, rh =0;
	bool l, r;

	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	*height = ((lh > rh)? lh : rh) + 1;

	if(abs(lh - rh) >= 2)
		return false;
	else
		return l && r;
}

int main()
{
	int height = 0;
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->left->left->left = newNode(7); 
  	
    if (isBalanced(root, &height)) 
    	cout<<"Tree is Balanced"<<endl;
    else
    	cout<<"Tree is Not Balanced"<<endl;
	return 0;
}

//complexity:O(n)