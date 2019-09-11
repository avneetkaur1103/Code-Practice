#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* create_node(int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

struct Node* Construct_Tree_Recr(int arr[],int *arr_index,int start, int end, int size){
	if (start > end || *arr_index > size)
		return NULL;
	
	Node *root = create_node(arr[*arr_index]);
	*arr_index = *arr_index+1;
	
	if (start == end)
		return root;
	int i;
	for (i=start; i<= end; ++i)
	{
		if (arr[i] > root->data)
			break;
	}
	
	root->left = Construct_Tree_Recr(arr, arr_index, *arr_index, i-1,size);
	root->right = Construct_Tree_Recr(arr, arr_index, i, end, size);
	return root;
}

struct Node* Construct_Tree_Base(int arr[],int size){
	int arr_index = 0;
	return Construct_Tree_Recr(arr,&arr_index,0,size-1,size);
}

void Inorder(struct Node *root){
	if (root == NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main() {
	int arr[] = {10, 5, 1, 7, 40, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node *root = Construct_Tree_Base(arr, n);
	Inorder(root);
	return 0;
}

Complexity: O(n^2)