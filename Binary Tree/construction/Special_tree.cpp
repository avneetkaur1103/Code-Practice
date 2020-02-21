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
struct Node* constructTreeUtil(int pre[], char preLN[], int *idx, int n){
	int i = *idx;
	if(i == n)
		return NULL;

	struct Node* root = newNode(pre[i]);
	++*idx;

	if(preLN[i] == 'N'){
		root->left = constructTreeUtil(pre,preLN,idx,n);
		root->right = constructTreeUtil(pre,preLN,idx,n);
		
	}

	return root;
}

struct Node* constructTree(int pre[], char preLN[], int n){
	int idx = 0;
	return constructTreeUtil(pre,preLN,&idx,n);
}

void Inorder(struct Node *root){
	if(!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	int pre[] = {10, 30, 20, 5, 15}; 
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
    struct Node *root = constructTree(pre,preLN,n);
    Inorder(root);
    return 0;
}

//Complexity: O(n)