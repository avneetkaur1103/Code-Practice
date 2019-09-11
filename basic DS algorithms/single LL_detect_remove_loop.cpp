#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void removeloop(struct Node *loop_point, struct Node *head);

int Detectandremoveloop(struct Node *head){
	struct Node *fast_ptr = head;
	struct Node *slow_ptr = head;
	while(fast_ptr && slow_ptr && fast_ptr->next){
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
		if (slow_ptr == fast_ptr){
			removeloop(slow_ptr, head);
			return 1;
		}
	}
	return 0;
}

void removeloop(struct Node *loop_point, struct Node *head){
	struct Node *ptr1;
	struct Node *ptr2;
	ptr1 = head;
	while(1){
		ptr2 = loop_point;
		
		while(ptr2->next != ptr1 && ptr2->next != loop_point)
			ptr2 = ptr2->next;
			
			if (ptr2->next == ptr1)
				break;
			
			ptr1 = ptr1->next;
	}
		ptr2->next = NULL;
	
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
  
  a->next->next->next->next->next->next = a->next->next;
   
  printf("%d\n",Detectandremoveloop(a));
  
  printList(a);
	return 0;
}