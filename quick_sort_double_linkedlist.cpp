#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node *prev;
		node *next;
};

node* lastnode(node *head){
	node *curr = head;
	while(curr && curr->next)
		curr = curr->next;
		
	return curr;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

node* partition(node *l, node *h){
	int p = h->data;
	node *i = l->prev;
	node *j;
	for (j=l; j!= h; j = j->next){
		if ((j->data) <= p){
			i = (i==NULL) ? l : i->next;
			swap(&(i->data),&(j->data));
		}
	}
	i = (i==NULL)? l:i->next;
	swap(&(i->data), &(h->data));
	return i;
}

void _quicksort(node *l, node *h){
	if(h!= NULL && l!=h && l != h->next){
		node *pivot = partition(l,h);
		_quicksort(l,pivot->prev);
		_quicksort(pivot->next,h);
	}
}

void quicksort(node *head){
	node *last = lastnode(head);
	_quicksort(head,last);
}

void print(node *head){
	node *curr = head;
	while (curr != NULL){
		cout<<curr->data<<"\t";
		curr = curr->next;
	}
	cout<<endl;
}

void push(node **head, int data){
	node *new_node = new node;
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = (*head);
	if ((*head) != NULL)
		(*head)->prev = new_node;
	
	(*head) = new_node;
}
int main() {
	node *head = NULL;
	push(&head, 9);
	push(&head,12);
	push(&head,3);
	push(&head,15);
	push(&head,7);
	push(&head,45);
	push(&head,21);
	cout<<"Unsorted Array: ";
	print(head);
	quicksort(head);
	cout<<"Sorted Array: ";
	print(head);
	return 0;
}

//Complexity: Best & Avg case: o(nlogn) and Worst case: O(n^2)