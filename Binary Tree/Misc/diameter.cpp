#include <iostream>
#include <climits>
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

int diameterUtil(Node* root, int &dia){
	if(!root)
		return 0;

	int lh = diameterUtil(root->left,dia);
	int rh = diameterUtil(root->right,dia);

	dia = max(dia, 1+lh+rh);

	return 1+max(lh,rh);
}

int diameter(Node* root){
	if (!root)
		return 0;

	int dia = INT_MIN;
	diameterUtil(root,dia);

	return dia;
}

int main(){
	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout<<"Diameter is: "<< diameter(root); 
  
    return 0;
}

//Complexity: O(n)