#if __linux
#include <sys/syscall.h>

#elif defined(_WIN32) || defined(_WIN64)
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#endif

#define N 5
int buffer[5];
int count=0;
pthread_mutex_t mt = PTHREAD_MUTEX_INITIALIZER;

void *produtor(){
	int i=0;
	int in=0;
	
	
	for (i=0; i < 10; i++){
		while (count == N); //do nothing
		//pthread_mutex_lock(&mt); //lock the mutex semaphor
		buffer[in]=i;
		in= (in+1)%N;
		count++;
		//pthread_mutex_unlock(&mt); //unlock the mutex semaphor
	}
	
	
	return NULL;
}

void *consumidor(){
	int i=0;
	int out=0;
	int temp;
  	
	for (i=0; i < 10; i++){
		while (count ==0); //do nothing
        pthread_mutex_lock(&mt); //lock the mutex semaphor
		temp = buffer[out];
		out= (out+1)%N;
		count--;  
		pthread_mutex_unlock(&mt); //unlock the mutex semaphor
  }
  	
  return NULL;
}


int main()
{
   pthread_t p1, p2;

   pthread_create(&p1, NULL, &produtor, NULL);
   pthread_create(&p2, NULL, &consumidor, NULL);


 
   pthread_join(p1, NULL);
   pthread_join(p2, NULL);
   printf("Produtor consumidor finalizado \n");
   return 0;	
}
