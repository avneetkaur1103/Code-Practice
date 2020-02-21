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
struct Node* constructTreeUtil(int pre[], int post[], int *idx, int start, int end, int n){
	if(start > end)
		return NULL;

	struct Node* root = newNode(pre[*idx]);
	++*idx;

	if(start == end)
		return root;

	int i;

	for(i=start;i<=end;i++){
		if(post[i] == pre[*idx])
			break;
	}

	if(i<end){
		root->left = constructTreeUtil(pre,post,idx,start,i,n);
		root->right = constructTreeUtil(pre,post,idx,i+1,end,n);
	}

	return root;
}

struct Node* constructTree(int pre[], int post[], int n){
	int idx = 0;
	return constructTreeUtil(pre,post,&idx,0,n-1,n);
}

void Inorder(struct Node *root){
	if(!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};  
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(pre)/sizeof(pre[0]);
    struct Node *root = constructTree(pre,post,n);
    Inorder(root);
    return 0;
}

//Complexity: O(n)