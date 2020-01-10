#include "params.h"

void *customer(void *args) 
{
	// customer id
	int id = *(int*)args;
	
	// target shelf id
	int target = rand() % NUM_SHELF;

	// counter with the least customers id
	int pos;

	// number of customers of the least queue
	int min_queue;

	printf("Customer %d needs to go to shelf <%d>. \n", id, target+1);

	// TODO:
	// find the package at shelf
	printf("Customer %d is searching the package in shelf <%d>. \n", id, target+1);
	pthread_mutex_lock(&mutex_shelf[target]);
	while ( cap_shelf[target] == 0 ){	
		pthread_cond_wait(&cond_shelf[target], &mutex_shelf[target]); 
	}
	sleep(rand() % TIME_WORK);
	cap_shelf[target]--;
	printf("Customer %d has found the package. \n", id);
	pthread_mutex_unlock(&mutex_shelf[target]);
	
	// TODO:
	// find cashier with least customer
	pthread_mutex_lock(&mutex_queue);
	pos = 0;
	min_queue = queue_cashier[pos];
	for (int i = 0; i < NUM_CASHIER; i++){
		if ( queue_cashier[i] < min_queue)
			pos = i;
			min_queue = queue_cashier[pos];
	}
	queue_cashier[pos]++;
	pthread_mutex_unlock(&mutex_queue);

	// TODO:
	// check out at cashier counter
	pthread_mutex_lock(&mutex_counter[pos]);
	pthread_mutex_lock(&mutex_cashier[pos]);
	pthread_cond_wait(&cond_cashier[pos], &mutex_cashier[pos]);
	printf("Customer %d is checking out at cashier %d. \n", id, pos+1);
	sleep(rand() % TIME_WORK);
	queue_cashier[pos]--;
	pthread_mutex_unlock(&mutex_cashier[pos]);
	pthread_mutex_unlock(&mutex_counter[pos]);
	
	// customer leaves and thread exit
	printf("Customer %d leaves. \n", id);

	pthread_exit(NULL);
}
