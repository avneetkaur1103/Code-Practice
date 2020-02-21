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

bool isFullBinaryTree(Node* root){
	if(!root)
		return true;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* tmp = q.front();
		q.pop();

		if(!tmp->left && !tmp->right)
			continue;

		if(!tmp->left || !tmp->right)
		return false;

		q.push(tmp->left);
		q.push(tmp->right);
	}
	return true;
}

int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    if (isFullBinaryTree(root))
    	cout<<"True";
    else
    	cout<<"False";

    return 0;
}

//Complexity: O(n)