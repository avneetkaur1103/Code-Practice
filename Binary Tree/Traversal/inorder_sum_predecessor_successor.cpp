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

void preorder(struct Node *node){
	if(!node)
		return;

	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
} 

void storeInInorder(vector<int> &v, struct Node* root){
	if(!root)
		return;

	storeInInorder(v, root->left);
	v.push_back(root->data);
	storeInInorder(v, root->right);
}

void sum_pre_succ_util(vector<int> v,struct Node* root, int *idx){
	if(!root)
		return;

	sum_pre_succ_util(v,root->left,idx);
	root->data = v[*idx-1] + v[*idx+1];
	++*idx;
	sum_pre_succ_util(v,root->right, idx);
}

void sum_pre_succ(struct Node* root){
	if(!root)
		return;

	vector<int> v;
	v.push_back(0);
	storeInInorder(v,root);
	v.push_back(0);

	int i =1;
	sum_pre_succ_util(v,root,&i);
}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6); 
    root->right->right = newNode(7);

    cout<<"Preorder before: "<<endl;
    preorder(root);
    cout<<endl;

    sum_pre_succ(root);

    cout<<"Preorder after: "<<endl;
    preorder(root);
    cout<<endl;

    return 0;
}

//Complexity: O(n)