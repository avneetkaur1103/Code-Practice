#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* getNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int sumOfParentOfXUtil(Node* root, int x, int &sum){
	if(!root)
		return 0;

	if(((root->left) && (root->left->data == x)) || ((root->right) && (root->right->data == x)))
		sum += root->data;

	sumOfParentOfXUtil(root->left,x,sum);
	sumOfParentOfXUtil(root->right,x,sum);

	return sum;
}

int sumOfParentOfX(Node* root, int x){
	int sum =0;
	return sumOfParentOfXUtil(root,x,sum);
}

int main() 
{ 
    
    Node *root = getNode(4);          
    root->left = getNode(2);
    root->right = getNode(5);
    root->left->left = getNode(7);
    root->left->right = getNode(2);
    root->right->left = getNode(2); 
    root->right->right = getNode(3); 
      
    int x = 2;
    cout<<sumOfParentOfX(root,x);
    return 0;
}

//Complexity: O(n)