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


// // void test_5_nserts_an_element_in_queue_at_rear_end_Integer(){
// // 	int* _12 = malloc(4);
// // 	double* _10 = malloc(8);
// // 	char* name = malloc(20);
// // 	name = "Raaz";
// // 	*_12 = 12;*_10 = 10.0;
// // 	queue = create(3);
// // 	enqueue(queue,_12);
// // 	ASSERT(12 == **(int**)getElement(queue, 0));
// // 	enqueue(queue,_10);
// // 	ASSERT(10.0 == **(double**)getElement(queue, 1));
// // 	enqueue(queue,name);
// // 	ASSERT("Raaz" == *(char**)getElement(queue, 2));
// // }

// void test_5_inserts_first_elemetnt_in_queue_queue_and_front_increase_by_one(){
// 	int* nums = (int*)malloc(sizeof(int)*1);
// 	*nums = 12;
// 	queue = create(3);
// 	ASSERT(-1 == queue->info.front && -1 == queue->info.rear);
// 	enqueue(queue, &nums[0]);
// 	ASSERT(0 == queue->info.front && 0 == queue->info.rear);
// 	ASSERT(12 == **(int**)getElement(queue, 0));
// 	free(nums);
// }

// void test_6_inserts_a_double_in_queue_at_rear_end_only_rear_increase(){
// 	double* nums = malloc(2*sizeof(double));
// 	nums[0] = 12.0;nums[1] = 10.0;
// 	queue = create(3);
// 	enqueue(queue, &nums[0]);
// 	ASSERT(12.0 == **(double**)getElement(queue, 0));
// 	ASSERT(0 == queue->info.rear && 0 == queue->info.front);
// 	enqueue(queue,&nums[1]);
// 	ASSERT(10.0 == **(double**)getElement(queue, 1));
// 	ASSERT(1 == queue->info.rear && 0 == queue->info.front);
// 	free(nums);
// }


// void test_7_inserts_an_element_in_queue_at_rear_end_Strings(){
// 	char* name = malloc(10);
// 	name = "Digs";
// 	queue = create(3);
// 	enqueue(queue,name);
// 	ASSERT("Digs" == *(char**)getElement(queue, 0));
// 	ASSERT(0==queue->info.front && 0 == queue->info.rear);
// 	// free(name);
// }

// void test_8_gives_error_if_stack_is_full(){
// 	int* nums = malloc(2*sizeof(int));
// 	int res;
// 	queue = create(1);
// 	nums[0] = 12;nums[1] = 10;
// 	res = enqueue(queue, &nums[0]);
// 	ASSERT(1 == res);
// 	ASSERT(12 == **(int**)getElement(queue, 0));
// 	res = enqueue(queue, &nums[1]);
// 	ASSERT(0 == res);
// 	free(nums);
// }

// typedef struct 
// {
// 	int accNo;
// 	int balance;
// }Account;

// int areAccountsEqual(Account expected,Account actual){
// 	return expected.accNo == actual.accNo && expected.balance == actual.balance;
// }
// void test_9_inserts_an_element_in_queue_at_rear_end_Structure(){
// 	Account* account = malloc(sizeof(Account));
// 	Account expected = {100,5000};
// 	account->accNo = 100;account->balance=5000;
// 	queue = create(1);
// 	ASSERT(-1 == queue->info.front && -1 == queue->info.rear);
// 	enqueue(queue,account);
// 	ASSERT(0 == queue->info.front && 0 == queue->info.rear);
// 	ASSERT(areAccountsEqual(expected, **(Account**)getElement(queue, 0)));
// 	free(account);
// }

// // // //**************************Dequeue******************************************

// void test_10_deletes_the_front_element_of_queue_front_is_zero_and_increase_front(){
// 	int* nums = malloc(sizeof(int)*2);
// 	int *res;
// 	nums[0] = 12;
// 	nums[1] = 10;
// 	queue = create(3);
// 	enqueue(queue, &nums[0]);
// 	enqueue(queue, &nums[1]);
// 	ASSERT(0==queue->info.front);
// 	res = dequeue(queue);
// 	ASSERT(12==*res);
// 	ASSERT(1==queue->info.front);
// 	free(nums);
// };

// void test_11_deletes_the_last_element_of_queue_and_sets_front_and_rear_minus_1(){
// 	double* nums = malloc(sizeof(double));
// 	double *res;
// 	nums[0] = 1.0;
// 	queue = create(3);
// 	enqueue(queue, &nums[0]);
// 	ASSERT(0==queue->info.front && 0 == queue->info.rear);
// 	res = dequeue(queue);
// 	ASSERT(1.0==*res);
// 	ASSERT(-1 == queue->info.front && -1 == queue->info.rear);
// 	free(nums);
// };

// void test_12_set_front_to_zero_if_front_is_at_the_end_of_queue(){
// 	String_256* names = malloc(sizeof(String_256)*2);
// 	char* delete_name_1;
// 	char* delete_name_2;
// 	strcpy(names[0], "Rajesh");
// 	strcpy(names[1], "Raman");
// 	queue = create(2);
// 	enqueue(queue, &names[0]);
// 	enqueue(queue, &names[1]);
// 	ASSERT(0 == queue->info.front && 1 == queue->info.rear);
// 	delete_name_1 = dequeue(queue);
// 	ASSERT(0==strcmp(delete_name_1, "Rajesh"));
// 	ASSERT(1 == queue->info.front && 1 == queue->info.rear);
// 	enqueue(queue, &names[0]);
// 	ASSERT(1 == queue->info.front && 0 == queue->info.rear);
// 	delete_name_2 = dequeue(queue);
// 	ASSERT(0==strcmp(delete_name_2, "Raman"));
// 	ASSERT(0 == queue->info.front && 0 == queue->info.rear);
// 	free(names);
// }

// void test_13_deletes_a_structure_from_a_queue(){
// 	Account* accounts = malloc(sizeof(Account)*2);
// 	Account* result;
// 	accounts[0].accNo = 100;accounts[0].balance = 1000;
// 	accounts[1].accNo = 101;accounts[1].balance = 2000;
// 	queue = create(2);
// 	enqueue(queue, &accounts[0]);
// 	enqueue(queue, &accounts[1]);
// 	ASSERT(0 == queue->info.front && 1 == queue->info.rear);
// 	ASSERT(areAccountsEqual(accounts[0], **(Account**)getElement(queue, 0)));
// 	ASSERT(areAccountsEqual(accounts[1], **(Account**)getElement(queue, 1)));
// 	result = dequeue(queue);
// 	ASSERT(areAccountsEqual(accounts[0], *result));
// 	ASSERT(areAccountsEqual(accounts[1], **(Account**)getElement(queue, 1)));
// 	ASSERT(1 == queue->info.front && 1 == queue->info.rear);
// 	free(accounts);
// }

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
