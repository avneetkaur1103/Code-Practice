#include <iostream>
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

void preOrder(Node* root){
	if(!root)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

vector<Node*> constructTrees(int s, int e){
	vector<Node*> BSTRoots;
	if(s>e){
		BSTRoots.push_back(NULL);
		return BSTRoots;
	}

	for(int i=s;i<=e;i++){
		vector<Node*> BSTLeft = constructTrees(s,i-1);
		vector<Node*> BSTRight = constructTrees(i+1,e);

		for(int j=0;j<BSTLeft.size();j++){
			Node* lNode = BSTLeft[j];

			for(int k=0;k<BSTRight.size();k++){
				Node* rNode = BSTRight[k];

				Node* node = newNode(i);
				node->left = lNode;
				node->right = rNode;
				BSTRoots.push_back(node);
			}
		}
	}

	return BSTRoots;
}

int main(){
	int n = 3;
	vector<Node*> BSTList1toN = constructTrees(1,n);

	for(int i=0;i<BSTList1toN.size();i++){
		preOrder(BSTList1toN[i]);
		cout<<endl;
	}
	return 0;
}