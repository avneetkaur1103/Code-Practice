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

bool isMatch(Node* t1, Node* t2){
	if(!t1 && !t2)
		return true;
	else if(!t1 || !t2)
		return false;
	else if (t1->data != t2->data)
		return false;
	else
		return (isMatch(t1->left,t2->left) && isMatch(t1->right,t2->right));
}

bool isSubtreeUtil(Node* t1,Node* t2){
	if(!t1)
		return false;
	else if (t1->data == t2->data && isMatch(t1,t2))
		return true;

	return (isSubtreeUtil(t1->left,t2) || isSubtreeUtil(t1->right,t2));
}

bool isSubtree(Node* t1,Node* t2){
	if(!t2)
		return true;

	return isSubtreeUtil(t1,t2);
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

	Node* root1 = createNode(3);
	root1->left = createNode(6);
	root1->right = createNode(7);
	root1->right->left = createNode(8);
	
	isSubtree(root,root1)? cout<<"Yes":cout<<"No";
	return 0;
}

//Space: O(logm+logn)
//time: O(mk+n)