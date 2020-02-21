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

void twoLineTraversal(struct Node* root){
	if(!root)
		return;

	stack<Node*> s;
	queue<Node*> q;
	struct Node* temp;
	bool dir = false; //left to right

	s.push(root);

	while(!s.empty() || !q.empty()){

		while(!s.empty()){
			temp = s.top();
			s.pop();
			cout<<temp->data<<" ";

			if(dir == false){
				if(temp->left)
					q.push(temp->left);
				if(temp->right);
					q.push(temp->right);
			}
			else{
				if(temp->right)
					q.push(temp->right);
				if(temp->left);
					q.push(temp->left);
			}
		}

		cout<<endl;

		while(!q.empty()){
			temp = q.front();
			q.pop();
			cout<<temp->data<<" ";

			if(dir == false){
				if(temp->left)
					s.push(temp->left);
				if(temp->right);
					s.push(temp->right);
			}
			else{
				if(temp->right)
					s.push(temp->right);
				if(temp->left);
					s.push(temp->left);
			}
		}

		cout<<endl;
		dir = !dir;
	}
}

int main(){
	struct Node* root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->left = newNode(6);  
    root->right->right = newNode(7);  
    root->left->left->left = newNode(8);  
    root->left->left->right = newNode(9);  
    root->left->right->left = newNode(3);  
    root->left->right->right = newNode(1);  
    root->right->left->left = newNode(4);  
    root->right->left->right = newNode(2);  
    root->right->right->left = newNode(7);  
    root->right->right->right = newNode(2);  
    root->left->right->left->left = newNode(16);  
    root->left->right->left->right = newNode(17);  
    root->right->left->right->left = newNode(18);  
    root->right->right->left->right = newNode(19);  
  
  	twoLineTraversal(root);
  	return 0;
}

//Complexity:O(n)