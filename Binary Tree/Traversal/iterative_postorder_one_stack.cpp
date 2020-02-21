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

void iterative_postorder_one_stack(struct Node* root){
	if (!root)
		return;

	stack<Node*> s;
	s.push(root);

	do{
		while(root){
			if(root->right)
				s.push(root->right);
			s.push(root);
			root = root->left;
		}

		root = s.top();
		s.pop();

		if(root->right && root->right->data == s.top()->data){
			//struct Node* temp1 = s.top();
			s.pop();
			s.push(root);
			root = root->right;
		}
		else{
			cout<<root->data<<" ";
			root = NULL;
		}
	}while(!s.empty());
}

int main(){
	struct Node* root = newNode(1);
	root->left        = newNode(2); 
  	root->right       = newNode(3); 
  	root->left->left  = newNode(4); 
  	root->left->right = newNode(5); 
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	iterative_postorder_one_stack(root);
	return 0;
}