#include <iostream>
#include <list>
using namespace std;

int max_depth, sum;

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

Node* succIntEncoding(Node* root, list<int> &data, list<bool> &enc){
	if(!root){
		enc.push_back(0);
		return NULL;
	}

	enc.push_back(1);
	data.push_back(root->data);
	succIntEncoding(root->left,data,enc);
	succIntEncoding(root->right,data,enc);
	return root;
}

void preorder(Node* root){
	if(!root)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	Node *root         = newNode(10); 
    root->left         = newNode(20); 
    root->right        = newNode(30); 
    root->left->left   = newNode(40); 
    root->left->right  = newNode(50); 
    root->right->right = newNode(70); 

    list<int> data;
    list<bool> enc;

    root = succIntEncoding(root,data,enc);
    preorder(root);
    cout<<endl;

    list<bool>::iterator it;
    for(it=enc.begin(); it!= enc.end();it++){
    	cout<<*it<<" ";
    }
    return 0;
}

//Complexity:O(n)
