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

int getLevelDiff(Node* root){
	if (!root)
		return 0;

	return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
}

int main()  
{  
    Node *root = newNode(5);  
    root->left = newNode(2);  
    root->right = newNode(6);  
    root->left->left = newNode(1);  
    root->left->right = newNode(4);  
    root->left->right->left = newNode(3);  
    root->right->right = newNode(8);  
    root->right->right->right = newNode(9);  
    root->right->right->left = newNode(7);  
    cout<<getLevelDiff(root);  
    return 0;
}

//complexity: O(n)
