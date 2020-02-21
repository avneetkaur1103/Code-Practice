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

bool check_children_sum(struct Node* root){
	if(!root || (!root->left && !root->right))
		return true;

	int rdata = 0,ldata = 0;
	if(root->left != NULL)
		ldata = root->left->data;
	if(root->right != NULL)
		rdata = root->right->data;

	if((root->data == ldata+rdata) && check_children_sum(root->left) && check_children_sum(root->right))
		return true;

	return false;

}

int main(){
	struct Node *root = newNode(10); 
    root->left     = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->right = newNode(2); 

    if(check_children_sum(root))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//complexity: O(n)