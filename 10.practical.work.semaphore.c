#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
sem_t s;
void *Primenumber (void *args)
 {
	int n,d=0;
	sem_wait(&s);
	printf("All the prime number from 2 to 1000000: \n");
 	sem_post(&s);
	for (n=2;n<=1000000;n++)
	{		d=0;
		for (int i=1;i<=n;i++)
		{
			if (n% i==0)
			 
				d++;
			if (d>2) break;

		}
		if (d==2)
		sem_wait(&s);
		printf("%d\n",n);
		sem_post(&s);
}
}
void *fibo(void *args)
{	int a=1,b=1,c=0;sem_wait(&s);
	printf(" All the number in fibonaci sequence from 2 to 1000000: \n");
	sem_post(&s);
	while(c<=1000000){
		c=a+b;
		a=b;
		b=c;
		sem_wait(&s);
		printf("%d \n",c);
		sem_post(&s);
	}
}
int main () {	sem_init(&s,0,1);
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL,Primenumber, NULL);
	pthread_create(&thread2, NULL,fibo, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	sem_destroy(&s);
	return 0;
}
