#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *nextRight;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->nextRight = NULL;
	return n;
}

void pathCountsUtil(Node* root, unordered_map<int,int> &m,int path_len){
	if(!root)
		return;

	if(root->left == NULL && root->right == NULL){
		m[path_len]++;
		return;
	}
	
	pathCountsUtil(root->left,m,path_len+1);
	pathCountsUtil(root->right,m,path_len+1);
}

void pathCounts(Node* root){
	unordered_map<int,int> m;
	pathCountsUtil(root,m,1);

	unordered_map<int,int>::iterator it;

	for (it=m.begin();it != m.end(); it++){
		cout<<it->second<<" is the number of paths with length "<<it->first<<endl;
	}
}

int main(){
	struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    pathCounts(root); 
    return 0; 
}

//Complexity:O(n)