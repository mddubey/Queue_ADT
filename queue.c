#include "queue.h"
#include <memory.h>
#include <stdlib.h>

Queue* create(int length){
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	queue->elements = calloc(length, sizeof(void*));
	queue->info.front = -1;
	queue->info.rear = -1;
	queue->info.length = length;
	return queue;
}

void** getElement(Queue* queue, int index){
	return (queue->elements+index);
};

int enqueue(Queue* queue, void* element){
	*getElement(queue, ++(queue->info.rear)) = element;
	return 1;;
}

// int dequeue(Queue* queue){
// 	int sourceSize = (queue->info.length-1)*queue->info.elementSize;
// 	memmove(queue->elements, queue->elements+(queue->info.elementSize), sourceSize);
// 	return 1;
// };