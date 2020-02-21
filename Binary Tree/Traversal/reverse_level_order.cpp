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

void reverse_level_order(struct Node* root){
	stack <Node*> s;
	queue <Node*> q;

	if(!root)
		return;
	q.push(root);

	while(!q.empty()){
		struct Node *temp = q.front();
		q.pop();
		s.push(temp);

		if(temp->right)
			q.push(temp->right);

		if(temp->left)
			q.push(temp->left);
	}

	while(!s.empty()){
		struct Node* tmp = s.top();
		s.pop();
		cout<<tmp->data<<" ";
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
    cout<<"Reverse Level order traversal: "<<endl;
    reverse_level_order(root);
    return 0;
}

//Complexity: O(n)