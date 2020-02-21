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

int getCount(Node* root, int l, int h){
	if(!root)
		return 0;

	if(root->data == l && root->data == h)
		return 1;

	if(root->data >= l && root->data <= h)
		return 1+ getCount(root->left,l,h) + getCount(root->right,l,h);

	else if(root->data <l)
		return getCount(root->right,l,h);

	else
		return getCount(root->left,l,h);

}

int main(){
	Node *root        = newNode(10); 
    root->left        = newNode(5); 
    root->right       = newNode(50); 
    root->left->left  = newNode(1); 
    root->right->left = newNode(40); 
    root->right->right = newNode(100); 

    int l = 5; 
    int h = 45; 
    cout<<getCount(root, l, h);
    return 0;
}

//complexity:O(h+k)
//where h = height & k= number of nodes in that range