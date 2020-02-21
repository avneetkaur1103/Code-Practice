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

Node* findLCA(Node* root, int n1, int n2){
	if(!root)
		return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	Node* ln = findLCA(root->left,n1,n2);
	Node* rn = findLCA(root->right,n1,n2);

	if (ln && rn)
		return root;

	if(!ln)
		return rn;
	else
		return ln;
}

int main(){
	Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data; 
    return 0;
}

//Complexity:O(n)