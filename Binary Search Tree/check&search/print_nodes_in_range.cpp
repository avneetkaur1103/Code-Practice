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

Node* insert(Node* root, int key){
	if(!root)
		return newNode(key);

	if(key<root->data)
		root->left = insert(root->left,key);
	if(key>root->data)
		root->right = insert(root->right,key);

	return root;
}

void print(Node* root, int k1, int k2){
	if(!root)
		return;

	if(root->data > k1)
		print(root->left,k1,k2);
	if(k1 <=root->data && k2 >= root->data)
		cout<<root->data<<" ";
	if(root->data < k2)
		print(root->right,k1,k2);
}

int main(){
	Node* root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);
    int k1=10, k2=25;
    print(root,k1,k2);
    return 0;
}

//Complexity:O(n)