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

void getTargetLeaf(Node* root, int *max_sum, int curr_sum, Node** leaf){
	if(!root)
		return;

	curr_sum += root->data;

	if(!root->left && !root->right){
		if(*max_sum < curr_sum){
			*max_sum = curr_sum;
			*leaf = root;
		}
	}

	getTargetLeaf(root->left,max_sum,curr_sum,leaf);
	getTargetLeaf(root->right,max_sum,curr_sum,leaf);
}

bool print_path(Node* root, Node* leaf){
	if(!root)
		return false;

	if(root->data == leaf->data || print_path(root->left,leaf) || print_path(root->right,leaf)){
		cout<<root->data<<" ";
		return true;
	}

	return false;
}

int maxSumPath(Node* root){
	int sum =0;
	if(!root)
		return INT_MIN;

	int max_sum = INT_MIN;
	Node* leaf = NULL;
	getTargetLeaf(root, &max_sum,0,&leaf);
	print_path(root,leaf);
	cout<<endl;
	return max_sum;
}

int main(){
	Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(7); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 
    cout<<maxSumPath(root);
    return 0;
}

//Complexity: O(n)