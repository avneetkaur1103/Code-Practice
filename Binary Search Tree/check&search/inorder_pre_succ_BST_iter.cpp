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

void find_p_s(Node* root, int a, Node* &pre, Node* &succ){
    if(!root)
        return;
    while(root != NULL){
        if(root->data == a){
            if(root->right){
                succ = root->right;
            
               while(succ->left)
                    succ = succ->left;
            }
            if(root->left){
                pre = root->left;
            
                while(pre->right)
                    pre = pre->right;
            }
            return;
        }
        else if(root->data < a){
            pre = root;
            root = root->right;
        }
        else{
            succ = root;
            root = root->left;
        }

    }
}

int main(){
    Node* root = insert(NULL    , 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80);
    Node* p = NULL, *q = NULL; 
   
    find_p_s(root, 65, p, q); 
      
    if(p) 
        cout << p->data; 
    if(q) 
        cout << " " << q->data; 
    return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(1)