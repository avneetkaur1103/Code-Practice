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
	struct Node dummy;
	struct Node *tail = &dummy;
	dummy.next = NULL;
	
	while(1){
		if (a == NULL){
			tail->next = b;
			break;
		}
		else if (b == NULL){
			tail->next = a;
			break;
		}
		else{
			if(a->data <= b->data){
				Move_node(&a, &(tail->next));
			}
			else{
				Move_node(&b, &(tail->next));
			}
			tail = tail->next;
		}
	}
	return(dummy.next);
	
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
  struct Node* b = NULL; 
  struct Node* result = NULL; 
  
  insert(&a,19);
  insert(&a,8);
  insert(&a,2);
  
  insert(&b,15);
  insert(&b,1);
    
  printList(a); 
  printList(b);
  result = Merge_sorted_list(a,b);
  printList(result);
	return 0;
}