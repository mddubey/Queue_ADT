#include "testUtils.h"
#include "queue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue* queue;

void tearDown(){
	free(queue->elements);
	free(queue);
}

int areEqual(Queue a, Queue b){
	int result = a.info.length == b.info.length && a.info.front == b.info.front
				&& a.info.rear == b.info.front &&  a.info.elementSize == b.info.elementSize ;
	if(!result) return result;
	return 0 == memcmp(a.elements,b.elements,a.info.length*a.info.elementSize);
}

void test_1_creates_a_queue_for_Integers_with_default_values_zero(){
	int _2_zeros[2] = {0,0};
	Queue expected = {_2_zeros,{2,sizeof(int),0,0}};
	queue = create(sizeof(int),2);
	ASSERT(areEqual(expected, *queue));
};

void test_2_creates_a_queue_for_doubles_elements_with_default_value_zero (){
	double _3_zeros[3] = {0.0,0.0,0.0};
	Queue expected = {_3_zeros,{3,sizeof(double),0,0}};
	queue = create(sizeof(double), 3);
	ASSERT(areEqual(expected, *queue));
};
