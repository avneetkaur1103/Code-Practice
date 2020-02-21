#include <iostream>
using namespace std;

int max_depth, sum;

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

int treePathsSum(Node* root, int val){
	if(!root)
		return 0;

	val = val*10 + root->data;

	if(root->left== NULL && root->right == NULL)
		return val;

	return treePathsSum(root->left,val) + treePathsSum(root->right,val);
}

int main()  
{  
    Node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  
    cout<<"Sum of all paths is "<<treePathsSum(root,0);  
    return 0;  
}  

//Complexity:O(n)