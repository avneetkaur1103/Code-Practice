#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void delete_Node_at_pos(struct Node *head_ref, int position) 
{
   if (head_ref == NULL) 
      return; 
  
   
   struct Node* temp = head_ref; 
  
    
    if (position == 0) 
    { 
        head_ref = temp->next;   
        free(temp);               
        return; 
    } 
  
    
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    
    struct Node *next = temp->next->next; 
    free(temp->next);
    temp->next = next;
}

int main (){
	return 0;
}