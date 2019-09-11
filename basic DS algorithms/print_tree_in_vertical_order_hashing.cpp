#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* new_node(int data){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void getVertOrder(node *root,int hd,map<int,vector<int>> &m){
	if (root == NULL)
		return;
	m[hd].push_back(root->data);
	getVertOrder(root->left,hd-1,m);
	getVertOrder(root->right,hd+1,m);
}

void PrintVertOrder(node *root){
	map<int,vector<int>> m;
	int hd = 0;
	getVertOrder(root,hd,m);
	map<int,vector<int>>::iterator it;
	for (it=m.begin();it!=m.end();it++){
		for (int i=0;i<it->second.size();++i){
			cout<<it->second[i]<< " ";
		}
		cout<<endl;
	}
}

int main() {
	node *root = new_node(1);
	root->left = new_node(3);
	root->right = new_node(5);
	root->left->left = new_node(7);
	root->left->right = new_node(11);
	root->right->left = new_node(13);
	root->right->right = new_node(17);
	PrintVertOrder(root);
	return 0;
}