#include <iostream>
#include <string>
#include <unordered_map>

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

string printAllDupsUtil(Node* root, unordered_map<string,int> &m){
	if(!root)
		return "";

	string str ="(";
	str += printAllDupsUtil(root->left,m);
	str += to_string(root->data);
	str+= printAllDupsUtil(root->right,m);
	str += ")";

	if(m[str] == 1)
		cout<<root->data<<" ";

	m[str]++;

	return str;

}

void printAllDups(Node* root){
	unordered_map<string, int> m;
	printAllDupsUtil(root,m);
}

int main(){
	Node* root = NULL; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(2); 
    root->right->left->left = newNode(4); 
    root->right->right = newNode(4); 
    printAllDups(root); 
    return 0; 
}

//Complexity:O(n)