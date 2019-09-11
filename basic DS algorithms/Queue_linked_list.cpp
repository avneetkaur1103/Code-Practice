#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Queue_node{
	public:
		int data;
		Queue_node *next;
};

class Queue{
	public:
		Queue_node *front, *rear;
};

Queue_node* create_new_node(int item){
	Queue_node *qnode = new Queue_node();
	qnode->data = item;
	qnode->next = NULL;
	return qnode;
}

Queue* create_new_queue(){
	Queue *q2 = new Queue();
	q2->front = q2->rear = NULL;
	return q2;
}

void enqueue(Queue *queue, int item){
	Queue_node *new_node = create_new_node(item);
	if (queue->rear == NULL){
		queue->rear = queue->front = new_node;
		return;
	}
	queue->rear->next = new_node;
	queue->rear = new_node;
}

int dequeue(Queue *queue){
	if (queue->front == NULL)
		return 0;
	Queue_node *temp = queue->front;
	queue->front = queue->front->next;
	return temp->data;
}

int main() {
	Queue *q1 = create_new_queue();
	enqueue(q1,10);
	enqueue(q1,20);
	enqueue(q1,30);
	enqueue(q1,40);
	printf("Dequeued item: %d\n",dequeue(q1));
	return 0;
}
