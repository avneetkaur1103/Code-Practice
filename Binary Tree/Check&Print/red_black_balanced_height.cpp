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

bool isBalancedRedBlackUtil(Node* root, int &maxh, int &minh){
	if(!root){
		maxh = minh = 0;
		return true;
	}

	int lmaxh=0, lminh=0, rmaxh=0, rminh=0;

	if (isBalancedRedBlackUtil(root->left,lmaxh,lminh)	== false)
		return false;

	if (isBalancedRedBlackUtil(root->right,rmaxh,rminh)	== false)
		return false;

	maxh = max(lmaxh,rmaxh) + 1;
	minh = min(lminh,rminh) + 1;

	//cout<<"Max h: "<<maxh <<" and Min h: "<<minh<<endl;
	if(maxh <= 2*minh)
		return true;

	return false;
}

bool isBalancedRedBlack(Node* root){
	int maxh,minh;
	return isBalancedRedBlackUtil(root,maxh,minh);
}

int main(){
	Node * root = newNode(10); 
    root->left = newNode(5); 
    root->right = newNode(100); 
    root->right->left = newNode(50); 
    root->right->right = newNode(150); 
    root->right->left->left = newNode(40);
     
    if(isBalancedRedBlack(root))
    	cout<<"True";
    else
    	cout<<"False";

    return 0;
}

//complexity: O(n)