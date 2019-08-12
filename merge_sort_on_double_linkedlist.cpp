#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

void push(node **head, int data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	
	if (!(*head))
		(*head) = new_node;
	else{
		new_node->next = *head;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

void frontbacksplit(node *head, node **a, node **b){
	node* slow;
	node* fast;
	slow = head;
	fast = head->next;
	
	while(fast->next != NULL){
		fast = fast->next;
		if(fast->next != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}
struct node* merge(node* a,node* b){
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	
	
	if (a->data <= b->data){
		a->next = merge(a->next,b);
		a->next->prev = a;
		a->prev = NULL;
		return a;
	}
	else{
		b->next = merge(a,b->next);
		b->next->prev = b;
		b->prev = NULL;
		return b;
	}
	
}

void merge_sort(struct node **head){
	node* head1 = *head;
	if (head1 == NULL || head1->next == NULL)
		return;
		
	node *a;
	node *b;
	frontbacksplit(head1, &a, &b);
	
	merge_sort(&a);
	merge_sort(&b);
	
	*head = merge(a,b);
}

void print_list(struct node* node){
	
	while(node->next != NULL){
		cout<<node->data<<"->";
		node = node->next;
	}
	cout<<endl;
}

int main() {
	struct node *head = NULL;
	push(&head,2);
	push(&head,12);
	push(&head,9);
	push(&head,23);
	push(&head,55);
	push(&head, 37);
	print_list(head);
	merge_sort(&head);
	print_list(head);
	return 0;
}

//Complexity:O(nlogn)