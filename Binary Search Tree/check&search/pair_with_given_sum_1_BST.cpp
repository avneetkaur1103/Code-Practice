#include <iostream>
#include <unordered_set>
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

Node* insert(Node* root, int key){
    if(!root)
        return newNode(key);

    if (key < root->data){
        root->left = insert(root->left,key);
    }
    else if(key > root->data){
        root->right = insert(root->right,key);
    }

    return root;
}

void findPairUtil(Node* root, int sum, unordered_set<int> &s){
	if(!root)
		return;

	findPairUtil(root->left,sum,s);

	if(s.find(sum - root->data) != s.end()){
		cout<<"Found pair: ("<<sum-root->data<<", "<<root->data<<")"<<endl;
	}
	else
		s.insert(root->data);

	findPairUtil(root->right,sum,s);
}

void findPair(Node* root, int sum){
	unordered_set<int> s;
	findPairUtil(root,sum,s);
}

int main() 
{ 
    Node* root = NULL; 
    root = insert(root, 15); 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 12); 
    root = insert(root, 16); 
    root = insert(root, 25); 
    root = insert(root, 10); 
  
    int sum = 33; 
    findPair(root, sum); 
  
    return 0;
}
//Complexity: O(n)