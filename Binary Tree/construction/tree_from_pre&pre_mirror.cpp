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
struct Node* constructTreeUtil(int pre[], int preM[], int *idx, int start, int end, int n){
	if(start > end)
		return NULL;

	struct Node* root = newNode(pre[*idx]);
	++*idx;

	if(start == end)
		return root;

	int i;

	for(i=start;i<=end;i++){
		if(preM[i] == pre[*idx])
			break;
	}

	if(i<=end){
		root->left = constructTreeUtil(pre,preM,idx,i,end,n);
		root->right = constructTreeUtil(pre,preM,idx,start+1,i-1,n);
		
	}

	return root;
}

struct Node* constructTree(int pre[], int preM[], int n){
	int idx = 0;
	return constructTreeUtil(pre,preM,&idx,0,n-1,n);
}

void Inorder(struct Node *root){
	if(!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	int preOrder[] = {1,2,4,5,3,6,7}; 
    int preOrderMirror[] = {1,3,7,6,2,5,4};
    int n = sizeof(preOrder)/sizeof(preOrder[0]);
    struct Node *root = constructTree(preOrder,preOrderMirror,n);
    Inorder(root);
    return 0;
}

//Complexity: O(n)