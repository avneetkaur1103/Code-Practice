#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void rotate(struct Node **head, int pos){
	if (pos == 0)
		return;
	struct Node *curr = *head;
	int count = 1;
	
	while(count < pos && curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	if (curr == NULL)
		return;
	
	struct Node *kthnode = curr;
	
	while (curr->next != NULL){
		curr = curr->next;
	}
	
	curr->next = *head;
	*head = kthnode->next;
	kthnode->next = NULL;
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

void insert(struct Node **head, int data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	
	new_node->next = *head;
	*head = new_node;
}

int main() {
  struct Node *a = NULL; 
 
  insert(&a,19);
  insert(&a,8);
  insert(&a,2);
  insert(&a,67);
  insert(&a,54);
  insert(&a,45);
  
  printList(a);
  rotate(&a,3);
  printList(a);
  
	return 0;
}