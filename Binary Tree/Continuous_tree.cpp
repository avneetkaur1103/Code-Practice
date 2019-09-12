#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data){
	struct Node *n= (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

bool isContinuousTree(struct Node *root){
	if (root == NULL)
		return true;

	if(root->left == NULL && root->right == NULL)
		return true;

	if(root->left == NULL)
				return (abs(root->data - root->right->data) == 1) && isContinuousTree(root->right);

	if(root->right == NULL)
				return (abs(root->data - root->left->data) == 1) && isContinuousTree(root->left);


	return ((abs(root->data -root->left->data)==1) && (abs(root->data - root->right->data) == 1) &&
		isContinuousTree(root->right) && isContinuousTree(root->left));

}

int main(){
	struct Node* root = newNode(3);
	//root->left = newNode(2);
	root->right = newNode(4);
	//root->left->left = newNode(1);
	//root->left->right = newNode(3);
	root->right->right = newNode(6);

	isContinuousTree(root) ? cout<<"Tree is continuous." : cout<<"Tree is NOT continuous.";
	return 0;

}