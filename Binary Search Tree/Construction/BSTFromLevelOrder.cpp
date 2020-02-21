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

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

Node* constructFromLevelOrder(Node* root, int key){
	if(root == NULL){
		root = newNode(key);
		return root;
	}
	else if(key<=root->data){
		root->left = constructFromLevelOrder(root->left,key);
	}
	else
		root->right = constructFromLevelOrder(root->right,key);

	return root;
}

Node* constructBst(int arr[],int n){
	if(n == 0)
		return NULL;

	Node* root = NULL;

	for(int i=0;i<n;i++)
		root = constructFromLevelOrder(root, arr[i]);

	return root;
}

int main(){
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    Node *root = constructBst(arr, n); 
    inOrder(root);
    return 0;
}

//Complexity: O(n)