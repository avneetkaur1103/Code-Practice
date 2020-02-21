#include <iostream>
#include <climits>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

bool isLeaf(Node* node){
	return ((node->left == NULL) && (node->right == NULL));
}

void sinkOddNodesUtil(Node* &root){
	if(root == NULL || isLeaf(root))
		return;

	if(root->left && !(root->left->data & 1)){
		swap(root->data, root->left->data);
		sinkOddNodesUtil(root->left);
	}

	else if(root->right && !(root->right->data & 1)){
		swap(root->data, root->right->data);
		sinkOddNodesUtil(root->right);
	}

}

void sinkOddNodes(Node* root){
	if(root == NULL || isLeaf(root))
		return;

	sinkOddNodes(root->left);
	sinkOddNodes(root->right);
	if(root->data & 1)
		sinkOddNodesUtil(root);
}

void Inorder(Node* root){
	if (!root)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	Node *root = newnode(1); 
    root->left = newnode(5); 
    root->right    = newnode(8); 
    root->left->left = newnode(2); 
    root->left->right = newnode(4); 
    root->right->left = newnode(9); 
    root->right->right = newnode(10); 
    sinkOddNodes(root);
    Inorder(root);
    return 0;
}

//Complexity: O(n)