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

Node* rightMostLeaf(Node* root){
	if (!root)
		return NULL;

	queue<Node*> q;
	q.push(root);
	Node* res = NULL;

	while(!q.empty()){
		Node* tmp = q.front();
		q.pop();

		if(tmp->left){
			q.push(tmp->left);
		}
		if(tmp->right){
			q.push(tmp->right);
			if(!tmp->right->left && !tmp->right->right)
				res = tmp->right;
		}
	}
	return res;
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    root->right->right->right->right = newNode(10);

    cout<< rightMostLeaf(root)->data;
    return 0;
}

//Complexity:O(n)