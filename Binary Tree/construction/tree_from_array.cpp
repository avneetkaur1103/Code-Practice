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

struct Node* construct_tree(int arr[], struct Node* root, int start,int end){
	if(start < end){
		root = newNode(arr[start]);

		root->left = construct_tree(arr,root->left,2*start+1,end);
		root->right = construct_tree(arr,root->right,2*start+2,end);
	}
	return root;
}


void Inorder(struct Node* root){
	if(!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	struct Node* root = construct_tree(arr,root,0,n);
	Inorder(root);
	return 0;
}

//complexity:O(n)