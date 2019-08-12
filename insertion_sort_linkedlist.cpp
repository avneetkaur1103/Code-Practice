#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node *next;
};

void insert_in_sorted(node **head, node *new_node){
	node *curr;
	
	if (((*head) == NULL) || ((*head)->data >= new_node->data)){
		new_node->next = (*head);
		(*head) = new_node;
	}
	else{
		curr= (*head);
		while(curr->next!= NULL && curr->next->data < new_node->data)
			curr = curr->next;
		new_node->next = curr->next;
		curr->next = new_node;
	}
	
}

void Insertion_sort(node **head){
	node *curr = *head;
	node *sorted = NULL;
	while (curr != NULL){
		node *temp_next = curr->next;
		insert_in_sorted(&sorted,curr);
		curr= temp_next;
	}
	*head = sorted;
}

void push(node **head,int data){
	node *new_node = new node;
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

void print(node *head){
	node *curr = head;
	while (curr!=NULL){
		cout<<curr->data<<"->";
		curr = curr->next;
	}
	cout<<endl;
}

int main() {
	node *a = NULL;
	push(&a,45);
	push(&a, 90);
	push(&a,2);
	push(&a,15);
	push(&a,55);
	cout<<"Unsorted List: ";
	print(a);
	Insertion_sort(&a);
	cout<<"Sorted List: ";
	print(a);
	return 0;
}

//Complexity: O(n*2)