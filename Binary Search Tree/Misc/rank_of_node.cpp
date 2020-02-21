#include <iostream>
using namespace std;

struct Node{
	int data, leftsize;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->leftsize = 0;
	n->left = n->right = NULL;
	return n;
}

Node* insert(Node* root, int key){
	if(!root)
		return newNode(key);

	if (key < root->data){
		root->left = insert(root->left,key);
		root->leftsize++;
	}
	else if(key > root->data)
		root->right = insert(root->right,key);

	return root;
}

int getRank(Node* root, int x){
	if(!root)
		return -1;

	if(root->data == x)
		return root->leftsize;

	if(x<root->data){
		if(!root->left)
			return -1;
		else{
			return getRank(root->left,x);
		}
	}
	else{
		if(!root->right)
			return -1;
		else{
			int rightsize = getRank(root->right,x);
			return root->leftsize + 1+rightsize;
		}
		
	}
}

int main(){
	int arr[] = { 5, 1, 4, 4, 5, 9, 7, 13, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 4; 
  
    Node* root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, arr[i]); 
  
    cout << "Rank of " << x << " in stream is: " 
         << getRank(root, x) << endl; 
    return 0;
}

//Complexity of getRank: O(logn)