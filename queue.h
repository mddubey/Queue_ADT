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

Queue* create(int elementSize,int length);
