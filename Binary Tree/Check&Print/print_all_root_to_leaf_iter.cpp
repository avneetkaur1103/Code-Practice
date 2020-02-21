#include <iostream>
#include <stack>
#include <map>
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

void printArray(Node* n, map<Node*,Node*> parent){
	stack<Node*> s;

	while(n){
		s.push(n);
		n = parent[n];
	}

	while(!s.empty()){
		struct Node* curr = s.top();
		s.pop();

		cout<<curr->data<<" ";
	}

	cout<<endl;
}

void printPaths(struct Node* root){
	if(!root)
		return;

	stack<Node*> s;
	map<Node*, Node*> parent;

	s.push(root);
	parent[root] = NULL;

	while(!s.empty()){
		struct Node* tmp = s.top();
		s.pop();

		if(!tmp->left && !tmp->right)
			printArray(tmp,parent);

		if(tmp->right){
			parent[tmp->right] = tmp;
			s.push(tmp->right);
		}

		if(tmp->left){
			parent[tmp->left] = tmp;
			s.push(tmp->left);
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

    printPaths(root);  
    return 0;  
}

//Complexity: O(n)