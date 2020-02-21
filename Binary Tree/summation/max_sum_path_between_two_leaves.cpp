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

int maxSumPathUtil(Node* root, int &sum){
	if (!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;

	int ls = maxSumPathUtil(root->left, sum);
	int rs = maxSumPathUtil(root->right, sum);

	if(root->left && root->right){
		sum = max(sum, ls+rs+root->data);
		return max(ls,rs) + root->data;
	}

	if(!root->left)
		return (rs + root->data);
	else
		return (ls+root->data);
}

int maxSumPath(Node* root){
	int sum = 0;
	maxSumPathUtil(root,sum);
	return sum;
}

int main() 
{ 
    struct Node *root = newNode(-15); 
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 

    cout<<"Max sum: "<<maxSumPath(root);
    return 0;
}

//complexity:O(n)