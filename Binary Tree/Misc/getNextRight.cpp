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

Node* getNextRightNodeUtil(Node* root, int k, int level, int &val_level){
	if(!root)
		return NULL;

	if(root->data == k){
		val_level = level;
		return NULL;
	}

	else if(val_level){
		if(val_level == level)
			return root;
	}

	Node* lNode = getNextRightNodeUtil(root->left,k,level+1,val_level);
	if(lNode)
		return lNode;

	return getNextRightNodeUtil(root->right,k,level+1,val_level);

}

int getNextRightNode(Node* root, int k){
	int val_level = 0;
	Node* nextRight = getNextRightNodeUtil(root,k,1,val_level);
	return nextRight->data;
}
int main(){
	Node* root = newNode(10); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->right->right = newNode(5); 
    root->left->left = newNode(8); 
    root->left->right = newNode(4); 
    cout<<getNextRightNode(root, 2);
    return 0;
}

//Complexity:O(n)
//Space Complexity: O(1)