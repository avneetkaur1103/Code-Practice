#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void reverse(struct Node **head) 
{ 
	struct Node *first, *rest;
	
	if (*head == NULL)
		return;
		
	first = *head;
	
	rest = first->next;
	if (rest == NULL)
		return;
		
	reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
	return;
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


int main() {
  struct Node* head = NULL; 
  struct Node* second = NULL; 
  struct Node* third = NULL; 
  struct Node* fourth = NULL;
    
  
  head  = (struct Node*)malloc(sizeof(struct Node));  
  second = (struct Node*)malloc(sizeof(struct Node)); 
  third  = (struct Node*)malloc(sizeof(struct Node)); 
  fourth = (struct Node*)malloc(sizeof(struct Node)); 
  head->data = 1; 
  head->next = second;   
   
  second->data = 2;
  second->next = third;   
   
  third->data = 3;
  third->next = fourth;
  
  fourth->data = 4;
  fourth->next = NULL;
    
  printList(head); 
  reverse(&head);
  printList(head);
	return 0;
}