#include <iostream>
#include <vector>
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


void storeInOrder(Node* root, vector<int> &v){
    if(!root)
        return;
    storeInOrder(root->left,v);
    v.push_back(root->data);
    storeInOrder(root->right,v);
}

void pairSumUtil(vector<int> v1, vector<int> v2, int sum){
    int i=0, j=v2.size()-1;
    while(i<v1.size() && j>0){
        if(v1[i] + v2[j] == sum){
            cout<<"("<<v1[i]<<", "<<v2[j]<<")"<<endl;
            i++;
            j--;
        }
        else if(v1[i] + v2[j] < sum)
            i++;
        else
            j--;
    }
}

void pairSum(Node* root1, Node* root2, int sum){
    vector<int> v1,v2;
    storeInOrder(root1,v1);
    storeInOrder(root2,v2);

    pairSumUtil(v1,v2,sum);
}

int main()
{ 
    // first BST 
    struct Node* root1 = NULL; 
    root1 = insert(root1, 8); 
    root1 = insert(root1, 10); 
    root1 = insert(root1, 3); 
    root1 = insert(root1, 6); 
    root1 = insert(root1, 1); 
    root1 = insert(root1, 5); 
    root1 = insert(root1, 7); 
    root1 = insert(root1, 14); 
    root1 = insert(root1, 13); 
  
    // second BST 
    struct Node* root2 = NULL; 
    root2 = insert(root2, 5); 
    root2 = insert(root2, 18); 
    root2 = insert(root2, 2); 
    root2 = insert(root2, 1); 
    root2 = insert(root2, 3); 
    root2 = insert(root2, 4); 
  
    int sum = 10; 
    pairSum(root1, root2, sum); 
  
    return 0; 
}

//Complexity: O(n)