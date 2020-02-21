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

bool isMirrorTree(struct Node* root1, struct Node* root2){
	if(!root1 && !root2)
		return true;

	queue<Node*> q1,q2;
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty()){
        struct Node* tmp1 = q1.front();
        struct Node* tmp2 = q2.front();
        q1.pop();
        q2.pop();

        if(!tmp1 && !tmp2)
            return true;

        if(!tmp1 || !tmp2)
            return false;

        if(tmp1->data != tmp2->data)
            return false;

        if(tmp1->left)
            q1.push(tmp1->left);
        if(tmp1->right)
            q1.push(tmp1->right);

        if(tmp2->right)
            q2.push(tmp2->right);
        if(tmp2->left)
            q2.push(tmp2->left);
    }
    return true;
}

int main(){
	Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 

    if(isMirrorTree(a,b))
    	cout<<"Yes";
    else
    	cout<<"No";
    return 0;
}

//complexity: O(n)