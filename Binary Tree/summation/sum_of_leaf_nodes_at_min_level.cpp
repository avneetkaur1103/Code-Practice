#include <iostream>
#include <queue>
using namespace std;

int max_depth, sum;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* getNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int sumOfLeafNodesAtMinLevel(Node* root){
	if(!root)
		return 0;

	if(!root->left && !root->right)
		return root->data;

	queue<Node*> q;
	int sum =0;
	bool flag =0;

	q.push(root);
	
	while(flag == 0){
		int n = q.size();

		while(n){
			Node* tmp = q.front();
			q.pop();

			if(!tmp->left && !tmp->right){
				flag=1;
				sum += tmp->data;
			}
			else{
				if(tmp->left)
					q.push(tmp->left);
				if(tmp->right)
					q.push(tmp->right);
			}
			n--;
		}
	}
	return sum;
}

int main() 
{ 
    
    Node* root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->left->right->left = getNode(8); 
    root->right->left->right = getNode(9); 
  
    cout << "Sum = "
         << sumOfLeafNodesAtMinLevel(root); 
  
    return 0; 
} 

//Complexity: O(n)