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

void longestConsecutiveUtil(Node* root, int path_len, int con_num, int &res){
	if(!root)
		return;

	if(root->data == con_num)
		path_len += 1;
	else
		path_len = 1;

	res = max(path_len,res);

	longestConsecutiveUtil(root->left,path_len,root->data+1,res);
	longestConsecutiveUtil(root->right,path_len,root->data+1,res);
}

int longestConsecutive(Node* root){
	int res = 0;
	longestConsecutiveUtil(root,0,root->data,res);
	return res;
}

int main(){
	Node* root = newNode(6); 
    root->right = newNode(9); 
    root->right->left = newNode(7); 
    root->right->right = newNode(10); 
    root->right->right->right = newNode(11);
    cout<<longestConsecutive(root);
    return 0;
}

//Complexity: O(n)