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

int ksmallestElementSumUtil(Node* root, int k, int &count){
	if(!root)
		return 0;
	if(count>k)
		return 0;

	int sum = ksmallestElementSumUtil(root->left,k,count);
	if(count >= k)
		return sum;

	sum += root->data;
	count++;
	if(count>=k)
		return sum;

	return sum + ksmallestElementSumUtil(root->right,k,count);
}

int ksmallestElementSum(Node* root, int k){
	int count = 0;
	return ksmallestElementSumUtil(root,k,count);
}

int main(){
	Node *root = NULL; 
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
    root = insert(root, 22); 
  
    int k = 3; 
    cout <<  ksmallestElementSum(root, k) <<endl; 
    return 0; 
}

//Complexity: O(k)