#include <iostream>
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

int Ceil(Node* root, int input){
    if(!root)
        return -1;

    if(root->data == input)
        return root->data;

    else if(root->data < input)
        return Ceil(root->right,input);

    else{
        int ceil = Ceil(root->left,input);
        if(ceil>=input)
            return ceil;
        else
            return root->data;
    }
}

int main() 
{ 
    Node* root = newNode(8); 
  
    root->left = newNode(4); 
    root->right = newNode(12); 
  
    root->left->left = newNode(2); 
    root->left->right = newNode(6); 
  
    root->right->left = newNode(10); 
    root->right->right = newNode(14); 
  
    for (int i = 0; i < 16; i++) 
        cout << i << " " << Ceil(root, i) << endl; 
  
    return 0; 
}

//Complexity:O(n)