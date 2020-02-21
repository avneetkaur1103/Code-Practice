#include <iostream>

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

int sumOfHeightsUtil(Node* root, int &sum){
	if (!root)
		return 0;

	int lh = sumOfHeightsUtil(root->left,sum);
	int rh = sumOfHeightsUtil(root->right,sum);

	int h = max(lh,rh) + 1;
	sum+= h;
	return h;
}

int sumOfHeights(Node* root){
	int sum = 0;
	sumOfHeightsUtil(root,sum);
	return sum;
}

int main(){
	struct Node* root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);
    cout<<sumOfHeights(root);
    return 0;
}

//Complexity: O(nh)