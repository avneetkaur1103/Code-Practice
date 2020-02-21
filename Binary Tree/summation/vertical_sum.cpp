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

void verticalSumUtil(Node* root, int hd, map<int,int> &m){
	if(!root)
		return;

	verticalSumUtil(root->left,hd-1,m);
	m[hd] += root->data;
	verticalSumUtil(root->right,hd+1,m);
}

void verticalSum(Node* root){
	int hd =0;
	map<int,int> m;
	map<int,int>::iterator it;
	verticalSumUtil(root,hd,m);

	for(it= m.begin();it != m.end();it++){
		cout<<it->first<<" -> "<<it->second<<endl;
	}
}

int main()
{
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    verticalSum(root);
	return 0;
}

//complexity:O(n)