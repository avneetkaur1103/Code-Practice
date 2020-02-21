#include <iostream>
#include <queue>
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

bool isPath(Node* root, int arr[], int n, int idx){
	if(root == NULL)
		return (n == 0);

	if(root->left == NULL && root->right == NULL && root->data == arr[idx] && idx == n-1 )
		return true;

	return((idx<n) && root->data == arr[idx] && (isPath(root->left,arr,n,idx+1) || isPath(root->right,arr,n,idx+1)));
}

int main()
{
	int arr[] = {5, 8, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    struct Node *root = newnode(5); 
    root->left    = newnode(3); 
    root->right   = newnode(8); 
    root->left->left = newnode(2); 
    root->left->right = newnode(4); 
    root->left->left->left = newnode(1); 
    root->right->left = newnode(6); 
    root->right->left->right = newnode(7); 
    isPath(root,arr,n,0) ? cout<<"Exists" : cout<<"Not Exists";
	return 0;
}

//Complexity: O(n)