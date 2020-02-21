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

bool iterativeSearch(Node* root, int key){
	while(root != NULL){
		if(key < root->data)
			root = root->left;
		else if(key > root->data)
			root = root->right;
		else
			return true;
	}
	return false;
}

int main(){
	struct Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    if (iterativeSearch(root, 15)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    return 0;
}

//Complexity: O(n)