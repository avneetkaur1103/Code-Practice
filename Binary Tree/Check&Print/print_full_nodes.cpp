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

void printFullNode(Node* root){
	if(!root)
		return;

	printFullNode(root->left);
	if(root->left != NULL && root->right != NULL)
		cout<<root->data <<" ";
	printFullNode(root->right);
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    printFullNode(root); 
    return 0; 
}

//complexity: O(n)