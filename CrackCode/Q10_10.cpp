#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	//int rank;
	struct Node* left,*right;
	Node(int d){
		data = d;
		//rank = 0;
		left = right = NULL;
	}
};

Node* Track(Node* root, int d){
	if (root == NULL)
		return new Node(d);
	else if(d < root->data)
		root->left = Track(root->left,d);
	else
		root->right = Track(root->right,d);
	return root;
}

int getRank(int x, Node* root){
	int rank = 0;
	stack<Node*> s;
	Node* curr = root;
	while(curr != NULL || !s.empty()){
		while(curr != NULL){
			s.push(curr);
			curr = curr->left;
		}

		
		curr = s.top();
		//cout<<curr->data<<" ";
		s.pop();
		rank++;
		if(curr->data == x)
			return rank;

		curr = curr->right;
	}
}

int main(){
	struct Node *root = NULL; 
    root = Track(root, 50); 
    Track(root, 30); 
    Track(root, 20); 
    Track(root, 40); 
    Track(root, 70); 
    Track(root, 60); 
    Track(root, 80);
    
  	cout<<getRank(70,root);
    return 0;
}