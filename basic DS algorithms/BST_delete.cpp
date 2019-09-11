#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

struct node* new_node(int data){
	struct node* node1 = (struct node*)malloc(sizeof(struct node));
	node1->data = data;
	node1->left = NULL;
	node1->right = NULL;
	return (node1);
}

struct node* insert(struct node *n,int key){
	if (n == NULL)
		return new_node(key);
	if (key < n->data)
		n->left = insert(n->left, key);
	else if (key > n->data)
		n->right = insert(n->right, key);
	return n;
}

void inorder(struct node* root){
	if (root != NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

struct node* minVal(struct node* n){
		struct node *curr = n;
		while (curr->left != NULL){
			curr = curr->left;
		}
		return curr;
}

struct node* delete_node(struct node *n, int key){
		if (n == NULL)
			return n;
		
		if (key < n->data)
			n->left = delete_node(n->left, key);
		else if (key > n->data)
			n->right = delete_node(n->right, key);
		else{
			if (n->left == NULL){
				struct node *temp = n->right;
				free(n);
				return temp;
			}
			else if (n->right == NULL){
				struct node *temp = n->left;
				free(n);
				return temp;
			}
			else{
					struct node *temp = minVal(n->right);
					n->data = temp->data;
					n->right = delete_node(n->right, temp->data);
			}
		}
	return n;
}

int main() {
	struct node *root = NULL;
	root = insert(root,7);
	insert(root, 3);
	insert(root, 8);
	insert(root, 1);
	insert(root, 5);
	insert(root, 10);
	insert(root, 12);
	inorder(root);
	printf("\n");;
	root = delete_node(root, 1);
	inorder(root);
	printf("\n");
	return 0;
}