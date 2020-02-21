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

int distanceFromRoot(Node* root, int n){
	if(!root)
		return 0;

	if(root->data == n)
		return 0;
	else if (root->data < n)
		return 1+distanceFromRoot(root->right,n);
	else
		return 1+distanceFromRoot(root->left,n);
}

int shortestDistBtw2NodesUtil(Node* root, int a,int b){
	if(!root)
		return 0;
	if(root->data < a && root->data <b)
		return shortestDistBtw2NodesUtil(root->right,a,b);
	if(root->data > a && root->data > b)
		return shortestDistBtw2NodesUtil(root->left,a,b);
	if (root->data >=a && root->data <=b)
		return distanceFromRoot(root,a)+distanceFromRoot(root,b);
}

int shortestDistBtw2Nodes(Node* root,int a, int b){
	if(a>b)
		swap(a,b);
	return shortestDistBtw2NodesUtil(root,a,b);
}

int main(){
	struct Node* root = NULL;
	root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 15); 
    root = insert(root, 30); 
    root = insert(root, 25); 
    root = insert(root, 35); 
    int a = 35, b= 5;
  
    cout << shortestDistBtw2Nodes(root,a,b); 
    return 0; 
}

//complexity: O(h)
