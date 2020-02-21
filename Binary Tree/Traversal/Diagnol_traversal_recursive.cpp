#include <iostream>
#include <map>
#include <vector>

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

void diagnol_traversal_util(struct Node* root, int level, map<int, vector<int> > &d){
	if(!root)
		return;

	d[level].push_back(root->data);

	diagnol_traversal_util(root->left,level+1,d);

	diagnol_traversal_util(root->right, level,d);
}

void diagnol_traversal(struct Node* root){
	map<int, vector<int> > diagnol;
	diagnol_traversal_util(root,0,diagnol);

	for(auto it = diagnol.begin(); it != diagnol.end(); it++){
		for(auto itr = it->second.begin(); itr != it->second.end(); itr++){
			cout<<*itr<<" ";
		
		}
		cout<<endl;
	}
}

int main(){
	struct Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7);

    diagnol_traversal(root);
    return 0;
}