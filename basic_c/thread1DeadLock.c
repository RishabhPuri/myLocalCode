#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex  = PTHREAD_MUTEX_INITIALIZER;

int resource  = 0;

void *api (void *);

void main ()
{
	pthread_t t1, t2;
	pthread_create (&t1, NULL, api, NULL);
	pthread_create (&t2, NULL, api, NULL);

	pthread_join (t1, NULL);
	pthread_join (t2, NULL);
}

void *api (void *p)
{
	printf ("Thread id %lu \n", pthread_self ());
	pthread_mutex_lock (&mutex);
	if (resource == 1)
		pthread_mutex_unlock (&mutex);	
}

