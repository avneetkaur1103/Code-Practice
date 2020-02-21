#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void maxDiffUtil(Node* root, int key, int &min_diff, int &min_diff_key){
	if(!root){
		//min_diff_key = -1;
		return;
	}

	if(root->data == key){
		min_diff_key = root->data;
		return;
	}

	if(min_diff > abs(root->data - key)){
		min_diff = abs(root->data - key);
		min_diff_key = root->data;
	}

	if(key< root->data)
		maxDiffUtil(root->left,key,min_diff,min_diff_key);
	else 
		maxDiffUtil(root->right,key,min_diff,min_diff_key);
}

int maxDiff(Node* root, int key){
	int min_diff = INT_MAX, min_diff_key = -1;
	maxDiffUtil(root,key,min_diff,min_diff_key);

	return min_diff_key;
}

int main (){
	struct Node *root = newnode(9); 
    root->left    = newnode(4); 
    root->right   = newnode(17); 
    root->left->left = newnode(3); 
    root->left->right = newnode(6); 
    root->left->right->left = newnode(5); 
    root->left->right->right = newnode(7); 
    root->right->right = newnode(22); 
    root->right->right->left = newnode(20); 
    int k = 18; 
    cout << maxDiff(root, k); 
    return 0; 
}

//Complexity: O(h)