#include "queue.h"
#include <memory.h>
#include <stdlib.h>
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue* queue;

void tearDown(){
	free(queue->elements);
	free(queue);
}

int areEqual(Queue a, Queue b){
	int result = a.info.length == b.info.length && a.info.front == b.info.front
				&& a.info.rear == b.info.rear;
	if(!result) return result;
	return 0 == memcmp(a.elements,b.elements,a.info.length*sizeof(void*));
}
//**********************************Create Tests*************************************

void test_1_creates_a_queue_for_Integers_with_default_values_zero(){
	void* _2_Nulls[2] = {NULL,NULL};
	Queue expected = {_2_Nulls,{2,-1,-1}};
	queue = create(2);
	ASSERT(areEqual(expected, *queue));
};

void test_2_creates_a_queue_for_doubles_elements_with_default_value_zero (){
	void* _3_nulls[3] = {NULL,NULL,NULL};
	Queue expected = {_3_nulls,{3,-1,-1}};
	queue = create(3);
	ASSERT(areEqual(expected, *queue));
};

void test_3_creates_a_queue_for_Chars_elements_with_default_value_Null (){
	void* _3_nulls[3] = {NULL,NULL,NULL};
	Queue expected = {_3_nulls,{3,-1,-1}};
	queue = create(3);
	ASSERT(areEqual(expected, *queue));
};

void test_4_creates_a_queue_for_Strings_elements_with_default_value_blank (){
	void* _3_Nulls[3] = {NULL,NULL,NULL};
	Queue expected = {_3_Nulls,{3,-1,-1}};
	queue = create(3);
	ASSERT(areEqual(expected, *queue));
};
	

// //**************************************enqueue***********************************

// void test_5_inserts_an_element_in_queue_at_rear_end_Integer(){
// 	int* _12 = malloc(4);
// 	double* _10 = malloc(8);
// 	char* name = malloc(20);
// 	name = "Raaz";
// 	*_12 = 12;*_10 = 10.0;
// 	queue = create(3);
// 	enqueue(queue,_12);
// 	ASSERT(12 == **(int**)getElement(queue, 0));
// 	enqueue(queue,_10);
// 	ASSERT(10.0 == **(double**)getElement(queue, 1));
// 	enqueue(queue,name);
// 	ASSERT("Raaz" == *(char**)getElement(queue, 2));
// }

void test_5_inserts_an_element_in_queue_at_rear_end_Integer(){
	int nums[] = {12,10};
	queue = create(3);
	enqueue(queue, &nums[0]);
	ASSERT(12 == **(int**)getElement(queue, 0));
	ASSERT(0 == queue->info.rear);
	enqueue(queue, &nums[1]);
	ASSERT(10 == **(int**)getElement(queue, 1));
	ASSERT(1 == queue->info.rear);
}

// void test_6_inserts_an_element_in_queue_at_rear_end_doubles(){
	// double* nums = malloc(3*sizeof(double));
	// *nums = 10.0;*(nums+sizeof(double)) = 12.0;
	// queue = create(3);
	// enqueue(queue, nums[0]);
	// ASSERT(0 == queue->info.rear);
	// enqueue(queue,&nums[1]);
// }

// void test_7_inserts_an_element_in_queue_at_rear_end_characters(){
// 	char _3_chars[3] = {'w','q','\0'};
// 	char _w = 'w';
// 	char _q = 'q';
// 	Queue expected = {_3_chars,{3,sizeof(char),2,0}};
// 	queue = create(sizeof(char), 3);
// 	enqueue(queue,&_w);
// 	enqueue(queue,&_q);
// 	ASSERT(areEqual(expected, *queue));
// }

// void test_8_inserts_an_element_in_queue_at_rear_end_Strings(){
// 	String_256 _3_names[3] = {"raj","Digs",""};
// 	String_256 raj = "raj";
// 	String_256 Digs = "Digs";
// 	Queue expected = {_3_names,{3,sizeof(String_256),2,0}};
// 	queue = create(sizeof(String_256), 3);
// 	enqueue(queue,raj);
// 	enqueue(queue,Digs);
// 	ASSERT(areEqual(expected, *queue));
// }

// //**************************Dequeue******************************************

// void test_10_deletes_the_first_element_of_queue(){
// 	int _3_nums[3] = {12,0,0};
// 	int *res;
// 	int _12 = 12;
// 	int _10 = 10;
// 	queue = create(sizeof(int), 3);
// 	enqueue(queue, &_12);
// 	enqueue(queue, &_10);
// 	res = dequeue(queue);
// 	printf("%d\n",*res );
// 	ASSERT(12==*res);
// }
