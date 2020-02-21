#include <iostream>
#include <climits>
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

void deepestLeafNodeUtil(Node* root, int level, bool isLeft, int *max_level, Node** res){
	if (!root){
		return;
	}

	if(isLeft && root->left == NULL &&  root->right == NULL && level>*max_level){
		*max_level = level;
		*res = root;
	}

	deepestLeafNodeUtil(root->left,level+1,true,max_level,res);
	deepestLeafNodeUtil(root->right,level+1,false,max_level,res);
}

Node* deepestLeafNode(Node* root){
	if(!root)
		return NULL;
	Node* res = NULL;
	int max_level = 0;
	deepestLeafNodeUtil(root,0,false,&max_level,&res);
	return res;
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    root->right->right->right->right = newNode(10);
    Node* res = deepestLeafNode(root);
    if(res != NULL)
  	  cout<<res->data<<endl;
    return 0;
}


//We can generalize this for finding deepest node in tree, by removing isleft boolean var
//Complexity:O(n)