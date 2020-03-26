#include<stdio.h>
#include<pthread.h>
void *Primenumber (void *args)
 {
	int n,d=0;
	printf("All the prime number from 2 to 1000000: \n");
	for (n=2;n<=1000000;n++)
	{		d=0;
		for (int i=1;i<=n;i++)
		{
			if (n% i==0)
				d++;
			if (d>2) break;

		}
		if (d==2)
		printf("%d\n",n);}
}
void *fibo(void *args)
{	int a=1,b=1,c=0;
	printf(" All the number in fibonaci sequence from 2 to 1000000: \n");
	
	while(c<=1000000){
		c=a+b;
		a=b;
		b=c;
		printf("%d \n",c);
	}
}
int main () {
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL,Primenumber, NULL);
	pthread_create(&thread2, NULL,fibo, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
