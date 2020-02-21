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

void getVerticalWidthUtil(Node* root, int &min, int &max, int curr){
	if(!root)
		return;

	getVerticalWidthUtil(root->left,min,max,curr-1);

	if(min > curr)
		min = curr;
	if(max<curr)
		max = curr;

	getVerticalWidthUtil(root->right,min,max,curr+1);
}

int getVerticalWidth(Node* root){
	int min = 0, max = 0;
	getVerticalWidthUtil(root,min,max,0);
	return (1 + abs(min) + max);
}

int main() 
{ 
  
    Node* root = newNode(7); 
    root->left = newNode(6); 
    root->right = newNode(5); 
    root->left->left = newNode(4); 
    root->left->right = newNode(3); 
    root->right->left = newNode(2); 
    root->right->right = newNode(1); 
  
    cout << getVerticalWidth(root) << endl; 
  
    return 0; 
} 

//Complexity:O(n)