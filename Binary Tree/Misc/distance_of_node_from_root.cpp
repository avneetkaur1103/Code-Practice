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

int findDistance(Node* root, int key){
	if(!root)
		return -1;

	if(root->data == key)
		return 0;

	int ldist = findDistance(root->left,key);
	if(ldist >= 0)
		return 1+ldist;
	else{
		int rdist = findDistance(root->right,key);
		if(rdist>=0)
			return 1+rdist;
	}
	return -1;
}

int main(){
	Node *root = newNode(5); 
    root->left = newNode(10); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->left->right = newNode(25); 
    root->left->right->right = newNode(45); 
    root->right->left = newNode(30); 
    root->right->right = newNode(35); 
  
    cout << findDistance(root, 45); 
    return 0;
}

//Complexity:O(n)