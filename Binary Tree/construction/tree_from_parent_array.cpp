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

void inOrder(struct Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void build_tree_utility(int parent[], Node* created[], int i, struct Node** root){
	if(created[i])
		return;

	created[i] = newNode(i);

	if(parent[i] == -1){
		*root = created[i];
		return;
	}

	if(!created[parent[i]])
		build_tree_utility(parent,created, parent[i] , root);

	struct Node* p = created[parent[i]];

	if(!p->left)
		p->left = created[i];
	else
		p->right = created[i];

}

struct Node* build_tree(int parent[], int n){
	Node* created[n];
	for(int j=0;j<n;j++)
		created[j] = NULL;

	struct Node* root = NULL;

	for(int i=0;i<n;i++){
		build_tree_utility(parent,created,i,&root);
	}

	return root;
}


int main(){
	int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
	int n = sizeof(parent)/sizeof(parent[0]);
	struct Node* root = build_tree(parent,n);
	inOrder(root);
	return 0;
}

//Complexity: O(n)