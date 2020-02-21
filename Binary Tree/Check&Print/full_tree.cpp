#include <iostream>
#include <stack>
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

bool isFullTree(struct Node* root){
	if(!root)
		return true;

	if(!root->left && !root->right)
		return true;

	if(root->left && root->right)
		return (isFullTree(root->left) && isFullTree(root->right));

	return false;
}


int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->right = newNode(40); 
    root->left->left = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    root->left->left->left = newNode(80); 
    root->left->left->right = newNode(90); 
    root->left->right->left = newNode(80); 
    root->left->right->right = newNode(90); 
    root->right->left->left = newNode(80); 
    root->right->left->right = newNode(90); 
    root->right->right->left = newNode(80); 
    root->right->right->right = newNode(90); 
  	
  	if(isFullTree(root))
  		cout<<"True";
  	else
  		cout<<"False";

  	return 0;
}

//Complexity:O(n)