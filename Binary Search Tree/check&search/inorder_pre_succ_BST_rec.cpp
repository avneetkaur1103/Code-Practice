#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;
};

struct Node* getnode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int key){
    if(!root)
        return getnode(key);

    if(key<root->data)
        root->left = insert(root->left,key);
    if(key>root->data)
        root->right = insert(root->right,key);

    return root;
}

void find_p_s(Node* root, int a, Node** p, Node** q){
    if(!root)
        return;

    find_p_s(root->left,a,p,q);

    if(root->data > a){
        if((!*q) || ((*q) && (root->data<(*q)->data) ))
            (*q) = root;
    }
        if(root->data < a)
            (*p) = root;
    
    find_p_s(root->right,a,p,q);

}

int main(){
    Node* root1 = getnode(50); 
    root1->left = getnode(20); 
    root1->right = getnode(60); 
    root1->left->left = getnode(10); 
    root1->left->right = getnode(30); 
    root1->right->left = getnode(55); 
    root1->right->right = getnode(70); 
    Node* p = NULL, *q = NULL; 
   
    find_p_s(root1, 55, &p, &q); 
      
    if(p) 
        cout << p->data; 
    if(q) 
        cout << " " << q->data; 
    return 0;
}

//Complexity: O(n)