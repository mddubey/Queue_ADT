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
				&& a.info.rear == b.info.rear &&  a.info.elementSize == b.info.elementSize ;
	if(!result) return result;
	return 0 == memcmp(a.elements,b.elements,a.info.length*a.info.elementSize);
}
//**********************************Create Tests*************************************

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

void test_3_creates_a_queue_for_Chars_elements_with_default_value_Null (){
	char _3_nulls[3] = {'\0','\0','\0'};
	Queue expected = {_3_nulls,{3,sizeof(char),0,0}};
	queue = create(sizeof(char),3);
	ASSERT(areEqual(expected, *queue));
};

void test_4_creates_a_queue_for_Strings_elements_with_default_value_blank (){
	String_256 _3_blanks[3] = {"","",""};
	Queue expected = {_3_blanks,{3,sizeof(String_256),0,0}};
	queue = create(sizeof(String_256),3);
	ASSERT(areEqual(expected, *queue));
};

//**************************************enqueue***********************************

void test_5_inserts_an_element_in_queue_at_front_end(){
	int _3_nums[3] = {12,10,0};
	int _12 = 12;
	int _10 = 10;
	Queue expected = {_3_nums,{3,sizeof(int),2,0}};
	queue = create(sizeof(int), 3);
	enqueue(queue,&_12);
	enqueue(queue,&_10);
	ASSERT(areEqual(expected, *queue));
}
