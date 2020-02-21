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

 int search(int in[], int start, int end, int val){
	for(int i= start; i<=end; i++){
		if(in[i] == val)
			return i;
	}
	return -1;
}

int* extractkeys(int in[], int level[], int m, int n){
	
	int *newLevel = new int[m];
	int j=0;
	for(int i=0;i<n;i++){
		if(search(in,0,m-1,level[0]) != -1){
			newLevel[j] = level[i];
			j++;
		}
	}
	return newLevel;
}

struct Node* constructTree(int in[], int level[], int start, int end, int n){
	if(start > end)
		return NULL;
	struct Node* root = newNode(level[0]);

	if(start == end)
		return root;

	int idx = search(in,start,end,root->data);
	int *ltree = extractkeys(in,level,idx,n);
	int *rtree = extractkeys(in+idx+1,level,n-idx-1,n);

	root->left = constructTree(in,ltree,start,idx-1,n);
	root->right = constructTree(in,rtree,idx+1,end,n);
	delete [] ltree;
 	delete [] rtree;
	return root;
}


void print_inorder(struct Node* root){
	if(!root)
		return;
	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
}

int main(){
	int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    struct Node* root = constructTree(in,level,0,n-1,n);
    print_inorder(root);
    return 0;
}