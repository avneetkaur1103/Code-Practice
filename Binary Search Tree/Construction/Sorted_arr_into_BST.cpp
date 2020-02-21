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

void preOrder(Node* root){
	if(!root)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

Node* sortedArrayToBST(int arr[], int s, int e){
	if(s>e)
		return NULL;

	int mid = (s+e)/2;
	Node* root = newNode(arr[mid]);
	root->left = sortedArrayToBST(arr,s,mid-1);
	root->right = sortedArrayToBST(arr,mid+1,e);
	return root;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]); 
  	Node *root = sortedArrayToBST(arr,0,n-1);
  	preOrder(root);
  	return 0;
}

//Complexity:O(n)