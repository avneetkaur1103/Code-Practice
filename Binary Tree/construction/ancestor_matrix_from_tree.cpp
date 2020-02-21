#include <iostream>
#include <vector>
#include <climits>

#define MAX 100

bool mat[MAX][MAX];

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

int ancestor_matrix_rec(struct Node* root, vector<int> &anc){
	if(!root)
		return 0;

	int data = root->data;
	for(int i = 0; i<anc.size(); i++){
		mat[anc[i]][data] = true;
	}

	anc.push_back(data);

	int l = ancestor_matrix_rec(root->left,anc);
	int r = ancestor_matrix_rec(root->right, anc);

	anc.pop_back();

	return l+r+1;
}

void ancestor_matrix(struct Node* root){
	if(!root)
		return;

	vector<int> anc;
	int n = ancestor_matrix_rec(root, anc);

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	struct Node* root = newNode(5);
	root->left        = newNode(1); 
    root->right       = newNode(2); 
    root->left->left  = newNode(0); 
    root->left->right = newNode(4); 
    root->right->left = newNode(3);

    ancestor_matrix(root);
    return 0;
}

//complexity: O(n^2)