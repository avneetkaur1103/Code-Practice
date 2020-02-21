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

void printCommon(Node* r1, Node* r2){
	stack<Node*> s1,s2;

	while(1){
		if(r1){
			s1.push(r1);
			r1 = r1->left;
		}

		else if(r2){
			s2.push(r2);
			r2 = r2->left;
		}

		else if(!s1.empty() && !s2.empty()){
			r1 = s1.top();
			r2 = s2.top();

			if(r1->data == r2->data){
				cout<<r1->data<<" ";
				s1.pop();
				s2.pop();
				r1 = r1->right;
				r2 = r2->right;
			}
			else if(r1->data < r2->data){
				s1.pop();
				r1 = r1->right;
				r2 = NULL;
			}
			else if(r1->data > r2->data){
				s2.pop();
				r2 = r2->right;
				r1 = NULL;
			}
		}
		else
			break;
	}
}

struct Node* insert(Node* root, int key){
	if(root == NULL)
		return newNode(key);

	if(key < root->data)
		root->left = insert(root->left, key);
	else if(key > root->data)
		root->right = insert(root->right, key);

	return root;
}

int main(){
	Node *root1 = NULL; 
    root1 = insert(root1, 5); 
    root1 = insert(root1, 1); 
    root1 = insert(root1, 10); 
    root1 = insert(root1,  0); 
    root1 = insert(root1,  4); 
    root1 = insert(root1,  7); 
    root1 = insert(root1,  9); 
  

  	Node *root2 = NULL; 
    root2 = insert(root2, 10); 
    root2 = insert(root2, 7); 
    root2 = insert(root2, 20); 
    root2 = insert(root2, 4); 
    root2 = insert(root2, 9); 

    printCommon(root1, root2);
    return 0; 
}

//Time Complexity: O(n)
//Space Complexity: O(h1+h2)