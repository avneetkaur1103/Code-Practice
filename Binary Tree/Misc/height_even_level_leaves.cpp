#include <iostream>
#include <queue>
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

int heightTreeUtil(Node* root, bool isEven){
	if (!root)
		return 0;

	if(!root->left && !root->right){
		if(isEven)
			return 1;
		else
			return 0;
	}

	int lh = heightTreeUtil(root->left, !isEven);
	int rh = heightTreeUtil(root->right, !isEven);

	if(lh == 0 && rh == 0)
		return 0;

	return (1 + max(lh,rh));
}

int heightTree(Node* root){
	return heightTreeUtil(root,false);
}

int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->left = newNode(6); 

    cout<<"Height of tree: "<< heightTree(root);
    return 0;
}

//Complexity:O(n)