#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *next;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = n->next = NULL;
	return n;
}

void populateNext(struct Node* root){
	static struct Node* next1 = NULL;
	if(root){
		populateNext(root->right);
		root->next = next1;
		next1 = root;
		populateNext(root->left);
	}
}

int main(){
	struct Node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(12);
	root->left->left = newNode(3);
	populateNext(root);
	
	struct Node* ptr = root->left->left;
	while(ptr->next != NULL){
		cout<<ptr->next->data<<" ";
		ptr = ptr->next;
	}
	return 0;
}

//Complexity: O(n)