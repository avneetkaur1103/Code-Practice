#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	struct Node* n = new Node;
	n->data = data;
	n->left = n->right = NULL;
	return n ;
}

void DeleteTree(struct Node* root){
	if(root == NULL)
		return;

	DeleteTree(root->left);
	DeleteTree(root->right);

	cout<<"Deleting Node: "<<root->data<<endl;
	free(root);
}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	DeleteTree(root);
	return 0;
}

//complexity: O(n)