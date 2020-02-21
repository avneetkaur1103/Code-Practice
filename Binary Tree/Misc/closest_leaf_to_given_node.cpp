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

void closestLeafDown(Node* root, int level, int &minDis){
	if(!root)
		return;
	if(!root->left && !root->right){
		if(level < minDis)
			minDis = level;
			return;
	}

	closestLeafDown(root->left,level+1,minDis);
	closestLeafDown(root->right,level+1,minDis);
}

int closestLeafThruParent(Node* root, Node* x, int &minDis){
	if(root == NULL)
		return -1;
	if(root == x)
		return 0;

	int l = closestLeafThruParent(root->left,x,minDis);
	if(l != -1){
		closestLeafDown(root->right,l+2,minDis);
		return l+1;
	}

	int r = closestLeafThruParent(root->right,x,minDis);
	if(r != -1){
		closestLeafDown(root->left,r+2,minDis);
		return r+1;
	}
	return -1;
}

int minimumDistance(Node* root, Node* x){
	int minDis = INT_MAX;

	closestLeafDown(x,0,minDis);
	closestLeafThruParent(root,x,minDis);
	return minDis;
}

int main(){
	Node *root  = newNode(1); 
    root->left  = newNode(12); 
    root->right = newNode(13); 
  
    root->right->left   = newNode(14); 
    root->right->right  = newNode(15); 
  
    root->right->left->left   = newNode(21); 
    root->right->left->right  = newNode(22); 
    root->right->right->left  = newNode(23); 
    root->right->right->right = newNode(24); 
  
    root->right->left->left->left  = newNode(1); 
    root->right->left->left->right = newNode(2); 
    root->right->left->right->left  = newNode(3); 
    root->right->left->right->right = newNode(4); 
    root->right->right->left->left  = newNode(5); 
    root->right->right->left->right = newNode(6); 
    root->right->right->right->left = newNode(7); 
    root->right->right->right->right = newNode(8); 
  
    Node *x = root->right; 

    cout<<minimumDistance(root, x)<<endl;
    return 0;
}

//complexity:O(n)