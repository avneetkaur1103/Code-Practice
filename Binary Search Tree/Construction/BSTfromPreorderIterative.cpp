#include <iostream>
#include <stack>
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


Node* constructBST(int pre[], int n){
	stack<Node*> s;
	Node* root = newNode(pre[0]);
	s.push(root);

	for(int i=1;i<n;i++){
		Node* temp = NULL;
		while(!s.empty() && s.top()->data <pre[i]){
			temp = s.top();
			s.pop();
		}
			if(temp != NULL){
				temp->right = newNode(pre[i]);
				s.push(temp->right);
			}
			else{
				s.top()->left = newNode(pre[i]);
				s.push(s.top()->left);
			}
	}
	return root;
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main(){
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(pre)/sizeof(pre[0]);
	Node* root = constructBST(pre,size);
	inOrder(root);
	return 0;
}

//Complexity:O(n)