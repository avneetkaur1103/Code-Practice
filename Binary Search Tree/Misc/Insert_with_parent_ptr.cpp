#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *parent;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->parent = NULL;
	n->left = n->right = NULL;
	return n;
}

Node* insert(Node* root, int key){
	if(!root)
		return newNode(key);

	if (key < root->data){
		root->left = insert(root->left,key);
		root->left->parent = root;
	}
	else if(key > root->data){
		root->right = insert(root->right,key);
		root->right->parent = root;
	}

	return root;
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	if(root->parent)
		cout<<"parent of "<<root->data<<" is: "<<root->parent->data<<endl;
	else
		cout<<"parent of "<<root->data<<" is: NULL"<<endl;

	inOrder(root->right);
}

int main(){
	struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    inOrder(root);
    return 0;
}

//Complexity:O(n)