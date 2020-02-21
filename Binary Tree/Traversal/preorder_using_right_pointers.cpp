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

void modify(struct Node* root){
	if(!root)
		return;
	stack<Node*> s;
	s.push(root);
	struct Node* pre = NULL;

	while(!s.empty()){
		struct Node* temp = s.top();
		s.pop();

		if(temp->right)
			s.push(temp->right);

		if(temp->left)
			s.push(temp->left);

		if(pre != NULL)
			pre->right = temp;

		pre = temp;
	}
}

void print(struct Node* root){
	if(!root)
		return;
	
	while(root){
		cout<<root->data<<" ";
		root = root->right;
	}
}


int main(){
	struct Node* root = newNode(10); 
    root->left = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 

    modify(root);
    print(root);
    return 0;
}