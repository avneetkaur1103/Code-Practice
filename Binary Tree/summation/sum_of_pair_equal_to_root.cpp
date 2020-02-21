#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

bool isPairPresentUtil(Node* node, unordered_set<int> &s,int root_data){
	if(!node)
		return false;

	int diff = root_data - (node->data);

	if(s.find(diff) != s.end())
		return true;

	s.insert(node->data);

	bool res = isPairPresentUtil(node->left,s,root_data) || isPairPresentUtil(node->right,s,root_data);

	s.erase(node->data);
	return res;
}

bool isPairPresent(Node* root){
	unordered_set<int> s;

	return (isPairPresentUtil(root->left,s,root->data) || isPairPresentUtil(root->right,s,root->data));
}

int main() 
{ 
    struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 

    isPairPresent(root) ? cout<<"Yes": cout<<"No";
    return 0;
}

//Complexity:O(n) as hash search,insert & delete take O(1)