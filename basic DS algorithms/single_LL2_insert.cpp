Program to insert into Single linked list

#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void Insert_at_front(struct Node* head, int d){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = d;
	new_node->next = head;
	head = new_node;
}

void Insert_at_End(struct Node* head, int d){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* curr = head;
	new_node->data = d;
	
	while (curr->next != NULL){
		curr = curr->next;		
	}
	new_node = curr->next;
	new_node->next = NULL;
}

void Insert_after_a_node(struct Node* head, int d, int k){
	struct Node* new_node = (struct Node*)malloc (sizeof (struct Node));
	new_node->data = d;
	struct Node* curr = head;
	while(curr->data != k){
		curr = curr->next;
	}
	
	new_node->next = curr->next;
	curr->next = new_node;
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
    
  
  head  = (struct Node*)malloc(sizeof(struct Node));  
  second = (struct Node*)malloc(sizeof(struct Node)); 
  third  = (struct Node*)malloc(sizeof(struct Node)); 
   
  head->data = 1; 
  head->next = second;   
   
  second->data = 2;
  second->next = third;   
   
  third->data = 3;
  third->next = NULL;
  
  printList(head); 
  
  Insert_at_front(head,4);
  Insert_at_End(head,5);
  printList(head);

	return 0;
}