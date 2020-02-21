#include <iostream>
#include <stack>
#include <queue>
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

void specific_order_binary_tree_util(struct Node* root, stack<Node*> &s){

	if(!root)
		return;

	queue<Node*> q;

	
	q.push(root->left);
	q.push(root->right);
	
	while(! q.empty()){
		struct Node* first=NULL, *second=NULL;
		first = q.front();
		q.pop();
		second = q.front();
		q.pop();

		s.push(second->left);
		s.push(first->right);
		s.push(second->right);
		s.push(first->left);


		if(first->left->left){
			q.push(first->right);
			q.push(second->left);
			q.push(first->left);
			q.push(second->right);
		}
	}

}

void specific_order_binary_tree(struct Node* root){
	if(!root)
		return;

	stack<Node*> s;
	s.push(root);
	
	if(root->left){
		s.push(root->right);
		s.push(root->left);
	}

	if(root->left->left)
		specific_order_binary_tree_util(root,s);

	while(!s.empty()){
		struct Node* temp;
		temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
	}
	
}

int main(){

	struct Node *root = newNode(1); 
  
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 
  
  	cout<<"specific order traversal of binary tree: "<<endl;
  	specific_order_binary_tree(root);
  	return 0;
}

	//Complexity: O(n)