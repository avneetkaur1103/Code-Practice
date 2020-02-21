#include <iostream>
#include <map>
using namespace std;

#define N 6

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

struct Node* tree_from_anc_matrix(int mat[][N]){
	int parent[N] = {0};
	Node* node[N];

	multimap<int, int> mm;
	Node* root = NULL;

	for(int i=0;i<N;i++){
		int sum = 0;
		for(int j=0; j<N; j++){
			sum += mat[i][j];
		}

		mm.insert(pair<int,int>(sum,i));
	}

	for(auto it=mm.begin(); it != mm.end(); it++){
		node[it->second] = newNode(it->second);
		root = node[it->second];

		if(it->first != 0){
			for(int i=0;i<N;i++){
				if(!parent[i] && mat[it->second][i] != 0){
					if(!root->left)
						root->left = node[i];
					else
						root->right = node[i];
					parent[i] = 1;
				}

			}
		}
	}
	return root;
}

void inorder(struct Node* root){
	if(!root)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


int main(){
	int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 }, 
        { 1, 0, 0, 0, 1, 0 }, 
        { 0, 0, 0, 1, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 1, 1, 1, 1, 1, 0 } 
    };

    struct Node *root = tree_from_anc_matrix(mat);

    inorder(root);
    return 0;
}