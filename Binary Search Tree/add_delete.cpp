/* We can insert & delete duplicates in BST by introducing "count" in struct Node and incr / decr count on every dupliacte occurance */

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
	if(root == NULL)
		return newNode(key);
	
	if(key<root->data)
		root->left = insert(root->left,key);

	if(key>root->data)
		root->right = insert(root->right,key);

	return root;
}

void inorder(Node* root){
	if(!root)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* search(Node* root, int key){
	if(!root)
		return NULL;

	if(root->data == key)
		return root;

	if(key<root->data)
		return search(root->left,key);

	return search(root->right,key);
}

Node* findMin(Node* node){
	if(node == NULL)
		return NULL;

	Node* curr = node;
	while(curr && curr->left)
		curr = curr->left;

	return curr;
}

Node* deleteNode(Node* root, int key){
	if(!root)
		return NULL;
	else if(key < root->data)
		root->left = deleteNode(root->left,key);
	else if (key > root->data)
		root->right = deleteNode(root->right,key);
	else{
		if(root->left == NULL){
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else{
			Node* temp = findMin(root->right);
			root->data = temp->data;
			return deleteNode(root->right, temp->data);
		}
	}

	return root;
}

int main(){
	struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   	
    inorder(root);
    cout<<endl;
    Node* snode = search(root,80);
    (snode != NULL)?cout<<"Found" : cout<<"Not Found";
    cout<<endl;
    root = deleteNode(root,20);
    inorder(root);
    return 0;
}

//Complexity of Search, Insert & Delete: O(h) | skewed tree: O(n)