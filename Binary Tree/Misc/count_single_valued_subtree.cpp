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

bool countSubtreeUtil(Node* root, int &count){
	if(!root)
		return true;

	bool ls = countSubtreeUtil(root->left,count);
	bool rs = countSubtreeUtil(root->right,count);

	if(ls == false || rs == false)
		return false;

	if(root->left && root->data != root->left->data)
		return false;

	if(root->right && root->data != root->right->data)
		return false;

	count++;
	return true;
}

int countSubtree(Node* root){
	int count = 0;
	countSubtreeUtil(root,count);
	return count;
}

int main(){
	Node* root        = newNode(5); 
    root->left        = newNode(4); 
    root->right       = newNode(5); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(4); 
    root->right->right = newNode(5); 
    cout<<countSubtree(root);
    return 0;
}

//complexity: O(n)