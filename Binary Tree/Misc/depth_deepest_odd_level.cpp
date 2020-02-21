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

int depthOfOddLeafUtil(Node* root, int level){
	if(!root)
		return 0;
	if(root->left == NULL && root->right == NULL && (level & 1))
		return level;

	return max( depthOfOddLeafUtil(root->left, level+1), depthOfOddLeafUtil(root->right, level+1));
}

int depthOfOddLeaf(Node* root){
	int level = 1;
	return depthOfOddLeafUtil(root,level);
}

int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    root->right->right->right->right = newNode(10); 
    root->right->right->right->right->left = newNode(11);
    cout << depthOfOddLeaf(root);

    return 0;
}

//Complexity:O(n)