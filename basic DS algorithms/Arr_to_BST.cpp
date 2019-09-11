#include <iostream>
using namespace std;

struct Tnode{
	int data;
	struct Tnode *left, *right;
};

struct Tnode* create_node(int data){
	struct Tnode* new_node = (struct Tnode*)malloc(sizeof(struct Tnode));
	new_node->data= data;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

struct Tnode* sorted_arr_to_bst(int arr[], int start, int last){
	
	if (start > last)
		return NULL;
	int mid = (start + last)/2;
	Tnode *root = create_node(arr[mid]);
	root->left = sorted_arr_to_bst(arr,start,mid-1);
	root->right = sorted_arr_to_bst(arr,mid+1,last);
	return root;
}

void PreOrder(struct Tnode *root){
	if (root == NULL)
		return;
	cout<< root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

int main() {
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	Tnode *root = sorted_arr_to_bst(arr,0,n-1);
	PreOrder(root);
	return 0;
}