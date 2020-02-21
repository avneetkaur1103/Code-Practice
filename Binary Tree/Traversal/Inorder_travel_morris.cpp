#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void morris_traversal(struct Node* root){
	if (root == NULL)
		return;
	struct Node* curr = root, *pre;
	while(curr != NULL){
		if(curr->left == NULL){
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else{
			pre = curr->left;
			while(pre->right!= NULL && pre->right != curr)
				pre = pre->right;

			if(pre->right == NULL){
				//cout<<"if is called"<<endl;
				pre->right = curr;
				curr = curr->left;
			}
			else{
				//cout<<"else is called"<<endl;
				pre->right = NULL;
				cout<<curr->data<<" ";
				curr = curr->right;
			}
		}
	}
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(8);
	root->left->right->right = newNode(9);
	morris_traversal(root);
	return 0;
}

//Complexity: O(n)