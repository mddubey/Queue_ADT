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

// void** getElement(Queue* queue, int index){
// 	return (queue->elements+index);
// };

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

// void* dequeue(Queue* queue){
// 	void* element;
// 	if(isEmpty(queue))
// 		return NULL;
// 	element = *(queue->elements + queue->info.front);	//address of front element
// 	if(queue->info.front==queue->info.rear){		//Deleting Last Element
// 		queue->info.rear = queue->info.front = -1;
// 	}
// 	else if(queue->info.front==queue->info.length-1)	//Front at the End of queue
// 		queue->info.front = 0;
// 	else
// 		queue->info.front++;
// 	return element;
// };

// int isFull(Queue* queue){
// 	if(queue->info.front == 0 && queue->info.rear == queue->info.length-1)
// 		return 1;
// 	if(queue->info.front==queue->info.rear+1)
// 		return 1;
// 	return 0;
// }

// int isEmpty(Queue* queue){
// 	return queue->info.front == -1;
// }