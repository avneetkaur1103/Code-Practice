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

Node* insert(Node* root, int key){
    if(!root)
        return newNode(key);

    if(key<root->data)
        root->left = insert(root->left,key);
    if(key>root->data)
        root->right = insert(root->right,key);

    return root;
}

bool deadEnd(Node* root,int min = 0, int max = INT_MAX){
    if(!root)
        return false;
    if(min == max)
        return true;

   return (deadEnd(root->left,min,root->data -1) || (deadEnd(root->right,root->data+1,max)));
}

int main(){
    Node* root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 5); 
    root = insert(root, 2); 
    root = insert(root, 3); 
    root = insert(root, 7); 
    root = insert(root, 11); 
    root = insert(root, 4); 
    if (deadEnd(root) == true) 
        cout << "Yes " << endl; 
    else
        cout << "No " << endl; 
    return 0;
}