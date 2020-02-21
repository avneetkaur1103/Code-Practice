#include <iostream>
using namespace std;

struct Node{
	int time;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->time = data;
	n->left = n->right = NULL;
	return n;
}

Node* insert(Node* root, int k, int time){
	if(root == NULL)
		return newNode(time);

	if(time-k < root->time && time+k > root->time)
		return root;

	if(time < root->time)
		root->left = insert(root->left,k,time);
	else
		root->right = insert(root->right,k,time);

	return root;
}

int main(){
	int k=4;
	Node* root = NULL;
	root = insert(root,k,20);
	root = insert(root,k,15);
	root = insert(root,k,7);
	root = insert(root,k,2);
	
	return 0;
}