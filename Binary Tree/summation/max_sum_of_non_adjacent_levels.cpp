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

int maxSumUtil(Node* root){
	if(!root)
		return 0;

	int sum = root->data;

	if(root->left != NULL){
		sum += maxSumUtil(root->left->left);
		sum += maxSumUtil(root->left->right);
	}

	if(root->right != NULL){
		sum += maxSumUtil(root->right->left);
		sum += maxSumUtil(root->right->right);
	}

	return sum;
}

int maxSum(Node* root){
	return max(maxSumUtil(root), (maxSumUtil(root->left)+maxSumUtil(root->right)));
}

int main(){

    Node* root1 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->right->left = newNode(4);  
    root1->right->left->right = newNode(5);  
    root1->right->left->right->left = newNode(6); 
    cout << maxSum(root1); 
    return 0;
}

//Complexity:O(n)