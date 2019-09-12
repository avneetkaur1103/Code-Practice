#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void Inorder(struct Node* root){
	if(root == NULL)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void Preorder(struct Node* root){
	if(root == NULL)
		return;
	
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(struct Node* root){
	if(root == NULL)
		return;
	
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout<< "Inorder traversal: ";
	Inorder(root);
	cout<<endl;
	cout<< "Preorder traversal: ";
	Preorder(root);
	cout<< endl;
	cout<< "Postorder traversal: ";
	Postorder(root);
	cout<< endl;
	return 0;
}

//Complexity: O(n)