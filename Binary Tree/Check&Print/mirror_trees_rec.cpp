#include <iostream>
#include <queue>
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

bool isMirrorTree(struct Node* root1, struct Node* root2){
	if(!root1 && !root2)
		return true;

	if(!root1 || !root2)
		return false;

	return (root1->data == root2->data && isMirrorTree(root1->left,root2->right) && isMirrorTree(root1->right, root2->left));
}

int main(){
	Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 

    if(isMirrorTree(a,b))
    	cout<<"Yes";
    else
    	cout<<"No";
    return 0;
}

//Complexity: O(n)