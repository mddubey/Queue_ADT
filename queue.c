#include "queue.h"

Queue* create(int elementSize, int length){
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	queue->elements = calloc(length, elementSize);
	queue->info.elementSize = elementSize;
	queue->info.front = 0;
	queue->info.rear = 0;
	queue->info.length = length;
	return queue;
}

void* getElement(Queue* queue, int rear){
	return (queue->elements+rear*queue->info.elementSize);
}

int enqueue(Queue* queue, void* element){
	if(queue->info.length==queue->info.rear)
		return 0;
	memmove(getElement(queue, (queue->info.rear)++), element, queue->info.elementSize);
	return 1;
}