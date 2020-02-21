#include <iostream>
#include <map>
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

void diagnolSumUtil(Node* root, map<int, int> &m, int d){
	if(!root)
		return;

	m[d] += root->data;
	diagnolSumUtil(root->left,m,d+1);
	diagnolSumUtil(root->right,m,d);

}

void diagnolSum(Node* root){
	map<int, int> m;
	diagnolSumUtil(root, m, 0);

	map<int,int>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		cout<< it->second<<" ";
	}
}

int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 

    diagnolSum(root);
    return 0;
}