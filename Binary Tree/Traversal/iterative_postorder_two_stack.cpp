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

void iterative_postorder_two_stack(struct Node* root){
	if (!root)
		return;

	stack<Node*> s1, s2;
	s1.push(root);

	while(!s1.empty()){
		struct Node* temp = s1.top();
		s1.pop();
		s2.push(temp);

		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
	}

	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
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

	iterative_postorder_two_stack(root);
	return 0;
}

//complexity: O(n)