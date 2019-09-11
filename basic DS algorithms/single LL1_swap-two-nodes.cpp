Program to swap 2 nodees

#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void swap_nodes(struct Node *head_ref, int x, int y) 
{ 

   if (x == y)
   return; 
  
   
   struct Node *prevX = NULL, *currX = head_ref; 
   while (currX && currX->data != x) 
   { 
       prevX = currX; 
       currX = currX->next; 
   } 
  
   struct Node *prevY = NULL, *currY = head_ref; 
   while (currY && currY->data != y) 
   { 
       prevY = currY; 
       currY = currY->next; 
   } 
  
   
   if (currX == NULL || currY == NULL) 
       return; 
  
   
   if (prevX != NULL) 
       prevX->next = currY; 
   else  
       head_ref = currY;   
  
   
   if (prevY != NULL) 
       prevY->next = currX; 
   else  
       head_ref = currX; 
  
   
   struct Node *temp = currY->next; 
   currY->next = currX->next; 
   currX->next  = temp; 
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
  swap_nodes(head, 2, 3);
  printList(head);
	return 0;
}