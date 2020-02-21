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

void Inorder(struct Node* root){
	if(!root)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void revorder(struct Node* root1, struct Node* root2, int level){
	if(root1 == NULL || root2 == NULL)
		return;

	if(level % 2 == 0)
		swap(root1->data, root2->data);
	
	revorder(root1->left, root2->right, level+1);
	revorder(root1->right, root2->left, level+1);
}

void reverse_alternate_levels(struct Node* root){
	if(!root)
		return;

	revorder(root->left, root->right, 0);
}

int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);

    cout<<"Inorder traversal before: "<<endl;
    Inorder(root);
    cout<<endl;

    reverse_alternate_levels(root);

    cout<<"Inorder traversal after: "<<endl;
    Inorder(root);

    return 0;
}

//Complexity: O(n)