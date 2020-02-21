#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

bool haspath(Node* root, int sum){
	if(!root)
		return (sum == 0);

	bool ans = false;

	int rem_sum = sum - root->data;
	if(rem_sum == 0 && root->left == NULL && root->right == NULL)
		return true;
	
	if(root->left)
		ans = ans || haspath(root->left, rem_sum);
	if(root->right)
		ans = ans || haspath(root->right,rem_sum);

	return ans;
}

int main(){
	Node *root = newnode(10);  
    root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);  
    root->right->left = newnode(2);  
    int sum = 21;

    haspath(root,sum)? cout<<"true" : cout<<"false";
    return 0;
}

//complexity: O(n)