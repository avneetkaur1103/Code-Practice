#include <iostream>
#include <queue>
using namespace std;

int max_depth, sum;

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

int delete_calcSize_tree(Node* root){
	if (!root)
		return -1;

	queue<Node*> q;
	q.push(root);
	int count = 1;

	while(!q.empty()){
		Node* tmp = q.front();
		q.pop();

		if(tmp->left){
			q.push(tmp->left);
			count++;
		}
		if(tmp->right){
			q.push(tmp->right);
			count++;
		}

		free(tmp);
	}
	return count;
}

int main(){
	Node *root =  newNode(15); 
    root->left = newNode(10); 
    root->right = newNode(20); 
    root->left->left = newNode(8); 
    root->left->right = newNode(12); 
    root->right->left = newNode(16); 
    root->right->right = newNode(25); 

    cout<<"Size of tree: "<< delete_calcSize_tree(root);
    return 0;
}

//Complexity:O(n)