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

Node* lca(Node* root, int v1,int v2){
	if(!root)
		return NULL;
	if(root->data == v1 || root->data == v2)
		return root;

	Node* ln = lca(root->left, v1,v2);
	Node* rn = lca(root->right,v1,v2);

	if(ln && rn)
		return root;
	if(!ln)
		return rn;
	else
		return ln;
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


	Node* _lca = lca(root,8,2);
	if(_lca)
		cout<<_lca->data;
	else
		cout<<"LCA not found"<<endl;
	return 0;
}