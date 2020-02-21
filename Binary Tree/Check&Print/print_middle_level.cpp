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

void printMiddleLevelUtil(Node* r1, Node* r2){
	if(!r1 || !r2)
		return;

	if(r2->left == NULL && r2->right == NULL){
		cout<<r1->data<<" ";
		return;
	}


	printMiddleLevelUtil(r1->left,r2->left->left);
	printMiddleLevelUtil(r1->right,r2->left->left);
}

void printMiddleLevel(struct Node* root){
	printMiddleLevelUtil(root, root);
}

int main(){
	Node* root = newNode(1); 
    root->left     = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printMiddleLevel(root);
    return 0;
}

//complexity: O(n)