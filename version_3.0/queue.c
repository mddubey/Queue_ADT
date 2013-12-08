#include "queue.h"
#include <memory.h>
#include <stdlib.h>

Queue* create(){
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

void enqueue(Queue* queue, void* element){
	Queue_element* current_item = (Queue_element*)malloc(sizeof(Queue_element));
	(current_item->next) = NULL;
	(current_item->item) = element;
	if(queue->rear == NULL){
		queue->front = current_item;
	}
	else
		(queue->rear->next) = current_item;
	queue->rear = current_item;
}

Queue_element* dequeue(Queue* queue){
	Queue_element* element;
	//Should I calloc/malloc here for element because i am returning this address
	if(isEmpty(queue))
		return NULL;
	element = queue->front;
	// free(queue->front);// I should free the deleted element in test case or library
	queue->front = queue->front->next;
	return element;
};

int isEmpty(Queue* queue){
	return queue->front == NULL;
}