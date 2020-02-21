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

bool isLeaf(struct Node* tmp){
	if(!tmp)
		return false;

	if (!tmp->left && !tmp->right)
		return true;

	return false;
}

bool check_leaf_traversal(struct Node* root1, struct Node* root2){
	if(!root1 || !root2)
		return false;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root1);
	s2.push(root2);

	struct Node* tmp1 = NULL;
	struct Node* tmp2 = NULL;

	while(!s1.empty() || !s2.empty()){
		if(s1.empty() || s2.empty())
			return false;
		tmp1=s1.top();
		tmp2 = s2.top();

		s1.pop();
		s2.pop();

		while(tmp1 != NULL && !isLeaf(tmp1)){
			if(tmp1->right != NULL)
			s1.push(tmp1->right);
			if(tmp1->left != NULL)
			s1.push(tmp1->left);
			tmp1 = s1.top();
			s1.pop();
		}
		
		while(tmp2 != NULL && !isLeaf(tmp2)){
			if(tmp2->right != NULL)
				s2.push(tmp2->right);
			if(tmp2->left != NULL)
				s2.push(tmp2->left);
			tmp2 = s2.top();
			s2.pop();
		}
		if(tmp1 && tmp2)
			return tmp1->data == tmp2->data;
		else
			return false;
	}
	return true;
}

int main(){
	Node* root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->right->left = newNode(6); 
    root1->right->right = newNode(7); 
      
    Node* root2 = newNode(0); 
    root2->left = newNode(1); 
    root2->right = newNode(5); 
    root2->left->right = newNode(4); 
    root2->right->left = newNode(6); 
    root2->right->right = newNode(8);  

    if(check_leaf_traversal(root1,root2))
    	cout<<"True";
    else
    	cout<<"False";
    return 0;
}

//complexity: O(n)