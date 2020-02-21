#include <iostream>
#include <stack>
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

void _push(Node **head, Node* tmp){
	tmp->right = (*head);
	tmp->left = NULL;

	if((*head) != NULL)
		(*head)->left = tmp;
	
	(*head) = tmp;
}


void printList(struct Node* head){
	while (head != NULL){
		cout<<head->data<<" ";
		head = head->right;
	}
}

void buildListFromTreeSpiral(struct Node* root){
	if(!root)
		return;

	int level = 0;
	deque<Node*> d;
	d.push_front(root);

	stack<Node*> s;

while(!d.empty()){
	int nCount = d.size();

	if(level&1){
		
		while(nCount > 0){
			Node* tmp = d.front();
			d.pop_front();
			s.push(tmp);

			if(tmp->left != NULL)
				d.push_back(tmp->left);
			//cout<<d.back()->data<<endl;
			if(tmp->right != NULL)
				d.push_back(tmp->right);
			//cout<<d.back()->data<<endl;
			nCount --;
		}
	}
	else{
		while(nCount > 0){
			Node* tmp = d.back();
			d.pop_back();
			s.push(tmp);

			if(tmp->right != NULL)
				d.push_front(tmp->right);
			//cout<<d.front()->data<<endl;
			if(tmp->left != NULL)
				d.push_front(tmp->left);
			//cout<<d.front()->data<<endl;
			nCount --;
		}
	}

	level++;
	//cout<<"level: "<<level<<endl;
}


	struct Node *head = NULL;
	while(!s.empty()){
		_push(&head,s.top());
		s.pop();
	}

	printList(head);
}

int main(){
	struct Node *root =  newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
  
    buildListFromTreeSpiral(root);

    
    return 0;
}

//Complexity: O(n)