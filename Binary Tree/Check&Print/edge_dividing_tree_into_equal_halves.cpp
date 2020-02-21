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

int count(Node* root){
	if(!root)
		return 0;
	return (1+count(root->left)+count(root->right));
}

bool checkUtil(Node* root, int n){
	if (!root)
		return false;

	if(count(root) == n-count(root))
		return true;

	return checkUtil(root->left,n) || checkUtil(root->right,n);
}


bool check(struct Node* root){
	int n = count(root);
	return checkUtil(root, n);
}

int main() 
{ 
    struct Node* root = newNode(5); 
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4); 

    if(check(root))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//Complexity: O(n^2)