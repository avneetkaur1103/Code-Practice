#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*) malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int determine_level_util(struct Node* root, int key, int level){
	int next_level;

	if(root == NULL)
		return 0;

	if(root->data == key)
		return level;

	next_level = determine_level_util(root->left,key,level+1);

	if(next_level != 0)
		return next_level;

	
	next_level = determine_level_util(root->right,key,level+1);


	return next_level;
}

int determine_level(struct Node* root, int key){
	return determine_level_util(root,key,1);
}

int main(){
	struct Node *root = newNode(3);
	root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4);
    cout<<"Level of key 5 is: "<<determine_level(root,4);
    return 0;
}

//complexity: O(n)