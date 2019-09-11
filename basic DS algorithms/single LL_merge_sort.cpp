#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void Move_node(struct Node **source, struct Node **dest){
	struct Node *new_node = *source;
	if (new_node != NULL)
	{
		*source = new_node->next;
		new_node->next = *dest;
		*dest = new_node;
	}
}

struct Node* Merge_sorted_list(struct Node *a, struct Node *b){
	
	struct Node *result = NULL;
	
		if (a == NULL){
			return b;
		}
		else if (b == NULL){
			return a;
		}
		else{
			if(a->data <= b->data){
				result = a;
				result->next= Merge_sorted_list(a->next,b);
			}
			else{
				result = b;
				result->next = Merge_sorted_list(a,b->next);
			}
		}
	return(result);
}

void front_back_split(struct Node *source, struct Node **a, struct Node **b){
	struct Node *fast = source->next;
	struct Node *slow = source;
	
	while(fast != NULL){
		fast = fast->next;
		while(fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*a = source;
	*b = slow->next;
	slow->next=NULL;
}

void Merge_sort(struct Node **headref){
	struct Node *head = *headref;
	if (head == NULL || head->next == NULL)
		return;
	struct Node *a = NULL;
	struct Node *b = NULL;
	front_back_split(head, &a, &b);
	Merge_sort(&a);
	Merge_sort(&b);
	*headref = Merge_sorted_list(a,b);
}

void printList(struct Node *n) 
{ 
  while (n != NULL) 
  { 
     printf(" %d ", n->data); 
     n = n->next; 
  }
  printf("\n");
} 

void insert(struct Node **head, int data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	
	new_node->next = *head;
	*head = new_node;
}

int main() {
  struct Node* a = NULL; 
  
  insert(&a,19);
  insert(&a,45);
  insert(&a,2);
  insert(&a,15);
  insert(&a,1);
    
  printList(a); 
  Merge_sort(&a);
  printList(a);
	return 0;
}