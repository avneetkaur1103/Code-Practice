#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *nextRight;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->nextRight = NULL;
	return n;
}

bool isLeaf(Node* node){
	return (node->left == NULL && node->right == NULL);
}

void findFirstNonMatchingLeaves(Node* r1, Node* r2){
	if(r1 == NULL || r2 == NULL)
		return;
	stack<Node*> s1, s2;

	s1.push(r1);
	s2.push(r2);

	while(!s1.empty() || !s2.empty()){

		if(s1.empty() || s2.empty())
			return;

		Node* tmp1 = s1.top();
		s1.pop();
		while (tmp1 && !isLeaf(tmp1) ){
			if(tmp1->right)
				s1.push(tmp1->right);
			if(tmp1->left)
				s1.push(tmp1->left);
			tmp1=s1.top();
			s1.pop();
		}

		Node* tmp2 = s2.top();
		s2.pop();
		while (tmp2 && !isLeaf(tmp2) ){
			if(tmp2->right)
				s2.push(tmp2->right);
			if(tmp2->left)
				s2.push(tmp2->left);
			tmp2=s2.top();
			s2.pop();
		}

		if(tmp1 && tmp2){
			if(tmp1->data != tmp2->data){
				cout<<"First non matching leaf nodes "<<tmp1->data<<" "<<tmp2->data<<endl;
				return;
			}
		}
	}
}

int main(){
	struct Node *root1 = newNode(5); 
    root1->left = newNode(2); 
    root1->right = newNode(7); 
    root1->left->left = newNode(10); 
    root1->left->right = newNode(11); 
  
    struct Node * root2 = newNode(6); 
    root2->left = newNode(10); 
    root2->right = newNode(15); 
  
    findFirstNonMatchingLeaves(root1,root2); 
  
    return 0; 
}

//Complexity:O(h1+h2)