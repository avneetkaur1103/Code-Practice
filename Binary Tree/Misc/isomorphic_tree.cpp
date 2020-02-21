#include <iostream>
#include <list>
using namespace std;

int max_depth, sum;

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

bool isIsomorphic(Node* n1, Node* n2){
	if(!n1 && !n2)
		return true;

	if(!n1 || !n2)
		return false;

	if(n1->data  == n2->data)
		return true;

	return ((isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right)) || 
			(isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left)));
}

int main(){
	struct Node *n1 = newNode(1); 
    n1->left        = newNode(2); 
    n1->right       = newNode(3); 
    n1->left->left  = newNode(4); 
    n1->left->right = newNode(5); 
    n1->right->left  = newNode(6); 
    n1->left->right->left = newNode(7); 
    n1->left->right->right = newNode(8); 
  
    struct Node *n2 = newNode(1); 
    n2->left         = newNode(3); 
    n2->right        = newNode(2); 
    n2->right->left   = newNode(4); 
    n2->right->right   = newNode(5); 
    n2->left->right   = newNode(6); 
    n2->right->right->left = newNode(8); 
    n2->right->right->right = newNode(7); 
  
    if (isIsomorphic(n1, n2) == true) 
       cout << "Yes"; 
    else
      cout << "No"; 
  
    return 0; 
} 


//Complexity: O(m) , if m<n 
//			else o(n)