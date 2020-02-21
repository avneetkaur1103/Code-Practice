#include <iostream>
#include <unordered_set>
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

void getVerticalWidthUtil(Node* root, unordered_set<int> &s, int hd){
	if(!root)
		return;

	getVerticalWidthUtil(root->left,s,hd-1);
	s.insert(hd);
	getVerticalWidthUtil(root->right,s,hd+1);
}

int getVerticalWidth(Node* root){
	unordered_set<int> s;
	getVerticalWidthUtil(root,s,0);

	return s.size();
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