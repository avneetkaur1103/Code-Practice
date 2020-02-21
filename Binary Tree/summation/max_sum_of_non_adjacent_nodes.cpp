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

pair<int, int> maxSumUtil(Node* root){
	if(!root){
		return pair<int,int> (0,0);
	}

	pair<int,int> sum1 = maxSumUtil(root->left);
	pair<int, int> sum2 = maxSumUtil(root->right);
	pair<int, int> sum;

	sum.first = sum1.second + sum2.second + root->data;
	sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);

	return sum;
}

int maxSum(Node* root){
	pair<int, int> p = maxSumUtil(root);
	return max(p.first, p.second);
}

int main(){
	Node *root= newNode(10); 
    root->left= newNode(1); 
    root->left->left= newNode(2); 
    root->left->left->left= newNode(1); 
    root->left->right= newNode(3); 
    root->left->right->left= newNode(4); 
    root->left->right->right= newNode(5); 
    cout << maxSum(root)<<endl;


    Node* root1 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->right->left = newNode(4);  
    root1->right->left->right = newNode(5);  
    root1->right->left->right->left = newNode(6); 
    cout << maxSum(root1); 
    return 0;
}

//Complexity: O(n)