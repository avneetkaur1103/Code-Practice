#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Queue{
	public:
		int front, rear, size;
		int *array;
		unsigned capacity;
};

Queue* create_queue(unsigned capacity){
	Queue* queue = new Queue;
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity -1;
	queue->array = new int[queue->capacity * sizeof(int)];
	return queue;
}

bool isempty(Queue* queue){
	return (queue->size == 0);
}

bool isfull(Queue* queue){
	return (queue->size == queue->capacity);
}

void enqueue(Queue* queue, int data){
	if(isfull(queue)){
		printf("Queue is full\n");
		return;
	}
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = data;
	queue->size = queue->size+1;
	printf("Item is enqueued: %d\n", data);
}

int dequeue(Queue* queue){
	if (isempty(queue)){
		printf("Queue is empty\n");
	}

	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size = queue->size -1;
	return item;
}

int front(Queue* queue){
	if (isempty(queue)){
			return 0;
	}
	return queue->array[queue->front];
	
}

int rear(Queue* queue){
	if (isfull(queue)){
		return 0;
	}
	return queue->array[queue->rear];
}
int main() {
	Queue* q = create_queue(100);
	enqueue(q,10);
	enqueue(q,30);
	enqueue(q,40);
	enqueue(q,60);
	
	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));
	printf("Dequeue item:%d\n", dequeue(q));
	
	return 0;
}