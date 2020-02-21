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

void printBSTsInRange(Node* root, int r1, int r2){
	if(!root)
		return;

	Node* curr = root;

	while(curr != NULL){
		if(curr->left == NULL){
			if(curr->data >= r1 && curr->data <= r2)
				cout<<curr->data<<" ";

			curr = curr->right;
		}
		else{
			Node* pre = curr->left;

			while(pre->right != NULL && pre->right != curr)
				pre = pre->right;

			if(pre->right == NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				
				if(curr->data >= r1 && curr->data <= r2)
					cout<<curr->data<<" ";
				curr = curr->right;
			}
		}
	}
}

int main(){
	Node* root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(7); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left = newNode(6); 
    root->right->right = newNode(10);

    printBSTsInRange(root, 4, 12);
    return 0;
}

//Time ComplexitY:O(n)
//Space Complexity: O(1)