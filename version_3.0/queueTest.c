#include "queue.h"
#include <memory.h>
#include <stdlib.h>
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue* queue;

void tearDown(){
	free(queue);
}

int areEqual(Queue a, Queue b){
	return a.front == b.front && a.rear == b.rear;
}

typedef struct 
{
	int accNo;
	int balance;
}Account;

int areAccountsEqual(Account expected,Account actual){
	return expected.accNo == actual.accNo && expected.balance == actual.balance;
}
// //**********************************Create Tests*************************************

void test_1_creates_a__dynamic_queue(){
	Queue expected = {NULL,NULL};
	queue = create();
	ASSERT(areEqual(expected, *queue));
};
//**************************************enqueue***********************************

void test_2_insert_first_element_into_queue_rear_and_front_are_same(){
	int* num = malloc(sizeof(int));
	queue = create();
	num[0] = 10;
	enqueue(queue, &num[0]);
	ASSERT(NULL == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT(10 == *(int*)(queue->rear->item) && 10 == *(int*)(queue->front->item));
	free(num);
};

void test_3_insert_second_element_in_queue_first_element_points_to_second (){
	int* num = malloc(sizeof(int)*2);
	queue = create();
	num[0] = 10;num[1] = 12;
	enqueue(queue, &num[0]);
	ASSERT(NULL == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT(10 == *(int*)(queue->rear->item) && 10 == *(int*)(queue->front->item));
	enqueue(queue, &num[1]);
	ASSERT(queue->rear == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT(12 == *(int*)(queue->rear->item) && 10 == *(int*)(queue->front->item));
	free(num);
};

void test_4_insert_second_element_in_queue_first_element_points_to_second_doubles (){
	double* num = malloc(sizeof(double)*2);
	queue = create();
	num[0] = 10.0;num[1] = 12.0;
	enqueue(queue, &num[0]);
	ASSERT(NULL == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT(10.0 == *(double*)(queue->rear->item) && 10.0 == *(double*)(queue->front->item));
	enqueue(queue, &num[1]);
	ASSERT(queue->rear == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT(12.0 == *(double*)(queue->rear->item) && 10.0 == *(double*)(queue->front->item));
	free(num);
};

void test_5_insert_second_element_in_queue_first_element_points_to_second_characters (){
	char* chars = malloc(sizeof(char)*2);
	queue = create();
	chars[0] = 'a';chars[1] = 'b';
	enqueue(queue, &chars[0]);
	ASSERT(NULL == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT('a' == *(char*)(queue->rear->item) && 'a' == *(char*)(queue->front->item));
	enqueue(queue, &chars[1]);
	ASSERT(queue->rear == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT('b' == *(char*)(queue->rear->item) && 'a' == *(char*)(queue->front->item));
	free(chars);
};

void test_6_insert_second_element_in_queue_first_element_points_to_second_strings (){
	String_256* names = malloc(sizeof(String_256)*2);
	queue = create();
	strcpy(names[0], "Rajesh");
	strcpy(names[1], "Raman");
	enqueue(queue, names[0]);
	ASSERT(NULL == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT((0 == strcmp("Rajesh", queue->rear->item)) &&
			 (0 == strcmp("Rajesh", queue->front->item)));
	enqueue(queue, names[1]);
	ASSERT(queue->rear == (queue->front->next) && NULL == (queue->rear->next));
	ASSERT((0 == strcmp("Raman", queue->rear->item)) &&
			 (0 == strcmp("Rajesh", queue->front->item)));
	free(names);
};

void test_7_insert_second_element_in_queue_first_element_points_to_second_Structs (){
	Account* accounts = malloc(sizeof(Account)*2);
	Account* result;
	accounts[0].accNo = 100;accounts[0].balance = 1000;
	accounts[1].accNo = 101;accounts[1].balance = 2000;
	queue = create();
	enqueue(queue, &accounts[0]);
	ASSERT(NULL == (queue->front->next) &&
			 NULL == (queue->rear->next));
	ASSERT(areAccountsEqual(accounts[0], *(Account*)(queue->front->item)) &&
	 areAccountsEqual(accounts[0], *(Account*)(queue->rear->item)));

	enqueue(queue, &accounts[1]);
	ASSERT(queue->rear == (queue->front->next) &&
			 NULL == (queue->rear->next));
	ASSERT(areAccountsEqual(accounts[0], *(Account*)(queue->front->item)) &&
	 areAccountsEqual(accounts[1], *(Account*)(queue->rear->item)));
	free(accounts);
};

//**************************Dequeue******************************************

void test_8_deletes_the_front_element_of_queue_single_element_in_queue(){
	int* nums = malloc(sizeof(int)*2);
	Queue_element *result;
	nums[0] = 12;
	queue = create();
	enqueue(queue, &nums[0]);
	result = dequeue(queue);
	ASSERT(12 == *(int*)result->item && NULL == result->next);
	ASSERT(NULL == queue->front);
	free(nums);
};

void test_9_deletes_the_front_element_of_queue_and_sets_next_element_as_front(){
	int* nums = malloc(sizeof(int)*2);
	Queue_element *result;
	Queue_element *rear;
	nums[0] = 12;
	nums[1] = 10;
	queue = create();
	enqueue(queue, &nums[0]);
	enqueue(queue, &nums[1]);
	rear = queue->rear;
	result = dequeue(queue);
	ASSERT(12 == *(int*)result->item && rear == result->next);
	ASSERT(10 == *(int*)queue->front->item && NULL == queue->front->next);
	free(nums); 
};

void test_10_deletes_the_front_element_of_queue_single_element_in_queue_doubles(){
	double* nums = malloc(sizeof(double)*2);
	Queue_element *result;
	nums[0] = 12.0;
	queue = create();
	enqueue(queue, &nums[0]);
	result = dequeue(queue);
	ASSERT(12.0 == *(double*)result->item && NULL == result->next);
	ASSERT(NULL == queue->front);
	free(nums);
};

void test_11_deletes_the_front_element_of_queue_and_sets_next_element_as_front_doubles(){
	double* nums = malloc(sizeof(double)*2);
	Queue_element *result;
	Queue_element *rear;
	nums[0] = 12.0;
	nums[1] = 10.0;
	queue = create();
	enqueue(queue, &nums[0]);
	enqueue(queue, &nums[1]);
	rear = queue->rear;
	result = dequeue(queue);
	ASSERT(12.0 == *(double*)result->item && rear == result->next);
	ASSERT(10.0 == *(double*)queue->front->item && NULL == queue->front->next);
	free(nums); 
};

void test_12_deletes_the_front_element_of_queue_single_element_in_queue_chars(){
	char* chars = malloc(sizeof(char)*2);
	Queue_element *result;
	chars[0] = 'm';
	queue = create();
	enqueue(queue, &chars[0]);
	result = dequeue(queue);
	ASSERT('m' == *(char*)result->item && NULL == result->next);
	ASSERT(NULL == queue->front);
	free(chars);
};

void test_13_deletes_the_front_element_of_queue_and_sets_next_element_as_front_chars(){
	char* nums = malloc(sizeof(char)*2);
	Queue_element *result;
	Queue_element *rear;
	nums[0] = 'm';
	nums[1] = 'a';
	queue = create();
	enqueue(queue, &nums[0]);
	enqueue(queue, &nums[1]);
	rear = queue->rear;
	result = dequeue(queue);
	ASSERT('m' == *(char*)result->item && rear == result->next);
	ASSERT('a' == *(char*)queue->front->item && NULL == queue->front->next);
	free(nums); 
};

void test_14_deletes_the_front_element_of_queue_single_element_in_queue_String(){
	String_256* names = malloc(sizeof(String_256)*2);
	Queue_element *result;
	strcpy(names[0], "MDAK");
	queue = create();
	enqueue(queue, names[0]);
	result = dequeue(queue);
	ASSERT((0 == strcmp("MDAK", (char*)result->item)) && NULL == result->next);
	ASSERT(NULL == queue->front);
	free(names);
};

void test_15_deletes_the_front_element_of_queue_and_sets_next_element_as_front_Strings(){
	String_256* names = malloc(sizeof(String_256)*2);
	Queue_element *result;
	Queue_element *rear;
	strcpy(names[0], "mdak");
	strcpy(names[1], "MDAK");
	queue = create();
	enqueue(queue, names[0]);
	enqueue(queue, names[1]);
	rear = queue->rear;
	result = dequeue(queue);
	ASSERT((0 == strcmp("mdak", (char*)result->item)) && rear == result->next);
	ASSERT((0 == strcmp("MDAK", (char*)queue->front->item)) &&
			 NULL == queue->front->next);
	free(names); 
};

void test_16_deletes_the_front_element_of_queue_single_element_in_queue_structurs(){
	Account* accounts = malloc(sizeof(Account)*2);
	Queue_element* result;
	accounts[0].accNo = 100;accounts[0].balance = 1000;
	queue = create();
	enqueue(queue, &accounts[0]);
	result = dequeue(queue);
	ASSERT(areAccountsEqual(accounts[0], *(Account*)(result->item)));
	ASSERT(NULL == result->next);
	ASSERT(NULL == queue->front);
	free(accounts);
}

void test_17_deletes_the_front_element_of_queue_single_element_in_queue_structurs(){
	Account* accounts = malloc(sizeof(Account)*2);
	Queue_element* result;
	Queue_element *rear;
	accounts[0].accNo = 100;accounts[0].balance = 1000;
	accounts[1].accNo = 101;accounts[1].balance = 2000;
	queue = create();
	enqueue(queue, &accounts[0]);
	enqueue(queue, &accounts[1]);
	rear = queue->rear;
	result = dequeue(queue);
	ASSERT(areAccountsEqual(accounts[0], *(Account*)result->item));
	ASSERT(rear==result->next);
	ASSERT(areAccountsEqual(accounts[1], *(Account*)queue->front->item));
	ASSERT(NULL == queue->front->next);
	free(accounts);
}
// void test_14_gives_null_during_deletion_if_queue_is_empty(){
// 	Account* accounts = malloc(sizeof(Account));
// 	Account* result;
// 	queue = create(1);
// 	ASSERT(-1 == queue->info.rear && -1 == queue->info.front);
// 	result = dequeue(queue);
// 	ASSERT(NULL == result);
// 	ASSERT(-1 == queue->info.rear && -1 == queue->info.front);
// 	free(accounts);
// }

// // //************************************isFull*****************************

// void test_15_tells_the_queue_is_full_front_zero(){
// 	int* num = malloc(sizeof(int));
// 	int result;
// 	*num = 10;
// 	queue = create(1);
// 	enqueue(queue, num);
// 	result = isFull(queue);
// 	ASSERT(1==result);
// 	free(num);
// }

// void test_16_tells_the_queue_is_full_front_is_one_more_then_rear(){
// 	int* num = malloc(sizeof(int)*2);
// 	int result;
// 	num[0] = 10;num[1] = 12;
// 	queue = create(2);
// 	enqueue(queue, &num[0]);
// 	enqueue(queue, &num[1]);
// 	dequeue(queue);
// 	enqueue(queue, &num[1]);
// 	ASSERT(1 == queue->info.front && 0 == queue->info.rear);
// 	result = isFull(queue);
// 	ASSERT(1==result);
// 	free(num);
// }

// void test_17_tells_the_queue_is_not_full(){
// 	int result;
// 	queue = create(1);
// 	result = isFull(queue);
// 	ASSERT(0 == result);
// }

// // //************************isEmpty**************************
// void test_18_tells_the_queue_is_Empty(){
// 	int result;
// 	queue = create(1);
// 	result = isEmpty(queue);
// 	ASSERT(1==result);
// }

// void test_19_tells_the_queue_is_not_Empty(){
// 	int* num = malloc(sizeof(int));
// 	int result;
// 	*num = 10;
// 	queue = create(1);
// 	enqueue(queue, num);
// 	result = isEmpty(queue);
// 	ASSERT(0==result);
// 	free(num);
// }



// //***************************************Some Cases******************

// void test_20_inserts_the_element_at_the_starting_of_queue_if_rear_is_end_of_queue(){
// 	Account* accounts = malloc(sizeof(Account)*2);
// 	Account expected = {101,2000};
// 	accounts[0].accNo = 100;accounts[0].balance = 1000;
// 	accounts[1].accNo = 101;accounts[1].balance = 2000;
// 	queue = create(3);
// 	ASSERT(-1 == queue->info.front && -1 == queue->info.rear);
// 	enqueue(queue,&accounts[0]);
// 	enqueue(queue,&accounts[1]);
// 	enqueue(queue,&accounts[0]);
// 	ASSERT(0 == queue->info.front && 2 == queue->info.rear);
// 	dequeue(queue);
// 	enqueue(queue,&accounts[1]);
// 	ASSERT(1 == queue->info.front && 0 == queue->info.rear);
// 	ASSERT(areAccountsEqual(expected, **(Account**)getElement(queue, 0)));
// 	free(accounts);
// }
