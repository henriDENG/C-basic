#include "params.h"

void *producer()
{
	while(1)
	{
		// TODO:
        // check which shelf needs maintenance
        for (int i = 0; i < NUM_SHELF; i++)
        {   
            pthread_mutex_lock(&mutex_shelf[i]);
            if (cap_shelf[i] == 0)
            {   
                printf("The producer is maintaining the shelf <%d> \n", i+1);
                cap_shelf[i] = MAX_CAPACITY;
                printf("The producer has filled the shelf <%d> and decides to relax for a while. \n", i+1);
                pthread_cond_signal(&cond_shelf[i]);
            }
            pthread_mutex_unlock(&mutex_shelf[i]);
        }

		// TODO:
        // let the cashier back to work if needed
        for (int i = 0; i < NUM_CASHIER; i++){
            if ( queue_cashier[i] > 0 && etat_cashier[i] == 1){
                    pthread_mutex_lock(&mutex_cashier[i]);
                    pthread_cond_signal(&cond_cashier[i]);
                    printf("The producer has called cashier %d back to work. \n", i+1);
                    pthread_mutex_unlock(&mutex_cashier[i]);
                }
        }

        sleep(rand() % TIME_IDLE);
	}
}
