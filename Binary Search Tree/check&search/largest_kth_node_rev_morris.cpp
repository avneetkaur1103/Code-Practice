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

int KthLargestUsingMorrisTraversal(Node* root, int k){
	Node* curr = root;
	int klarge = INT_MAX;
	int count = 0;

	while(curr != NULL){
		if(curr->right == NULL){
			count++;
			if(count == k)
				klarge = curr->data;
			curr = curr->left;
		}
		else{
			Node* pre = curr->right;

			while(pre->left != NULL && pre->left != curr)
				pre = pre->left;

			if(pre->left == NULL){
				pre->left = curr;
				curr = curr->right;
			}
			else{
				pre->left = NULL;
				count++;
				if(count == k)
					klarge = curr->data;
				curr = curr->left;
			}
		}
	}
	return klarge;
}

int main(){
	Node* root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(7); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left = newNode(6); 
    root->right->right = newNode(10); 
  
    
    cout << KthLargestUsingMorrisTraversal(root, 2);
    return 0;
}

//Time ComplexitY:O(n)
//Space Complexity: O(1)