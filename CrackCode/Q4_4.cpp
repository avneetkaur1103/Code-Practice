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

bool isBalanced(Node* root, int &height){
	if(root == NULL){
		height = 0;
		return true;
	}

	int lheight, rheight;
	bool l = isBalanced(root->left, lheight);
	bool r = isBalanced(root->right, rheight);

	height = max(lheight,rheight) + 1;

	if(abs(lheight-rheight) >= 2)
		return false;

	return l&&r;
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
	int height = 0;
	isBalanced(root,height)?cout<<"Balanced":cout<<"Not Balanced";
	return 0;
}