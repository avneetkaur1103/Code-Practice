#include <iostream>
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

void sumOfNodesAtMaxDepth(Node* root, int level){
	if(!root)
		return;
	
	if(level > max_depth){
		max_depth = level;
		sum = root->data;
	}

	else if(level == max_depth){
		sum+=root->data;
	}

	sumOfNodesAtMaxDepth(root->left,level+1);
	sumOfNodesAtMaxDepth(root->right,level+1);
}


int main() 
{ 
    Node *root; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    sumOfNodesAtMaxDepth(root, 0); 
    cout<<sum;
    return 0;
}

//complexity: O(n)