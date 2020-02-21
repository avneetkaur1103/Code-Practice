#include <iostream>
#include <stack>

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

void iterative_preorder(struct Node* root){
	if (!root)
		return;

	stack<Node*> s;

	s.push(root);

	while(!s.empty()){
		struct Node* tmp = s.top();
		cout<<tmp->data<<" ";
		s.pop();

		if(tmp->right)
			s.push(tmp->right);

		if(tmp->left)
			s.push(tmp->left);
	}

}

int main(){
	struct Node* root = newNode(10);
	root->left        = newNode(8); 
  	root->right       = newNode(2); 
  	root->left->left  = newNode(3); 
  	root->left->right = newNode(5); 
	root->right->left = newNode(9);

	iterative_preorder(root);
	return 0;
}

//Complexity: O(n)