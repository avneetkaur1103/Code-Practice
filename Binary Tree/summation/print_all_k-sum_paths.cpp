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

void printVector(vector<int> v,int j){
	for (int i=j;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

void printKPathUtil(Node* root, int k, vector<int> v){
	if(!root)
		return;

	v.push_back(root->data);
	printKPathUtil(root->left, k,v);
	printKPathUtil(root->right,k,v);

	int sum =0;
	for(int j = v.size()-1; j >=0; j--){
		sum += v[j];

		if(sum == k)
		printVector(v,j);

	}

	v.pop_back();
}

void printKPath(Node* root, int k){
	vector<int> v;
	printKPathUtil(root, k, v);
}

int main(){
	Node *root = newNode(1); 
    root->left = newNode(3); 
    root->left->left = newNode(2); 
    root->left->right = newNode(1); 
    root->left->right->left = newNode(1); 
    root->right = newNode(-1); 
    root->right->left = newNode(4); 
    root->right->left->left = newNode(1); 
    root->right->left->right = newNode(2); 
    root->right->right = newNode(5); 
    root->right->right->right = newNode(2); 
  
    int k = 5; 
    printKPath(root, k); 
    return 0;
}

//Complexity: O(n)

//Amazon