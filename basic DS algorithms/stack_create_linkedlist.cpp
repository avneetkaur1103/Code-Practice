#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node* new_node(int d){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = d;
	new_node->next = NULL;
	return new_node;
}

bool isempty(struct node* head){
	return !head;
}

void push(struct node **root,int data){
	struct node *stacknewnode = new_node(data);
	stacknewnode->next = *root;
	*root = stacknewnode;
	printf("pushed\n");
}

int pop(struct node **root){
	if(isempty(*root)){
		return 0;
	}
	else{
		struct node *temp = *root;
		*root = (*root)->next;
		int temp1 =  temp->data;
		free(temp);
		
		return temp1;
	}
}

int main() {
	struct node* s = NULL;
	push(&s,10);
	push(&s,20);
	push(&s,30);
	printf("%d\n",pop(&s));
	return 0;
}