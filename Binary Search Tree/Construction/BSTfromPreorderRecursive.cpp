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

Node* constructBSTUtil(int pre[], int &preIndex, int key, int min, int max, int size){
	if(preIndex >= size)
		return NULL;
	Node* root = NULL;
	if(key > min && key < max){
		root = newNode(key);
		preIndex = preIndex +1;

		if(preIndex <size){
			root->left = constructBSTUtil(pre,preIndex,pre[preIndex],min,key,size);
			root->right = constructBSTUtil(pre,preIndex,pre[preIndex],key,max,size);
		}
	}
	return root;
}

Node* constructBST(int pre[], int n){
	int preIndex = 0;
	return constructBSTUtil(pre, preIndex, pre[0], INT_MIN, INT_MAX, n);
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main(){
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(pre)/sizeof(pre[0]);
	Node* root = constructBST(pre,size);
	inOrder(root);
	return 0;
}

//Complexity:O(n)