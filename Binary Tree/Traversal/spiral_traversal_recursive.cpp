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

int height(struct Node* root){
	if (!root)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	if(lh>rh)
		return lh+1;
	else
		return rh+1;
}

void print_traversal(struct Node* root, bool ltr, int level){
	if(!root)
		return;
	if(level == 1)
		cout<<root->data<<" ";
	else{
		if(ltr){
			print_traversal(root->left,ltr,level-1);
			print_traversal(root->right,ltr,level-1);
		}
		else{
			print_traversal(root->right,ltr,level-1);
			print_traversal(root->left,ltr,level-1);
		}
	}
}

void spiral_traversal_rec(struct Node* root){
	bool ltr = false;
	int h = height(root);
	//cout<<"Height of tree: "<<h<<endl;
	for(int i=1;i<=h; i++){
		print_traversal(root, ltr, i);
		ltr = !ltr;
	}
}


int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 

    cout<<"Spiral recursive traversal: "<<endl;
    spiral_traversal_rec(root);
    return 0;
}

//Complexity: O(n^2)