#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int max_depth, sum;

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

int findMaxSum(vector<int> v,int n){
	int curr_max = v[0];
	int max_so_far = v[0];

	for(int i=1;i<n;i++){
		curr_max = max(v[i], v[i]+curr_max);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

int maxSpiralSum(Node* root){

	if(!root)
		return 0;

	if(!root->left && !root->right)
		return root->data;

	stack<Node*> s1, s2;

	s1.push(root);
	vector<int> v;

	while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){
			Node* curr = s1.top();
			s1.pop();

			v.push_back(curr->data);

			if(curr->right)
				s2.push(curr->right);
			if(curr->left)
				s2.push(curr->left);
		}

		while (!s2.empty()){

			Node* curr1 = s2.top();
			s2.pop();

			v.push_back(curr1->data);

			if(curr1->left)
				s1.push(curr1->left);
			if(curr1->right)
				s1.push(curr1->right);
		}

	}

	int n= v.size();
	//cout<<"size of v: "<<n<<endl;
	return findMaxSum(v,n);
}

int main(){
	Node* root = newNode(-2); 
    root->left = newNode(-3); 
    root->right = newNode(4); 
    root->left->left = newNode(5); 
    root->left->right = newNode(1); 
    root->right->left = newNode(-2); 
    root->right->right = newNode(-1); 
    root->left->left->left = newNode(-3); 
    root->right->right->right = newNode(2); 
  
    cout << "Maximum Spiral Sum = "
         << maxSpiralSum(root); 
  
    return 0; 
} 

//complexity: O(n)