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
