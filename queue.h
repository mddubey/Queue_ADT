#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct{
	void* elements;
	struct QueueInfo{
		int length;
		int elementSize;
		int rear;
		int front;
	}info;
}Queue;

typedef char String_256[256];
Queue* create(int elementSize,int length);
int enqueue(Queue* queue, void* element);
