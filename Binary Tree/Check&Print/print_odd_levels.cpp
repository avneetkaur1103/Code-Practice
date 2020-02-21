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

void printOddLevel(Node* root, bool isOdd = true){
	if(!root)
		return;

	if(isOdd)
		cout<<root->data <<" ";

	printOddLevel(root->left, !isOdd);
	printOddLevel(root->right, !isOdd);
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    printOddLevel(root); 
    return 0; 
}

//complexity: O(n)