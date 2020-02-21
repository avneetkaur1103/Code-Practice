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

void diagnol_traversal(struct Node* root){
	if(!root)
		return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		struct Node* temp = q.front();
		q.pop();

		if(temp == NULL){
			if(q.empty())
				return;

			cout<<endl;
			q.push(NULL);
		}
		else{
			while(temp){
				cout<<temp->data<<" ";
				if(temp->left)
					q.push(temp->left);

				temp = temp->right;
			}
		}
	}
}

int main(){
	struct Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7);

    diagnol_traversal(root);
    return 0;
}