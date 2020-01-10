#include "params.h"

void *cashier(void *argv)
{
	int id = *(int*)argv;
	while(1)
	{
		// TODO
		if (queue_cashier[id] == 0){
			pthread_mutex_lock(&mutex_cashier[id]);
			printf("Cashier %d leaves the counter since no one waits there. \n", id+1);
			etat_cashier[id] = 1;
			pthread_cond_wait(&cond_cashier[id], &mutex_cashier[id]);
			printf("Cashier %d goes back to work. \n", id+1);
			etat_cashier[id] = 0;
			pthread_cond_signal(&cond_cashier[id]);
			pthread_mutex_unlock(&mutex_cashier[id]);
			//sleep(rand() % TIME_IDLE);
		}

		else {
			//pthread_mutex_lock(&mutex_cashier[id]);
			pthread_cond_signal(&cond_cashier[id]);
			//pthread_mutex_unlock(&mutex_cashier[id]);
		}
		
    }
}
