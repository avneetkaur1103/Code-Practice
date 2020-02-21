/* One Method: store Inorder of both BSTs, merge those arrays a& then convert merged sorted array into BST*/

/*Method with limited extra space is below:*/

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

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void merge(Node* root1, Node* root2){
	if(root1 == NULL){
		inOrder(root2);
		return;
	}

	if(root2 == NULL){
		inOrder(root1);
		return;
	}

	stack<Node*> s1;
	stack<Node*> s2;
	//s1.push(root1);
	Node* curr1 = root1;

	//s2.push(root2);
	Node* curr2 = root2;

	while(curr1 != NULL || curr2 != NULL || !s1.empty() || !s2.empty()){

		if(curr1 != NULL || curr2 != NULL){

			if(curr1 != NULL){
				s1.push(curr1);
				curr1 = curr1->left;
			}

			if(curr2 != NULL){
				s2.push(curr2);
				curr2 = curr2->left;
			}
		}
		else{
			if(s1.empty()){
				while(!s2.empty()){
					curr2 = s2.top();
					s2.pop();
					curr2->left = NULL;
					inOrder(curr2);
				}
				return;
			}

			if(s2.empty()){
				while(!s1.empty()){
					curr1 = s1.top();
					s1.pop();
					curr1->left = NULL;
					inOrder(curr1);
				}
				return;
			}

			curr1 = s1.top();
			s1.pop();
			curr2 = s2.top();
			s2.pop();

			if(curr1->data < curr2->data){
				cout<<curr1->data<<" ";
				curr1 = curr1->right;
				s2.push(curr2);
				curr2 = NULL;
			}
			else{
				cout<<curr2->data<<" ";
				curr2 = curr2->right;
				s1.push(curr1);
				curr1 = NULL;
			}
		}
	}
}

int main(){
	Node *root1 = NULL, *root2 = NULL;
	root1 = newNode(3);  
    root1->left = newNode(1);  
    root1->right = newNode(5);
    root2 = newNode(4);  
    root2->left = newNode(2);  
    root2->right = newNode(6);
    merge(root1,root2);
    return 0;
}

//Complexity: O(m+n)