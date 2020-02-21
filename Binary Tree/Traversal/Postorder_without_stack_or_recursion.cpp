#include <iostream>

using namespace std;

struct Node{
	int data;
	bool visited;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->visited = false;
	return n;
}

void postorderWithoutStackOrRecursion(struct Node *root){
	if(!root)
		return;
	struct Node *temp = root;

	while(temp && temp->visited == false){
		if(temp->left && temp->left->visited == false)
			temp = temp->left;
		else if(temp->right && temp->right->visited == false)
			temp = temp->right;
		else{
			cout<<temp->data<<" ";
			temp->visited = true;
			temp = root;
		}
	}
}

int main(){
	struct Node* root = newNode(1);
	root->left        = newNode(2); 
  	root->right       = newNode(3); 
  	root->left->left  = newNode(4); 
  	root->left->right = newNode(5); 
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	postorderWithoutStackOrRecursion(root);
	return 0;
}

//Complexity: O(n^2)