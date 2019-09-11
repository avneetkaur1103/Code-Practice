Length of linked list:

1. Iterative:
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

int length_of_linked_list(struct Node* head){
	int count = 0;
	struct Node* curr = head;
	while(curr != NULL){
		count++;
		curr = curr->next;
	}
	return count;
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
  printf("%d\n",length_of_linked_list(head));
	return 0;
}


Complexity: O(n)

2. Recursive:
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

int get_count(struct Node* head){
	if (head == NULL)
		return 0;
	else 
		return 1+get_count(head->next);
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
  printf("%d\n",get_count(head));
	return 0;
}

Complexity: O(n)