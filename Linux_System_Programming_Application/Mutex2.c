#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

int iCnt = 0;

void *Increment(void *arg)
{
    // Cretical section start
    pthread_mutex_lock(&lock);
    
    iCnt++;

    printf("%d\n", iCnt);

    // Cretical section end
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&t1, NULL, Increment, NULL);
    pthread_create(&t2, NULL, Increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}


// kernal have one lock we have to write destory

// kartik-ganesh-jare@kartik-ganesh-jare-LOQ-15IRX9:~/Desktop/LSP_Application$ ./Myexe
// 2
// 2

// if you remove print for lock this will be prin

// Arr[4] function point int loop  in thread at home