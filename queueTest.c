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
	int* nums = (int*)malloc(sizeof(int)*2);
	nums[0] = 12;
	nums[1] = 10; 
	queue = create(3);
	enqueue(queue, &nums[0]);
	ASSERT(12 == **(int**)getElement(queue, 0));
	ASSERT(0 == queue->info.rear);
	enqueue(queue, &nums[1]);
	ASSERT(10 == **(int**)getElement(queue, 1));
	ASSERT(1 == queue->info.rear);
}

void test_6_inserts_an_element_in_queue_at_rear_end_doubles(){
	double* nums = malloc(2*sizeof(double));
	nums[0] = 12.0;nums[1] = 10.0;
	queue = create(3);
	enqueue(queue, &nums[0]);
	ASSERT(12.0 == **(double**)getElement(queue, 0));
	ASSERT(0 == queue->info.rear);
	enqueue(queue,&nums[1]);
	ASSERT(10.0 == **(double**)getElement(queue, 1));
	ASSERT(1 == queue->info.rear);
}

void test_7_inserts_an_element_in_queue_at_rear_end_characters(){
	char* chars = malloc(sizeof(char)*3);
	chars[0] = 'w';chars[1] = 'q';
	queue = create(3);
	enqueue(queue,&chars[0]);
	ASSERT('w' == **(char**)getElement(queue,0));
}

void test_8_inserts_an_element_in_queue_at_rear_end_Strings(){
	char* name = malloc(10);
	name = "Digs";
	queue = create(3);
	enqueue(queue,name);
	ASSERT("Digs" == *(char**)getElement(queue, 0));
}

void test_9_gives_error_if_stack_is_full(){
	int* nums = malloc(2*sizeof(int));
	int res;
	queue = create(1);
	nums[0] = 12;nums[1] = 10;
	res = enqueue(queue, &nums[0]);
	ASSERT(1 == res);
	ASSERT(12 == **(int**)getElement(queue, 0));
	res = enqueue(queue, &nums[1]);
	ASSERT(0 == res);
}

typedef struct 
{
	int accNo;
	int balance;
}Account;

int areAccountsEqual(Account expected,Account actual){
	return expected.accNo == actual.accNo && expected.balance == actual.balance;
}
void test_10_inserts_an_element_in_queue_at_rear_end_Structure(){
	Account* account = malloc(sizeof(Account));
	Account expected = {100,5000};
	account->accNo = 100;account->balance=5000;
	queue = create(1);
	enqueue(queue,account);
	ASSERT(areAccountsEqual(expected, **(Account**)getElement(queue, 0)));
}

// //**************************Dequeue******************************************

void test_11_deletes_the_first_element_of_queue(){
	int* nums = malloc(sizeof(int)*2);
	int *res;
	nums[0] = 12;
	nums[1] = 10;
	queue = create(3);
	enqueue(queue, &nums[0]);
	enqueue(queue, &nums[1]);
	ASSERT(1==queue->info.rear);
	res = dequeue(queue);
	ASSERT(12==*res);
	ASSERT(0==queue->info.rear);
};

void test_12_shift_left_remaining_elements_after_deletion(){
	double* nums = malloc(sizeof(double)*3);
	nums[0] = 1.0;nums[1] = 2.0;nums[2] = 3.0;
	queue = create(3);
	enqueue(queue, &nums[0]);
	enqueue(queue, &nums[1]);
	enqueue(queue, &nums[2]);
	ASSERT(1.0 == **(double**)getElement(queue, 0));
	ASSERT(2.0 == **(double**)getElement(queue, 1));
	ASSERT(3.0 == **(double**)getElement(queue, 2));
	dequeue(queue);
	ASSERT(2.0 == **(double**)getElement(queue, 0));
	ASSERT(3.0 == **(double**)getElement(queue, 1));
}


