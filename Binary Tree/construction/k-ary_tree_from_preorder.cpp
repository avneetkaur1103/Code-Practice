#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node{
	int data;
	vector<Node*> child;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	return n;
}

struct Node* build_tree_util(int preorder[], int n, int k, int &ind, int h){
	if (n<=0)
		return NULL;
	struct Node* root = newNode(preorder[ind]);

	if(!root)
		return NULL;
	
	for(int i=0;i<k;i++){
		if(ind<n-1 && h>1){
			ind++;
			root->child.push_back(build_tree_util(preorder,n,k,ind,h-1));
		}
		else
			root->child.push_back(NULL);
	}
	return root;
}

void postorder(struct Node* root, int k){
	if(!root)
		return;

	for(int i=0;i<k;i++){
		postorder(root->child[i], k);
		cout<<root->data<<" ";
	}
}

struct Node* build_tree(int preorder[], int n, int k, int &ind){
	int h = (int)ceil((log((double)n*(k-1)+1))/log((double)k));
	return build_tree_util(preorder,n,k,ind,h);
}

int main(){
	int preorder[] = { 1, 2, 5, 6, 7, 3, 8, 9, 10, 4 };
	int n = sizeof(preorder)/sizeof(preorder[0]);
	int k =3;
	int ind = 0;
	struct Node* root = build_tree(preorder,n,k,ind);
	postorder(root, k);
	return 0;
}