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

bool seqExist(Node* root, int seq[], int n, int &index){
	if(!root)
		return false;
	seqExist(root->left,seq,n,index);

	if(seq[index] == root->data)
		index++;

	seqExist(root->right,seq,n,index);

	return (index == n);
}

int main(){
	struct Node* root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 10); 
    root = insert(root, 3); 
    root = insert(root, 6); 
    root = insert(root, 1); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 14); 
    root = insert(root, 13); 
  
    int seq[] = {4, 6, 8, 14}; 
    int n = sizeof(seq)/sizeof(seq[0]); 
  	int index = 0;
    seqExist(root, seq, n, index)? cout << "Yes" : 
                            cout << "No"; 
  
    return 0;
}

//complexity: O(n)