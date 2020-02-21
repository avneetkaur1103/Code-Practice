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

Node* removeNodesUtil(Node* root, int path_len, int k){
	if(!root)
		return NULL;

	root->left = removeNodesUtil(root->left,path_len+1,k);
	root->right = removeNodesUtil(root->right,path_len+1,k);

	if(root->left == NULL && root->right == NULL){
		if(path_len < k){
			free(root);
			return NULL;
		}
	}

	return root;
}

Node* removeNodes(Node* root, int k){
	Node* res = removeNodesUtil(root, 1, k);
	return res;
}

int main(){
	int k=4;
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(7); 
    root->right->right = newNode(6); 
    root->right->right->left = newNode(8); 
    Node* ans = removeNodes(root, k);
    inOrder(ans);
    return 0;
}

//Complexity: O(n)