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

void nthPostorderNode(struct Node *root, int n){
	static int count = 0;
	if(!root)
		return;
	if(count<=n){
		nthPostorderNode(root->left,n);
		nthPostorderNode(root->right,n);
		count++;
		if(count == n)
			cout<<root->data;
		
	}
}

int main(){
	struct Node* root = newNode(25);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(18);
	root->left->right = newNode(22);
	root->right->left = newNode(24);
	root->right->right = newNode(32);
	int n=6;
	nthPostorderNode(root,n);
	return 0;
}

//Complexity: O(n)