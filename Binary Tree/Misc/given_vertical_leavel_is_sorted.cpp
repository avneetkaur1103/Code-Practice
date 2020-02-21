#include <iostream>
#include <queue>
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

bool isSorted(Node* root, int level){
	if(!root)
		return true;

	queue<pair<Node*,int> > q;
	q.push(make_pair(root,0));
	int prevVal = INT_MIN;

	while(!q.empty()){
		pair<Node*,int> p = q.front();
		q.pop();

		if(p.second == level){
			if(prevVal <= p.first->data)
				prevVal = p.first->data;
			else
				return false;
		}
		if(p.first->left)
			q.push(make_pair(p.first->left,p.second-1));

		if(p.first->right)
			q.push(make_pair(p.first->right,p.second-1));
	}

	return true;
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(7); 
    root->left->right = newNode(4); 
    root->left->right->left = newNode(6); 
  
    int level = -1; 
    if (isSorted(root, level) == true) 
        cout << "Yes"; 
    else
        cout << "No"; 
    return 0; 
}

//complexity: O(n)