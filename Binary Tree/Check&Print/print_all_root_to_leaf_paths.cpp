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

void printArray(int paths[], int idx){
	for (int i=0; i<idx; i++)
		cout<<paths[i]<<" ";

	cout<<endl;
}

void  printPathsRec(struct Node* root, int paths[], int idx){
	if(!root)
		return;

	paths[idx] = root->data;
	idx++;

	if(!root->left && !root->right)
		printArray(paths,idx);

	printPathsRec(root->left,paths,idx);
	printPathsRec(root->right,paths,idx);
}

void printPaths(struct Node* root){
	int paths[100];
	printPathsRec(root, paths, 0);
}

int main()  
{  
    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  

    printPaths(root);  
    return 0;  
}

//Complexity: O(n)