#include <iostream>
#include <climits>
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

int countNonleaf(Node* root){
	if (!root)
		return 0;

	if(root->left == NULL && root->right == NULL)
		return 0;

	return 1 + countNonleaf(root->left) + countNonleaf(root->right);
}

int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    cout << countNonleaf(root); 
    return 0; 
}

//complexit:O(n)