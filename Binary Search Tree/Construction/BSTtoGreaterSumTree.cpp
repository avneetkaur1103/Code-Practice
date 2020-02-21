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

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void transformTreeUtil(Node* root,int &sum){
	if(!root)
		return;

	transformTreeUtil(root->right,sum);
	sum = sum+root->data;
	root->data = sum - root->data;
	transformTreeUtil(root->left,sum);
}

void transformTree(Node* root){
	int sum =0;
	transformTreeUtil(root, sum);

}

int main(){
	struct Node *root = newNode(11); 
    root->left = newNode(2); 
    root->right = newNode(29); 
    root->left->left = newNode(1); 
    root->left->right = newNode(7); 
    root->right->left = newNode(15); 
    root->right->right = newNode(40); 
    root->right->right->left = newNode(35); 
    transformTree(root);
    inOrder(root);
    return 0;
}

//Complexity:O(n)