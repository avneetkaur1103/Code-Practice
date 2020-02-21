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

int longestSameValuePathUtil(Node* root, int &ans){
	if(!root)
		return 0;

	int left_p = longestSameValuePathUtil(root->left, ans);
	int right_p = longestSameValuePathUtil(root->right, ans);

	int left_max = 0, right_max = 0;

	if(root->left && root->left->data == root->data)
		left_max += left_p + 1;

	if(root->right && root->right->data == root->data)
		right_max += right_p + 1;

	ans = max(ans, left_max + right_max);
	return( max(left_max,right_max));
}

int longestSameValuePath(Node *root){
	int ans = 0;
	longestSameValuePathUtil(root, ans);
	return ans;
}

int main(int argc, char const *argv[])
{
  Node *root = NULL; 
  root = newNode(4); 
  root->left = newNode(4); 
  root->right = newNode(4); 
  root->left->left = newNode(4); 
  root->left->right = newNode(9); 
  root->right->right = newNode(5); 
  cout << longestSameValuePath(root); 
  return 0; 
}

//Complexity: O(n)