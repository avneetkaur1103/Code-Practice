#include <iostream>
#include <vector>
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

void storeInArr(Node* root, vector<int> &v){
	if(!root)
		return;

	storeInArr(root->left, v);
	v.push_back(root->data);
	storeInArr(root->right, v);
}

void ConvertToHeap(Node* root,vector<int> v,int &idx){
	if(!root)
		return;

	root->data = v[++idx];
	ConvertToHeap(root->left,v,idx);
	ConvertToHeap(root->right,v,idx);
}

void convertToMinHeapUtil(Node* &root){

	vector<int> v;
	storeInArr(root,v);
	int idx = -1;
	ConvertToHeap(root, v,idx);

}

void preOrder(Node* root){
	if(!root)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	struct Node *root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left = newNode(5); 
    root->right->right = newNode(7); 
  
    convertToMinHeapUtil(root);
    preOrder(root);
    return 0;
}

//Complexity: O(n)
//Space Complexity: O(n)