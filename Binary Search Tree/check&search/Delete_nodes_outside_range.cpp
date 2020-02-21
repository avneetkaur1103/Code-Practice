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

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

Node* removeOutsideRange(Node* root, int k1, int k2){
	if(!root)
		return NULL;
	root->left = removeOutsideRange(root->left,k1,k2);
	root->right = removeOutsideRange(root->right,k1,k2);

	if(root->data < k1){
		Node* rchild = root->right;
		free(root);
		return rchild;
	}
	if(root->data > k2){
		Node* lchild = root->left;
		free(root);
		return lchild;
	}
	return root;
}

int main(){
	Node* root = NULL; 
    root = insert(root, 6); 
    root = insert(root, -13); 
    root = insert(root, 14); 
    root = insert(root, -8); 
    root = insert(root, 15); 
    root = insert(root, 13); 
    root = insert(root, 7); 

    root = removeOutsideRange(root, -10, 13);
    inOrder(root);
    return 0;
}

//Complexity:O(n)