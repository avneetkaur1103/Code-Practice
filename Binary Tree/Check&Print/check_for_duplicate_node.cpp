#include <iostream>
#include <unordered_set>
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

bool checkDupUtil(Node* root, unordered_set<int> &s){
	if (!root)
		return false;

	if(s.find(root->data) != s.end()){
		return true;
	}

	s.insert(root->data);

	return checkDupUtil(root->left,s) || checkDupUtil(root->right,s);
}

bool checkDup(Node* root){
	unordered_set<int> s;
	return checkDupUtil(root, s);
}

int main() 
{ 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    if (checkDup(root)) 
        printf("Yes"); 
    else
        printf("No"); 
  
    return 0; 
}

//complexity: O(n)