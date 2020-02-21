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

int find_max(int in[], int start, int end){
	int max = in[start];
	int max_plc = start;
	for(int i =start+1;i<=end;i++){
		if(in[i] > max){
			max = in[i];
			max_plc = i;
		}
	}
	return max_plc;
}

struct Node* build_tree(int in[], int start, int end){
	if(start>end)
		return NULL;

	int max_plc = find_max(in,start,end);
	struct Node* root = newNode(in[max_plc]);

	if(start == end)
		return root;

	root->left = build_tree(in,start,max_plc -1);
	root->right = build_tree(in, max_plc+1,end);

	return root;
}

void inOrder(struct Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main(){
	int inorder[] = {5, 10, 40, 30, 28};
	int n = sizeof(inorder)/sizeof(inorder[0]);
	struct Node* root = build_tree(inorder,0,n-1);
	inOrder(root);
	return 0;
}

//Complexity: O(n^2) ??