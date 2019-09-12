#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void BFS(struct Node* root){

	if(root == NULL)
		return;

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp;

	while(!q.empty()){
		temp = q.front();
		q.pop();

		cout<<temp->data<<" ";

		if(temp->left)
			q.push(temp->left);


		if(temp->right)
			q.push(temp->right);

	}
}

int main(){
	struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  	cout<<"Breadth First Search: "<<endl;
  	BFS(root);
  	return 0;
}

//Complexity: O(n)