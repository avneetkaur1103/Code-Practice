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

int findMirrorRec(int target, Node* left, Node* right){
	if(left == NULL || right == NULL)
		return 0;
	if(left->data == target)
		return right->data;

	if(right->data == target)
		return left->data;

	int mirror = findMirrorRec(target,left->left,right->right);
	if(!mirror)
		mirror = findMirrorRec(target,left->right,right->left);

	return mirror;
}

int findMirror(Node* root, int target){
	if(!root)
		return 0;

	if(root->data == target)
		return target;

	return findMirrorRec(target,root->left,root->right);
}

int main(){
	struct Node* root = newNode(1);  
    root-> left = newNode(2);  
    root->left->left = newNode(4);  
    root->left->left->right    = newNode(7);  
    root->right    = newNode(3);  
    root->right->left = newNode(5);  
    root->right->right = newNode(6);  
    root->right->left->left    = newNode(8);  
    root->right->left->right = newNode(9); 

    int target = root->left->left->data;  
  
    int mirror = findMirror(root, target);
    if(mirror && mirror !=0)
    	cout<<mirror;
    else
    	cout<<"Not found";

    return 0;
}

//Complexity: O(n)