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

int countSubtreesUtil(Node* root, int &count){
	if(!root)
		return 0;
	int c = countSubtreesUtil(root->left,count);
	c += countSubtreesUtil(root->right,count);

	if(root->data %2 == 0)
		c += 1;

	if(c%2 != 0)
		count++;

	return c;
}

int countSubtrees(Node* root){
	int count = 0;
	countSubtreesUtil(root,count);
	return count;
}

int main(){
	struct Node *root = newNode(2);   
    root->left        = newNode(1);  
    root->right       = newNode(3);   
    root->left->left  = newNode(4);   
    root->left->right = newNode(10); 
    root->right->left  = newNode(8);  
    root->right->right = newNode(5); 
    root->left->right->left = newNode(6); 

    cout<<countSubtrees(root);
    return 0;
}

//Complexity:O(n)