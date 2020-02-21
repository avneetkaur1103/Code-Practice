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

int depth(Node* root){
	if(!root)
		return 0;
	return (1+depth(root->left));
}

bool isPerfectUtil(Node* root, int d,int level=0){
	if(!root)
		return true;
	if(root->left == NULL && root->right == NULL)
		return(d==level+1);

	if(root->left == NULL || root->right == NULL)
		return false;

	return isPerfectUtil(root->left,d,level+1) && isPerfectUtil(root->right,d,level+1);
}

bool isPerfect(struct Node* root){
	int d= depth(root);
	return isPerfectUtil(root,d);
}


int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  	
  	if(isPerfect(root))
  		cout<<"True";
  	else
  		cout<<"False";

  	return 0;
}

//Complexity: O(n)