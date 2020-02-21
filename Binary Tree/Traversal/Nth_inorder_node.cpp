#include <iostream>
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

void nthInorderNode(struct Node *root, int n){
	static int count = 0;
	if(!root)
		return;

	if(count<=n){
		
		nthInorderNode(root->left,n);
		count++;
		//cout<<"Count: "<<count<<endl; 
		if(count == n)
			cout<<root->data;
		nthInorderNode(root->right,n);
	}
}

int main(){
	struct Node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	int n=4;
	nthInorderNode(root,n);
	return 0;
}

//Complexity: O(n)