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

int tiltUtil(Node* root, int &tilt){
	if(!root)
		return 0;

	int left = tiltUtil(root->left,tilt);
	int right = tiltUtil(root->right,tilt);

	tilt += abs(left - right);

	return left + right + root->data;
}

int tilt(Node* root){
	int tilt=0;
	tiltUtil(root, tilt);
	return tilt;
}

int main(){
	Node* root = NULL; 
    root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(9); 
    root->left->left = newNode(3); 
    root->left->right = newNode(8); 
    root->right->right = newNode(7); 
    cout<<tilt(root);
    return 0;
}

//Complexity:O(n)