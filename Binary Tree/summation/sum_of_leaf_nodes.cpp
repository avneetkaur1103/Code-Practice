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

int leafNodesSum(Node* root,int &sum){
	if(!root)
		return 0;

	if(!root->left && !root->right)
		sum += root->data;

	leafNodesSum(root->left,sum);
	leafNodesSum(root->right,sum);

	return sum;
}

int main(){
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right = newNode(3); 
    root->right->right = newNode(7); 
    root->right->left = newNode(6); 
    root->right->left->right = newNode(8); 
    int sum =0;
    cout<<leafNodesSum(root,sum);
    return 0;
}

//complexity: O(n)