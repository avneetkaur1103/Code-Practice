#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right, *abtr;
};

struct Node* newNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = n->abtr = NULL;
    return n;
}

void preOrderTraverse(Node* root, vector<Node*> &even, vector<Node*> &odd){
    if(!root)
        return;

    if(root->data % 2 == 0)
        even.push_back(root);
    else
        odd.push_back(root);

    preOrderTraverse(root->left,even,odd);
    preOrderTraverse(root->right,even,odd);
}

void createLoops(Node* root){
    vector<Node*> even, odd;
    preOrderTraverse(root, even, odd);

    int i;
    for(i=1;i<even.size();i++){
        even[i-1]->abtr = even[i];
    }
    even[i-1]->abtr = even[0];

    for(i=1;i<odd.size();i++){
        odd[i-1]->abtr = odd[i];
    }
    odd[i-1]->abtr = odd[0];
}

void traverseLoop(Node* root){
    if(!root)
        return;

    Node* curr = root;

    do{
        cout<<curr->data<<" ";
        curr = curr->abtr;
    }while(curr != root);
}

int main() 
{
    Node* root = newNode(1);       
    root->left = newNode(2);             
    root->right = newNode(3);        
    root->left->left = newNode(4);     
    root->left->right = newNode(5);      
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
      
    createLoops(root); 
      
    
    cout << "Odd nodes: "; 
    traverseLoop(root->right); 
      
    cout << endl << "Even nodes: "; 
    traverseLoop(root->left);     
      
    return 0; 
} 

//Complexity:O(n)