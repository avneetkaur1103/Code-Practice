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

bool check_leaves_level_utility(struct Node* root, int level, int *leaf_level){
	if(!root)
		return true;
	if(root->left == NULL && root->right == NULL){
		if(*leaf_level == 0){
			level = *leaf_level;
			return true;
		}
		return (level == *leaf_level);
	}

	return check_leaves_level_utility(root->left,level+1,leaf_level) && check_leaves_level_utility(root->right,level+1,leaf_level);
}

bool check_leaves_level(struct Node* root){
	int level =0, leaf_level =0;
	return check_leaves_level_utility(root,level,&leaf_level);
}

int main(){
	struct Node *root = newNode(12); 
    root->left = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(9); 
    root->left->left->left = newNode(1); 
    root->left->right->left = newNode(1);

    if(check_leaves_level(root))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//complexity: O(n)