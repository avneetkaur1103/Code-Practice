#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *nextRight;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->nextRight = NULL;
	return n;
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void createFactorTree(Node** root, int n){
	(*root) = newNode(n);

	for(int i = 2;i<n/2;i++){
		if(n%i !=0)
			continue;

		createFactorTree(&(*root)->left,i);
		createFactorTree(&(*root)->right,n/i);
		return;
	}
}

int main(){
	int n = 48;
	Node* root = NULL;
	createFactorTree(&root, n);
	inOrder(root);
	return 0;
}

//complexity:O(n)