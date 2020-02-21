#include <iostream>
using namespace std;

struct Node{
	char data;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void preOrder(struct Node* root){
	if (!root)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

struct Node* convertToTree(string str, int &i){
	Node* root = newNode(str[i]);
	if(i==str.length() -1)
		return root;
	i++;
	if(str[i] == '?'){
		i++;
		root->left = convertToTree(str,i);
		i++;
		root->right = convertToTree(str,i);
	}
	return root;
}

int main(){
	string str = "a?b?c:d:e";
	int i=0;
	struct Node* root = convertToTree(str,i);
	preOrder(root);
	return 0;
}

//Complexity: O(n)