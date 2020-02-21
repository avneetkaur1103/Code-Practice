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

void insertInHash(Node* root, unordered_set<int> &s){
	if(!root)
		return;

	insertInHash(root->left,s);
	s.insert(root->data);
	insertInHash(root->right,s);
}

bool checkBSTs(Node* root1, Node* root2){
	if(!root1 && !root2)
		return true;

	if((!root1 && root2) || (!root2 && root1))
		return false;

	unordered_set<int> s1, s2;
	insertInHash(root1,s1);
	insertInHash(root2,s2);

	return (s1 == s2);
}

int main() 
{
    Node* root1 = newNode(15); 
    root1->left = newNode(10); 
    root1->right = newNode(20); 
    root1->left->left = newNode(5); 
    root1->left->right = newNode(12); 
    root1->right->right = newNode(25); 

    Node* root2 = newNode(15); 
    root2->left = newNode(12); 
    root2->right = newNode(20); 
    root2->left->left = newNode(5); 
    root2->left->left->right = newNode(10); 
    root2->right->right = newNode(25); 

    if (checkBSTs(root1, root2)) 
        cout << "YES"; 
    else
        cout << "NO"; 
    return 0;         
}

//Complexity: O(n)