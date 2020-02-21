#include <iostream>
#include <stack>

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

void Inorder(struct Node *root){
	stack <Node*> s;
	struct Node* current = root;

	while(current != NULL || !s.empty()){
		while(current != NULL){
			s.push(current);
			current = current->left;
		}

		current = s.top();
		s.pop();
		cout<<current->data<<" ";
		current = current->right;

	}
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	Inorder(root);
	return 0;
}

//Complexity: O(n)