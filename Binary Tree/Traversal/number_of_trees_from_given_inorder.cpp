#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void preorder(struct Node* root){
	if(root != NULL){
		cout<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

vector<Node*> number_of_trees(int arr[], int start, int end){
	vector<Node*> trees;

	if(start > end){
		trees.push_back(NULL);
		return trees;
	}

	for(int i=start;i<=end;i++){
		

		vector<Node*> ltrees = number_of_trees(arr,start,i-1);
		vector<Node*> rtrees = number_of_trees(arr,i+1,end);

		for(int j=0;j<ltrees.size();j++){
			for(int k=0;k<rtrees.size();k++){
				struct Node* node = newNode(arr[i]);
				node->left = ltrees[j];
				node->right = rtrees[k];
				trees.push_back(node);
			}
		}
	}
	return trees;
}


int main(){
	int in[] = {4,5,7};
	int n= sizeof(in)/sizeof(in[0]);
	vector<Node *> trees = number_of_trees(in,0,n-1);

	for(int i=0;i<trees.size();i++){
		preorder(trees[i]);
		cout<<endl;
	}
	return 0;
}