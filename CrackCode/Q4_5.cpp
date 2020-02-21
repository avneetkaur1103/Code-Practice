#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

Node* createNode(int d){
	Node* n = new Node;
	n->data = d;
	n->left = n->right = NULL;
	return n;
}

bool isBST(Node* root, Node* &prev){
	if(root){

		if(!isBST(root->left,prev))
			return false;

		if(prev!= NULL && prev->data >= root->data)
			return false;

		prev = root;
		

		if(!isBST(root->right,prev))
			return false;

	}
	return true;
	
}

int main(){
	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->right->right->left = createNode(8);
	//root->right->right->left->right = createNode(9);


	Node* root1 = createNode(3);
	root1->left = createNode(2);
	root1->right = createNode(4);
	root1->left->left = createNode(1);
	root1->right->right = createNode(7);

	Node* prev = NULL;
	isBST(root1,prev)?cout<<"Tree is BST":cout<<"Tree is not BST";
	return 0;
}