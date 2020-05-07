#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mutex;

void *Prime(void *param){
	for (int i = 2; i <= 1000000; i++){
		pthread_mutex_lock(&mutex);
		int b = 0;
		for (int a = 2; a <= i; a++){
            if(i%a==0) b++;
		}
	if (b == 1){
        printf("%d\n",i);
	}
	pthread_mutex_unlock(&mutex);
}
	return NULL;
}

void *Fibo(void *param){
	int f1,f2,f;
	f1 = 1;
	f2 = 1;
	f = 2;
	while(f <= 1000000){
        pthread_mutex_lock(&mutex);
        printf("%d\n",f);
        f1 = f2;
        f2 = f;
        f = f1 + f2;
        pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main() {
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,Prime,NULL);
	pthread_create(&tid2,NULL,Fibo,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
