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

int largestSubtreeSumUtil(Node* root, int &ans){
	if (!root)
		return 0;

	int res = root->data + largestSubtreeSumUtil(root->left,ans) + largestSubtreeSumUtil(root->right,ans);

	ans = max(res, ans);

	return res;
}

int largestSubtreeSum(Node* root){
	int ans = INT_MIN;
	largestSubtreeSumUtil(root,ans);
	return ans;
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(-2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(-6); 
    root->right->right = newNode(2); 
  
    cout << largestSubtreeSum(root); 
    return 0; 
}

//Complexity: O(n)