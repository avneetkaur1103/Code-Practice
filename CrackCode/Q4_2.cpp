#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

Node* createNode(int d){
	Node* n = new Node;
	n->data = d;
	n->left = n->right = NULL;
	return n;
}

Node* createBST(int inOrder[], int start, int end){
	if(start>end)
		return NULL;

	int mid = (start+end)/2;
	cout<<inOrder[mid]<<endl;
	Node* root = createNode(inOrder[mid]);

	//if(start == end)
	//	return root;

	root->left = createBST(inOrder,start,mid - 1);
	root->right = createBST(inOrder,mid+1,end);

	return root;

}

void printInorder(Node* root){
	if(!root)
		return;

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main(){
	int inOrder[] = {1,2,3,4,5,6,7};
	int n = sizeof(inOrder)/sizeof(inOrder[0]);
	Node* root = createBST(inOrder,0,n-1);
	printInorder(root);
	return 0;
}