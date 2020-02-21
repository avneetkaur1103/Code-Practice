#include <iostream>
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

void traversal_line_by_line(struct Node* root){
	if(!root)
		return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	struct Node* curr = NULL;
	while(q.size() >1){
		curr = q.front();
		q.pop();

		if(curr == NULL){
			q.push(NULL);
			cout<<endl;
		}
		else{

			cout<<curr->data<<" ";

			if(curr->left)
				q.push(curr->left);

			if(curr->right)
				q.push(curr->right);
		}
	}
}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	traversal_line_by_line(root);
	return 0;
}

//Complexity: O(n)