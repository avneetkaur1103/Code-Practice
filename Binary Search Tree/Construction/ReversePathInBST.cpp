#include <iostream>
#include <queue>
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
	if(root == NULL)
		return newNode(key);
	
	if(key<root->data)
		root->left = insert(root->left,key);

	else if(key>root->data)
		root->right = insert(root->right,key);

	return root;
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void reversePathBST(Node** root, int &k, queue<Node*> &q){
	if(!root)
		return;

	if((*root)->data == k){
		q.push(*root);
		(*root)->data = q.front()->data;
		q.pop();
		return;
	}
	else if((*root)->data < k){
		q.push(*root);
		reversePathBST(&(*root)->right,k,q);
		(*root)->data = q.front()->data;
		q.pop();
	}
	else if((*root)->data > k){
		q.push(*root);
		reversePathBST(&(*root)->left,k,q);
		(*root)->data = q.front()->data;
		q.pop();
	}

	return;
}

int main(){
	Node* root = insert(root, 50); 
    /*insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    int k=80;
    queue<Node*> q;
    //reversePathBST(&root,k,q);
    //inOrder(root);*/
    return 0;
}