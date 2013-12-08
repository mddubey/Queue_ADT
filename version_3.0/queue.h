typedef struct qElement{
	struct qElement* next;
	void* item;
}Queue_element;

typedef struct{
	Queue_element* rear;
	Queue_element* front;
}Queue;

typedef char String_256[256];
Queue* create();
void enqueue(Queue* queue, void* element);
Queue_element* dequeue(Queue* queue);
void** getElement(Queue* queue, int index);
int isFull(Queue* queue);
int isEmpty(Queue* queue);