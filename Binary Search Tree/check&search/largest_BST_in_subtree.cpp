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

struct Info{
	int sz;
	int max;
	int min;
	int ans;
	bool isBST;
};

Info* largestBSTinBT(Node* root){
	if(!root)
		return {0,INT_MIN,INT_MAX,0,true};
	if(!root->left && !root->right)
		return {1,root->data,root->data,1,true};

	Info* l = largestBSTinBT(root->left);
	Info* r = largestBSTinBT(root->right);

	Info* res;
	res->sz = l->sz + r->sz;

	if(l->isBST && r->isBST && l->max <root->data && r->min > root->data){
		res->min = min(l->min,min(root->data,r->min));
		res->max = max(l->max,max(root->data,r->max));
		res->ans = res->sz;
		res->isBST = true;
		return res;
	}

	res->ans = max(l->ans,r->ans);
	res->isBST = false;
	return res;
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

int main(){
	struct Node *root = newNode(60); 
    root->left = newNode(65); 
    root->right = newNode(70); 
    root->left->left = newNode(50); 
    cout<<largestBSTinBT(root)->ans;
    return 0;
}