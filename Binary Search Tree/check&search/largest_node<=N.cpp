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

Node* insert(Node* root, int key){
	if(!root)
		return newNode(key);

	if(key<root->data)
		root->left = insert(root->left,key);
	if(key>root->data)
		root->right = insert(root->right,key);

	return root;
}

int findMax(Node* root, int n){
	if(!root)
		return -1;
	if(root->data == n)
		return root->data;
	else if (root->data < n){
		int k = findMax(root->right,n);
		if(k == -1)
			return root->data;
		else
			return k;
	}
	else
		return findMax(root->left,n);
}

int main(){
	Node* root = NULL;
	root = insert(root, 25); 
    root = insert(root, 2); 
    root = insert(root, 1); 
    root = insert(root, 3); 
    root = insert(root, 12); 
    root = insert(root, 9); 
    root = insert(root, 21); 
    root = insert(root, 19); 
    root = insert(root, 25);
    int n= 4;
    cout<<findMax(root,n);
    return 0;
}

//Complecity:O(h)