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

int totalSum(struct Node* root){
	if(!root)
		return 0;

	int sum = root->data + totalSum(root->left) + totalSum(root->right);
	return sum;
}

int UCLNodeSum(struct Node* node){
	if(!node)
		return 0;
	if(!node->left && !node->right)
		return node->data;

	if(node->left)
			return (node->data + UCLNodeSum(node->left));
	else
			return (node->data + UCLNodeSum(node->right));
}

int UCRNodeSum(struct Node* node){
	if(!node)
		return 0;
	if(!node->left && !node->right)
		return node->data;

	if(node->right)
			return (node->data + UCRNodeSum(node->right));
	else
			return (node->data + UCRNodeSum(node->left));
}

bool isSameSum(struct Node* root){
	if(!root || (!root->left && !root->right))
		return true;
	int totalUCSum = UCRNodeSum(root) + UCLNodeSum(root);

	if(totalUCSum == (totalSum(root) - totalUCSum))
		return true;
	else
		return false;
}

int main(){
	struct Node* root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 

    if(isSameSum(root))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//complexity: O(n)