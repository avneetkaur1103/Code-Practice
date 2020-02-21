#include <iostream>
#include <cstdlib>
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


void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int CountNodes(Node* root){
	if(!root)
		return 0;
	return 1 + CountNodes(root->left) + CountNodes(root->right);
}

void BSTtoArr(Node* root, int arr[], int &idx){
	if(!root)
		return;

	BSTtoArr(root->left,arr,idx);
	
	arr[idx] = root->data;
	idx++;

	BSTtoArr(root->right,arr,idx);
}

bool compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

void ArrtoBST(int arr[], Node* &root, int &idx){
	if(!root)
		return;

	ArrtoBST(arr,root->left,idx);
	root->data = arr[idx];
	idx++;
	ArrtoBST(arr,root->right,idx);
}

void binaryTreeToBST(Node* &root){
	if(!root)
		return;

	int n = CountNodes(root);
	int *arr = new int[n];
	int idx = 0;
	BSTtoArr(root, arr,idx);

	//qsort(arr,n,sizeof(arr[0]),compare);
	sort(arr, arr+n);

	idx = 0;
	ArrtoBST(arr,root,idx);
	delete []arr;
}

int main(){
	Node* root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5);
    binaryTreeToBST(root);
	inOrder(root);
	return 0;
}

//Complexity:O(n)+O(n^2) { Sorting } + O(n)