#include <iostream>
#include <queue>
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


bool  printPathsUtil(struct Node* root,  vector<Node*> &v, int x){
	if(!root)
		return false;

	v.push_back(root);

	if(root->data == x)
		return true;

	if( printPathsUtil(root->left,v,x) || printPathsUtil(root->right,v,x))
		return true;

	v.pop_back();
	return false;
}

void printPaths(struct Node* root, int x){
	vector<Node*> v;
	if(printPathsUtil(root, v, x)){
		//cout<<v.size();

		for(int i =0; i<v.size(); i++){
			cout<<v[i]->data<<" ";
		}
	}
}

int main()  
{  
    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    int x=5;
    printPaths(root,x);  
    return 0;  
}

//Complexity: O(n)